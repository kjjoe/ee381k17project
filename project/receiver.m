%% mimo receiver simulation
% Kevin
tic
%% add paths
addpath(genpath([pwd '/stu_to_do']));
addpath(genpath([pwd '/Libs']));

%% SENT DATA
rng(1234)
bits_sent = randi([0 1], 960, 1);
qam_modulated_data = qam_mod(bits_sent, 4);

%% Simulation parameters
M = 4;
payload_size_in_ofdm_symbols = 10;
N_tx = 2;
N_rx = 2;
snr = 1000; %%% be sure to comment before running systemcheck.m

%%% Channel %%%
channel_order = 3; % separate than number of taps

channel_L = 4;
channel_tap = zeros(N_rx,N_tx,channel_L);  %h_(receiver)(transmitter)

channel_tap(1,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6].'; %h11
channel_tap(2,1,:) = [1+1j, -1/3+1j/3, 1/5j     ,1/8]';  %h21
channel_tap(1,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/10].';       %h12
channel_tap(2,2,:) = [1   , 2/5-1j/2 , -1j/5    ,1/15]';        %h22

channel_snr_dB = snr;
cyclic_prefix = 0;
channel_delay = round(rand*100);
%channel_delay = 45;

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
                           'channel_delay_samples',channel_delay);  % simulate delay
                       
% System parameters for the receiver       
sys_params_rx = init_sdr_rx(sys_params_base,...
                           'usrp_sample_rate',5e6,... % USRP sampling rate
                           'usrp_gain',10,... %%%%%%%% USRP receiver gain %%%%%%%%
                           'upsampling_factor', 10,... % Upsampling factor
                           'roll_off', 0.5,... % Rolling factor
                           'filt_spans', 6,...  % Filter span of square root raised cosine (SRRC) filters (in symbols)
                           'downsampling_factor', 10, ... % Downsampling factor
                           'channel_order_estimate', 3, ... % Estimated order of channel L, then L+1 taps assumed
                           'correct_cfo', true, ... % Whether correct the cfo
                           'use_moose_frame_sync', false, ... % Whether use moose algorithm
                           'correct_common_gain_phase_error', true, ... % Whether correct common gain and phase error
                           'total_frames_to_receive', 10); % The total number of frames to receive

%% reset parameters
totalloop = 5;
SER = zeros(sys_params_rx.total_frames_to_receive-2,totalloop);
ser_ratio = SER;
BER = SER;
ber_ratio = SER;
snr1 = zeros(totalloop,1);
snr2 = snr1;

%% LOOP


for loop = 1:5

%% mimo channel simulation
%load('frame_to_send.mat');
compile_it = true;
use_codegen = true;
use_wireless_link = true; % true: test with real wireless link. false: test with simulated channel  
if compile_it
    codegen('run_usrp_rx', '-args', {coder.Constant(sys_params_rx)}); %#ok<UNRCH>
end
if use_wireless_link
    if use_codegen 
       clear run_usrp_rx_mex %#ok<UNRCH>
       rx_sig_all = run_usrp_rx_mex(sys_params_rx); 
    else
       rx_sig_all = run_usrp_rx(sys_params_rx);
    end
else %Simulated channel (This is used for simulation instead of real wireless link test)
    %load('frame_to_send.mat');
    rx_sig_all = zeros(length(frame_to_send(:,1))* sys_params_rx.total_frames_to_receive,N_rx);
    for r = 1:N_rx
        for t = 1:N_tx
            rx_sig_all(:,r) = rx_sig_all(:,r) + channel_simulator(frame_to_send(:,t),sys_params_rx,[r,t]);
        end
    end
end
%% Match Filter,Symbol sync, and downsample
% Matched filtering
filtered_data1 = matched_filtering(rx_sig_all(:,1), sys_params_rx);
filtered_data2 = matched_filtering(rx_sig_all(:,2), sys_params_rx);

% Symbol Synchronization
[symbol_synced_data1, symbol_offset1] = symbol_sync_max_energy(filtered_data1, sys_params_rx);
[symbol_synced_data2, symbol_offset2] = symbol_sync_max_energy(filtered_data2, sys_params_rx);
downsampled = [downsample(symbol_synced_data1,sys_params_rx.downsampling_factor), ...
           downsample(symbol_synced_data2,sys_params_rx.downsampling_factor)];      
       
frame_size = sys_params_rx.frame_size;
for frame_id = 1:8
    
    tmp = downsampled((frame_id-1)*frame_size+1:(frame_id+1)*frame_size,:);
    
    %%% Joint Frame and Frequency Sync %%%
    signal_out = joint_sync(tmp,sys_params_rx,2);
    
    %%% Channel estimation %%%        
    [H,G,h_est] = channel_estimation(signal_out,sys_params_rx);

    %%% Detect Symbols %%%
    symbol_out = detect_symbol(signal_out,H,G,sys_params_rx);

    %%% OFDM demodulation %%%
    output_bit = detect_bits(symbol_out);

    %%% Output Calculations %%%
    [s1,s2] = symerr(reshape(symbol_out,[],1),qam_modulated_data);
    [b1,b2] = biterr(output_bit,bits_sent);
    
    SER(frame_id,loop) = s1;
    ser_ratio(frame_id,loop) = s2;
    BER(frame_id,loop) = b1;
    ber_ratio(frame_id,loop) = b2;
end

% snr calculations
var_signal1 = rms(downsampled(:,1))^2;
var_signal2 = rms(downsampled(:,2))^2;
var_noise_measured1 = 2.3044e-07;
var_noise_measured2 = 2.4218e-07; 
snr1(loop) = 10*log10((var_signal1-var_noise_measured1)/var_noise_measured1);
snr2(loop) = 10*log10((var_signal2-var_noise_measured2)/var_noise_measured2); 

fprintf('snr1: %2.2f\nsnr2: %2.2f\nSER: %0.4f\nBER: %0.4f\n',snr1(loop),snr2(loop),mean(ser_ratio(:,loop)),mean(ber_ratio(:,loop)))
toc
end

%%


