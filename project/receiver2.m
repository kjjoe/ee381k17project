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
snr = 15;

%%% Channel %%%
channel_order = 3; % separate than number of taps

channel_L = 4;
channel_tap = zeros(N_rx,N_tx,channel_L);  %h_(receiver)(transmitter)

channel_tap(1,1,:) = [1+1j, -1/2+1j/3, 1/4j     ,1/6].'; %h11
channel_tap(2,1,:) = [1+1j, -1/3+1j/3, 1/5j     ,1/8]';  %h21
channel_tap(1,2,:) = [1   , -1j/2    , 1/4+1j/4 ,1/10].';       %h12
channel_tap(2,2,:) = [1   , 2/5-1j/2 , -1j/5    ,1/15]';        %h22

% channel_tap(1,1,:) = [1   ; 1/2 ];
% channel_tap(2,1,:) = [1+1j; 1j/2];
% channel_tap(1,2,:)= [1j ; -1/2];
% channel_tap(2,2,:)= [1-1j; -1j/2];

channel_snr_dB = snr;
cyclic_prefix = 0;
channel_delay = round(rand*100);
channel_delay = 45;
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

%% mimo channel simulation
%load('frame_to_send.mat');
rx_sig_all = zeros(length(frame_to_send{1})* sys_params_rx.total_frames_to_receive,N_rx);
for r = 1:N_rx
    for t = 1:N_tx
        rx_sig_all(:,r) = rx_sig_all(:,r) + channel_simulator(frame_to_send{t},sys_params_rx,[r,t]);
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


%% Joint Frame and Frequency Sync
signal_out = joint_sync(downsampled,sys_params_rx);

%% Channel estimation
[H,G,h_est] = channel_estimation(signal_out,sys_params_rx);

%% detection ML
symbol_out = detect_symbol(signal_out,G,sys_params_rx);

%% ofdm demodulation
output_bit = detect_bits(symbol_out);

%% Output Calculations
[SER,ratio_ser] = symerr(reshape(symbol_out,[],1),qam_modulated_data);
[BER,ratio_ber] = biterr(output_bit,bits_sent);
fprintf('SNR: %2.2f\nSER: %0.4f\nBER: %0.4f\n',channel_snr_dB,ratio_ser,ratio_ber)

