%% mimo receiver simulation
% Kevin

%% add paths
addpath(genpath([pwd '/stu_to_do']));
addpath(genpath([pwd '/Libs']));

%ser = zeros(40,1);
%ber = ser;
%etotal = ser;
%for snr = 1:1

%snr = 15;
%% Simulation parameters
M = 4;
payload_size_in_ofdm_symbols = 10;
N_tx = 2;
N_rx = 2;

%%% Channel %%%
channel_order = 3; % separate than number of taps

channel_L = 4;
channel_tap = zeros(N_rx,N_tx,channel_L);  %h_(receiver)(transmitter)

channel_tap(1,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6].'; %h11
channel_tap(2,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6]';  %h21
channel_tap(1,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/8].';       %h12
channel_tap(2,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/8]';        %h22

% channel_tap(1,1,:) = [1   ; 1/2 ];
% channel_tap(2,1,:) = [1+1j; 1j/2];
% channel_tap(1,2,:)= [1j ; -1/2];
% channel_tap(2,2,:)= [1-1j; -1j/2];


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

channel_snr_dB = snr;
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
                           'sim_CF', true, ... % simulate carrier freq offset 
                           'sim_delay',true, ...
                           'channel_delay_samples',15);  % simulate delay
                       
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
                           'total_frames_to_receive', 2); % The total number of frames to receive

bps = length(sys_params_rx.data_carriers_index);                       
cfo_start = sys_params_rx.cfo_start;
data_start = sys_params_rx.data_start;
Lc = 16;
frame_size = sys_params_rx.frame_size;
%% mimo channel simulation
%load('frame_to_send.mat');

rx_sig_all = zeros(length(frame_to_send{1})* sys_params_rx.total_frames_to_receive,N_rx);

for r = 1:N_rx
    for t = 1:N_tx
        rx_sig_all(:,r) = rx_sig_all(:,r) + channel_simulator(frame_to_send{t},sys_params_rx,[r,t]);
    end
end


%% Symbol sync and downsample
  % Matched filtering
    rx_sig_temp1 = rx_sig_all(:,1);
    rx_sig_temp2 = rx_sig_all(:,2);
    filtered_data1 = matched_filtering(rx_sig_temp1, sys_params_rx);
    filtered_data2 = matched_filtering(rx_sig_temp2, sys_params_rx);
    
    % Symbol Synchronization
    [symbol_synced_data1, symbol_offset1] = symbol_sync_max_energy(filtered_data1, sys_params_rx);
    [symbol_synced_data2, symbol_offset2] = symbol_sync_max_energy(filtered_data2, sys_params_rx);
downsampled = [downsample(symbol_synced_data1,sys_params_rx.downsampling_factor), ...
               downsample(symbol_synced_data2,sys_params_rx.downsampling_factor)];


%% frame sync

if sys_params_rx.sim_delay
    % stage 1
    m = 1:(2*M+1);
    n = (1:Lc)'; % but usually 0 to Lc-1
    R = zeros(frame_size,1);
    frame_sync = downsampled(cfo_start+Lc:end,1); 
    for delta = 0:frame_size
        numer = sum(sum(abs(conj(frame_sync(n + (m-1)*Lc + delta)).* frame_sync(n + m*Lc + delta))));
        denom = sum(sum(abs(frame_sync(n + (m-1)*Lc + delta)).^2));
        R(delta+1) = numer/denom;
    end

    [~,offset1] = max(R);
    % stage 2
    freq_synced_input_data = downsampled(cfo_start+160:end,2); 
    n = 1:(Lc+N);
    R = zeros(frame_size,1);
    for d = 0:frame_size
        num = abs(sum(freq_synced_input_data(n+N+d).*conj(freq_synced_input_data(n+d))))^2;
        den1 = sqrt(sum(abs(freq_synced_input_data(n+N+d)).^2));
        den2 = sqrt(sum(abs(freq_synced_input_data(n+d)).^2));
        R(d+1) = num/(den1*den2);
    end


    [~,offset2] = max(R);
    
   % offset2 = 3;
    frame_offset = offset2 - 1;
    
    frame_synced_data = downsampled(offset2:offset2+sys_params_rx.frame_size-1,:);
else
    frame_synced_data = downsampled;
end

%% cfo estimation

if sys_params_rx.sim_CF
%     y_cfo = downsampled((cfo_start+L_CP):(cfo_start+L_CP+N-1),:);
%     n = (0:(N/2 - 1))';
%     e_frac = angle(sum(sum(conj(y_cfo(n+1+N/2,:)).*  y_cfo(n+1,:))))/pi/N;
%     %e_frac = -4e-5*length(downsampled)/64;
%     n1 = (0:length(downsampled)-1)';
%     cfo_done = downsampled.*exp(1j*2*pi*e_frac*n1);
% %    
% figure(1)
%     hold on
% % scatter(real(y_cfo(1:32,1)),imag(y_cfo(1:32,1)))
% % scatter(real(y_cfo(33:64,1)),imag(y_cfo(33:64,1)))
% for p = 1:32
%     tmp = [y_cfo(p,1); y_cfo(p+32,1)];
%     plot(real(tmp),imag(tmp),'o-');
% end
    
    input_data_r1 = frame_synced_data(cfo_start:data_start-1,1);
    input_data_r2 = frame_synced_data(cfo_start:data_start-1,2);
    frame_id = 1;
    
    m = 1:(2*M+1);
    n = (1:Lc)'; % but usually 0 to Lc-1    
    epsilon1 = angle(sum(sum(conj(input_data_r1(n + (m-1)*Lc)).* input_data_r1(n + m*Lc))))/(2*pi*Lc);
    epsilon2 = angle(sum(sum(conj(input_data_r2(n + (m-1)*Lc)).* input_data_r2(n + m*Lc))))/(2*pi*Lc);
    % Phase offset in comparison with the first symbol of the first frame
%     phase_offset = exp(1j*2*pi*epsilon*(sys_params_rx.frame_size-1)*(frame_id-1)); % phase offset with respect to the first symbol of the first frame
%     freq_synced_data = input_data .* conj(phase_offset); % Compensate the phase offset
    freq_offset1 = epsilon1/2e-6;
    freq_offset2 = epsilon2/2e-6;
    % Compensate the CFO
    % Code here
    n1 = (0:length(downsampled)-1)';
    %efrac = (epsilon1 + epsilon2)/2;
    %cfo_done = downsampled.*exp(-1j*2*pi*efrac*n1);

    input1 = input_data_r1(177:end);
    input2 = input_data_r2(177:end);

    n = 1:N;
    ep1 = (1/(2*pi*N))*angle(sum(conj(input1(n)).*input1(n+N)));
    ep2 = (1/(2*pi*N))*angle(sum(conj(input2(n)).*input2(n+N)));
    final_e = mean([epsilon1, epsilon2,ep1,ep2]);
    cfo_done = downsampled.*exp(-1j*2*pi*final_e*n1);
else
    cfo_done = frame_synced_data;
end


%% Channel estimation
tmp = cfo_done(L_CP+1:L_CP+N,:);
%tmp = tmp.*exp(1j*2*pi*e_frac*n1);

Y = reshape(transpose(fft(tmp,N)/sqrt(N)),[],1); % why does sqrt(8) provide the correct scaling?

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
% need to change data indices 
Ydata = cfo_done(data_start:sys_params_rx.frame_size,:); % no training
Ydata = reshape(Ydata,[],10); % blocks in time  
Ydata = Ydata(L_CP+1:end,:); % no prefix in time
Ydata = fft(Ydata,N,1)/sqrt(N); % data in freq domain                 
Ydata = reshape(transpose(reshape(Ydata,[],2)),[],1); % remodulate 

% detect 1 block at a time
s_est = zeros(bps*payload_size_in_ofdm_symbols/N_rx,N_rx);
N2 = 2*N;
forplots = []; % for debugging
for block = 0:(payload_size_in_ofdm_symbols/N_rx)-1
    Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
    s_tmp = zeros(bps*2,1);
    magnitude = zeros(M^2,1);
    index = 0;
    for k = (sys_params_rx.data_carriers_index)
        z_tmp = G(:,:,k+1)*Ydatablock(2*k+1:2*k+2);
        [~,ind] = min(reshape(vecnorm(z_tmp-qam2),[],1));
        s_tmp(2*index+1:2*index+2) = qam2(:,:,ind);
        index = index+1;
        forplots = [forplots; z_tmp];
    end
    s_est(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));
end

% no zero forcing if you want
% s_est2 = zeros(bps*payload_size_in_ofdm_symbols/N_rx,N_rx);
% N2 = 2*N;
% forplots2 = [];
% forplots3 = [];
% 
% qam3 = cell(N,1);
% for k = (sys_params_rx.data_carriers_index)
%     for index = 1:16
%         qam3{k}(:,:,index) = H(:,:,k)*qam2(:,:,index);
%     end
% end
% 
% for block = 0:(payload_size_in_ofdm_symbols/N_rx)-1
%     Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
%     s_tmp = zeros(bps*2,1);
%     magnitude = zeros(M^2,1);
%     index = 0;
%     for k = (sys_params_rx.data_carriers_index)
%         [~,ind] = min(reshape(vecnorm(Ydatablock(2*k+1:2*k+2)-qam3{k}),[],1));
%         s_tmp(2*index+1:2*index+2) = qam2(:,:,ind);
%         index = index+1;
%         forplots2 = [forplots2; qam3{k}(:,:,ind)];
%         forplots3 = [forplots3; Ydatablock(2*k+1:2*k+2)];
%     end
%     s_est2(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));
% end
% s = reshape(s_est2,[],1);


%% ofdm demodulation
detect = s_est;

detect = reshape(detect,[],1);

L_out = length(detect)*2;

output_bit = zeros(L_out,1);
up = output_bit; % upsample 
up(1:2:end) = detect;

% first bit of the input symbol
output_bit(imag(up) > 0) = 0;
output_bit(imag(up) < 0) = 1;

% second bit of the input symbol
output_bit(circshift(real(up) > 0 , 1)) = 0;
output_bit(circshift(real(up) < 0 , 1)) = 1;

[SER,ratio_ser] = symerr(detect,qam_modulated_data);
[BER,ratio_ber] = biterr(output_bit,bits_sent);
fprintf('SNR: %2.2f\nSER: %0.4f\nBER: %0.4f\n',channel_snr_dB,ratio_ser,ratio_ber)
%ser(snr) = ratio_ser;
%ber(snr) = ratio_ber;
%etotal(snr) = e_frac;
%end
% new line to add just for git hub
% more test lines


