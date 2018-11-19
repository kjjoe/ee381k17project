%% mimo receiver simulation
% Kevin

%% add paths
addpath(genpath([pwd '/stu_to_do']));
addpath(genpath([pwd '/Libs']));

%% Simulation parameters
M = 4;
payload_size_in_ofdm_symbols = 10;
N_tx = 2;
N_rx = 2;

%%% Channel %%%
channel_order = 3; % separate than number of taps

channel_L = 2;
channel_tap = zeros(N_rx,N_tx,channel_L);  %h_(receiver)(transmitter)

% channel_tap(1,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6].'; %h11
% channel_tap(2,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6]';  %h21
% channel_tap(1,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/8].';       %h12
% channel_tap(2,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/8]';        %h22

channel_tap(1,1,:) = [1   ; 1/2 ];
channel_tap(2,1,:) = [1+1j; 1j/2];
channel_tap(1,2,:)= [1j ; -1/2];
channel_tap(2,2,:)= [1-1j; -1j/2];


% bad channel example. why? makes Zero-forcing go to shit. G is bad.
% channel_tap(1,1,:)= 1;
% channel_tap(2,1,:)= 1;
% channel_tap(1,2,:)= 0.5;
% channel_tap(2,2,:)= 0.5;

% also bad channel example. 
% channel_tap(1,1,:)= 1;
% channel_tap(2,1,:)= 1;
% channel_tap(1,2,:)= 1;
% channel_tap(2,2,:)= 1;

channel_snr_dB = 19;
cyclic_prefix = 0;
channel_delay = 0;
%%% basic parameters %%%

N = 64;
L_CP = 16;

sys_params_base = init_sdr('usrp_center_frequency', 2.40e9,...
                           'sys_id',3, ...
                           'M',M, ...
                           'payload_size_in_ofdm_symbols', payload_size_in_ofdm_symbols, ... % Payload size in ofdm symbols per frame 
                           'training_seq_name','Zadoff-Chu',... % Choose your desired training sequence: "Barker", "Zadoff-Chu", "Golay_32", "Golay_64"
                           'training_seq_repetition',2,... % Number of repetition of the trainig sequence
                           'N_ZC',52,... % Length of Zadoff-Chu sequence
                           'M_ZC',3,... % Co-prime parameter with N_ZF for generating Zadoff-Chu sequence
                           'M_ZC2',5,...
                           'L_P', L_CP,... % Length of prefix for training sequence
                           'N_carriers', N,... % Numer of DFT N
                           'L_CP',L_CP,... % Length of cyclic prefix for data
                           'channel_tap', channel_tap,... % Channel impluse response
                           'channel_cfo', 200,... % Carrier frequency offset in Hz
                           'channel_delay', (4*2e-07+6*2e-6),... % Channel dealy in second
                           'channel_snr_dB', channel_snr_dB,...  % Create the common system parameters between transmitter and receiver
                           'N_tx',N_tx, ...  % number of transmitter antennas
                           'N_rx',N_rx, ...    % number of receiver antennas
                           'sim_CF', false, ... % simulate carrier freq offset 
                           'sim_delay',false);  % simulate delay
                       
% System parameters for the receiver       
sys_params_rx = init_sdr_rx(sys_params_base,...
                           'usrp_sample_rate',5e6,... % USRP sampling rate
                           'usrp_gain',35,... % USRP receiver gain
                           'upsampling_factor', 10,... % Upsampling factor
                           'roll_off', 0.5,... % Rolling factor
                           'filt_spans', 6,...  % Filter span of square root raised cosine (SRRC) filters (in symbols)
                           'downsampling_factor', 10, ... % Downsampling factor
                           'channel_order_estimate', 3, ... % Estimated order of channel L, then L+1 taps assumed
                           'correct_cfo', true, ... % Whether correct the cfo
                           'use_moose_frame_sync', false, ... % Whether use moose algorithm
                           'correct_common_gain_phase_error', true, ... % Whether correct common gain and phase error
                           'total_frames_to_receive', 1); % The total number of frames to receive

bps = length(sys_params_rx.data_carriers_index);                       
                       
%% mimo channel simulation
%load('frame_to_send.mat');

rx_sig_all = zeros(length(frame_to_send{1})* sys_params_rx.total_frames_to_receive,N_rx);

for r = 1:N_rx
    for t = 1:N_tx
        rx_sig_all(:,r) = rx_sig_all(:,r) + channel_simulator(frame_to_send{t},sys_params_rx,[r,t]);
    end
end


% downsample
downsampled = downsample(rx_sig_all,sys_params_rx.downsampling_factor);

% Channel estimation
Y = reshape(transpose(fft(downsampled(L_CP+1:L_CP+N,:),N)/sqrt(N)),[],1); % why does sqrt(8) provide the correct scaling?

t = reshape(transpose([sys_params_rx.single_OFDM_training_seq_freq_domain{1}, sys_params_rx.single_OFDM_training_seq_freq_domain{2}]),[],1);

l = transpose(0:channel_order);

T = zeros(64*N_rx,N_tx*N_rx*(max(l)+1)); % pre allocation
index = 0; % could be only active carriers for estimate.
for k = 0:63  % is i possible to vectorize this?
    e = exp(-1i*2*pi*l*k/N);
    t1 = t(2*k+1:2*k+2);

    tt = kron(kron(transpose(e),transpose(t1)),eye(N_rx));
    T((N_rx*index+1:N_rx*index+N_rx),:) = tt;
    index = index+1;
end

h_vec = inv(T'*T)*T'*Y/2; % vectorized 
h_est = reshape(h_vec,N_rx,N_tx,channel_order+1); % back to matrix (R x T x L), for testing

H = zeros(N_rx,N_tx,sys_params_rx.N_carriers); % idk which to pick 
G = H;  % zero forcing requires less computation later
for k = 0:63  % is i possible to vectorize this?
    e = exp(-1i*2*pi*l*k/N);
    tmp = kron(kron(transpose(e),eye(N_tx)),eye(N_rx));
    H(:,:,k+1) = reshape(tmp*h_vec,N_rx,N_tx);
    G(:,:,k+1) = pinv(H(:,:,k+1));
end

%% test H for G
% k = 15;
% disp(H(:,:,k+1)*t(2*k+1:2*k+2))
% disp(Y(2*k+1:2*k+2))
% 
% disp(t(2*k+1:2*k+2))
% disp(G(:,:,k+1)*Y(2*k+1:2*k+2))

%% qam constellation

qam = [1+1j; -1+1j; -1-1j; 1-1j]/sqrt(2);

qam2 = zeros(N_rx,1,M^2);
qam2(1,1,:) = reshape(repmat(transpose(qam),4,1),[],1);
qam2(2,1,:) = repmat(qam,4,1);

%% detection ML
Ydata = downsampled(sys_params_rx.OFDM_preamble_length+1:end,:); % no training
Ydata = reshape(Ydata,[],10); % blocks in time  
Ydata = Ydata(L_CP+1:end,:); % no prefix in time
Ydata = fft(Ydata,N,1)/sqrt(N); % data in freq domain                 
Ydata = reshape(transpose(reshape(Ydata,[],2)),[],1); % remodulate 

% detect 1 block at a time
s_est = zeros(bps*payload_size_in_ofdm_symbols/N_rx,N_rx);
N2 = 2*N;
for block = 0:(payload_size_in_ofdm_symbols/N_rx)-1
    Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
    s_tmp = zeros(bps*2,1);
    magnitude = zeros(M^2,1);
    index = 0;
    for k = (sys_params_rx.data_carriers_index)
        shiftconstellation = [];
        z_tmp = G(:,:,k+1)*Ydatablock(2*k+1:2*k+2);
        [~,ind] = min(reshape(vecnorm(z_tmp-qam2),[],1));
        s_tmp(2*index+1:2*index+2) = qam2(:,:,ind);
        index = index+1;
    end
    s_est(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));
end

%% ofdm demodulation
s_est = reshape(s_est,[],1);

L_out = length(s_est)*2;

output_bit = zeros(L_out,1);
up = output_bit; % upsample 
up(1:2:end) = s_est;

% first bit of the input symbol
output_bit(imag(up) > 0) = 0;
output_bit(imag(up) < 0) = 1;

% second bit of the input symbol
output_bit(circshift(real(up) > 0 , 1)) = 0;
output_bit(circshift(real(up) < 0 , 1)) = 1;

[SER,ratio_ser] = symerr(s_est,qam_modulated_data);
[BER,ratio_ber] = biterr(output_bit,bits_sent);
%fprintf('SNR: %d\nSER: %0.4f\nBER: %0.4f\n',channel_snr_dB,ratio_ser,ratio_ber)

% new line to add just for git hub
% more test lines


