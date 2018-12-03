%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% receiver.m
%
% This is the main function for receiving data
%
% Created Aug. 30, 2018 
% Modified Nov. 1, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%% Initialization and add the required directorys to your path
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Initialize the program by clearing the memory, if the USRP device was
% run previously, the command "clear all" is strongly recommended to
% avoid that MATLAB considers the target USRP is in "Busy" mode. In
% particular, just after this initialization and before running the 
% following codes, you can double check that the yellow LED of the USRP 
% Ethernet port (right side) is not flashing, namely that no data is being 
% received.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%clear all
Lib_path = [pwd '/Libs'];
addpath(genpath(Lib_path));


%% Simulation parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Initialize the system parameters for the receiver
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Create the common system parameters between transmitter and receiver
M = 4;
payload_size_in_ofdm_symbols = 10;
channel_tap = [1+1j, -1/2+1j/3, 1/4j, 1/6].';
channel_tap2 = [1,-1j/2,1/4+1j/4,1/8].';
channel_snr_dB = 30;

sys_params_base = init_sdr('usrp_center_frequency', 2.40e9,...
                           'sys_id',3, ...
                           'M',M, ...
                           'payload_size_in_ofdm_symbols', payload_size_in_ofdm_symbols, ... % Payload size in ofdm symbols per frame 
                           'training_seq_name','Zadoff-Chu',... % Choose your desired training sequence: "Barker", "Zadoff-Chu", "Golay_32", "Golay_64"
                           'training_seq_repetition',2,... % Number of repetition of the trainig sequence
                           'N_ZC',52,... % Length of Zadoff-Chu sequence
                           'M_ZC',3,... % Co-prime parameter with N_ZF for generating Zadoff-Chu sequence
                           'L_P', 16,... % Length of prefix for training sequence
                           'N_carriers',64,... % Numer of DFT N
                           'L_CP',16,... % Length of cyclic prefix for data
                           'channel_tap', channel_tap,... % Channel impluse response
                           'channel_tap2', channel_tap2,... % channel 2
                           'channel_cfo', 200,... % Carrier frequency offset in Hz
                           'channel_delay', (4*2e-07+6*2e-6),... % Channel dealy in second
                           'channel_snr_dB', channel_snr_dB); % Create the common system parameters between transmitter and receiver
                       
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
                           'total_frames_to_receive', 20); % The total number of frames to receive
%% Data reception
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Receive data (in frame) from the USRP device
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
compile_it = false;
use_codegen = false;
use_wireless_link = false; % true: test with real wireless link. false: test with simulated channel  
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
    load('frame_to_send.mat');
    rx_sig_all = channel_simulator(frame_to_send,sys_params_rx);
end


%% Data postprocessing 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Process the received raw data including synchronization and demodulation
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
samples_per_frame = sys_params_rx.usrp_samples_per_frame_tx; % Number of samples per frame
filtered_signal = []; % Vector sink for storing the signal after filtering but before downsampling
downsampled_signal = []; % Vector sink for storing the signal after downsampling
recovered_signal = []; % Vector sink for storing the recoverd signal including preamble
payload = []; % Vector sink for storing the payload without preamble
buffer_last_synced_frame = zeros(samples_per_frame,1); % Buffer of the last synnchronized frame, used in equalization
MSE_one_simulation_vec = [];
NMSE_one_simulation_numerator_vec = [];
NMSE_one_simulation_denomerator_vec = [];
h_est_vec = [];
MSE_CFO_one_simulation_vec = []; % Vector sink for storing the estimation error of channel for simulation mode 
freq_offset_vec = [];
for frame_id = 1:1:sys_params_rx.total_frames_to_receive-2
    % Buffer of two consecutive frames each time for synchronization 
    rx_sig_temp = zeros(samples_per_frame*2,1); 
    rx_sig_temp(:) = rx_sig_all(1+(frame_id-1)*samples_per_frame:(frame_id+1)*samples_per_frame); 
       
    % Matched filtering
    filtered_data = matched_filtering(rx_sig_temp, sys_params_rx);
    filtered_signal = [filtered_data; filtered_signal];
    
    % Symbol Synchronization
    [symbol_synced_data, symbol_offset] = symbol_sync_max_energy(filtered_data, sys_params_rx);
    
    % Downsampling
    downsampled_data = downsample(symbol_synced_data,sys_params_rx.downsampling_factor);
    
    % Buffer long enough samples are so that there is one frame of data but not so long that there are multiple frames
    downsampled_data = downsampled_data(1:end-1); 
    
    % Joint frame and frequency synchronization
    [synced_data, frame_offset, freq_offset] = joint_frame_freq_sync(frame_id, downsampled_data, sys_params_rx);
    freq_offset_vec = [freq_offset_vec freq_offset];
    if ~use_wireless_link
        MSE_CFO_one_simulation_vec = [MSE_CFO_one_simulation_vec (abs(freq_offset-sys_params_rx.channel_cfo)*sys_params_rx.T_symbol)^2]; 
    end
    
    % Channel estimation
    switch sys_params_rx.sys_name
        case {"SC","SC-FDE"}
            h_est = channel_estimation(synced_data, sys_params_rx);
        case "OFDM"
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            h_est = channel_estimation_ofdm(synced_data, sys_params_rx);
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end
    h_est_vec = [h_est_vec h_est];
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--PLESE READ THIS BLOCK FOR UNDERSTANDING HOW CALCULATE MSE--%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Calculate the MSE and NMSE of channel estimation performance for the simualtion mode
    if ~use_wireless_link
        % Correct for global phase factor
        l_temp = max(length(h_est),length(sys_params_rx.channel_tap));
        h_est_temp = zeros(l_temp,1);
        channel_tap_temp = zeros(l_temp,1);
        h_est_temp(1:length(h_est)) = h_est;
        channel_tap_temp(1:length(sys_params_rx.channel_tap)) = sys_params_rx.channel_tap;
        phase_offset = exp( 1i* angle( (h_est_temp'*channel_tap_temp)/(channel_tap_temp'*channel_tap_temp) ) );
        phase_offset = 1;
        h_est_correct_temp = h_est_temp*phase_offset;
        MSE_one_frame = norm(channel_tap_temp-h_est_correct_temp)^2;
        MSE_one_simulation_vec = [MSE_one_simulation_vec MSE_one_frame];
        NMSE_one_frame_numerator = norm(channel_tap_temp-h_est_correct_temp)^2;
        NMSE_one_simulation_numerator_vec = [NMSE_one_simulation_numerator_vec NMSE_one_frame_numerator];
        NMSE_one_frame_denomerator = norm(channel_tap_temp)^2;
        NMSE_one_simulation_denomerator_vec = [NMSE_one_simulation_denomerator_vec NMSE_one_frame_denomerator];
    end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--PLESE READ THIS BLOCK FOR UNDERSTANDING HOW CALCULATE MSE--%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    % Choose the system that is runed to select the corresponding equalizer
    switch sys_params_rx.sys_name
        case "SC"
            [equalized_data, fnd, fnd_error] = equalization(synced_data, buffer_last_synced_frame, sys_params_rx);
            equalized_data = equalized_data(sys_params_rx.sc_preamble_length+1:end);
        case {"SC-FDE","OFDM"}
            equalized_data = equalization_FDE(synced_data, h_est, sys_params_rx);
            if sys_params_rx.sys_name == "OFDM" && sys_params_rx.correct_common_gain_phase_error
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                equalized_data = common_gain_phase_error_compensation(equalized_data, sys_params_rx);
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            end
    end
     
    % Fetech payload data
    switch sys_params_rx.sys_name
        case {"SC","SC-FDE"}
            sub_payload = equalized_data;
        case "OFDM"
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            sub_payload = OFDM_demod(equalized_data, sys_params_rx);
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end
          
    % Buffer the synchronized data for the equalization of next frame
    % This buffered data is used for "SC" mode when function "equalization"
    % is called
    if frame_id == 1 %if mod(FrameID,SimParamsRx.RxBufferedFrame) == 1
        buffer_last_synced_frame(:) = 0;
    else
        buffer_last_synced_frame = synced_data;     
    end
    
    % Store the synchronized data
    downsampled_signal = [downsampled_signal; downsampled_data];
    recovered_signal = [recovered_signal; equalized_data];
    payload = [payload; sub_payload];
end

% Symbol detection and demodulation
detected_symbols = detect_symbol(payload, sys_params_rx.M);
demod_data = qam_demod(detected_symbols, sys_params_rx.M);

% Channel estimation error
if ~use_wireless_link
    MSE_one_simulation = mean(MSE_one_simulation_vec);
    NMSE_one_simulation_numerator = mean(NMSE_one_simulation_numerator_vec);
    NMSE_one_simulation_denumerator = mean(NMSE_one_simulation_denomerator_vec);
    NMSE_one_simulation = NMSE_one_simulation_numerator/NMSE_one_simulation_denumerator;
    MSE_CFO_one_simulation = mean(MSE_CFO_one_simulation_vec);
end

% BER/SER/FER calculation
load('bits_sent.mat');
bit_received_All = reshape(demod_data,[length(bits_sent),length(demod_data)/length(bits_sent)]);
[number_b,ratio_ber] = biterr(bit_received_All,bits_sent); 
BER = mean(ratio_ber);
load('qam_modulated_data.mat');
sym_received_All = reshape(detected_symbols,[length(qam_modulated_data),length(detected_symbols)/length(qam_modulated_data)]);
[number_s,ratio_ser] = symerr(sym_received_All,qam_modulated_data); 
SER = mean(ratio_ser);
FER = length(find(ratio_ser ~= 0))/length(ratio_ser);

% SNR estimation
var_noise = rms(downsampled_signal)^2;
var_signal = rms(downsampled_signal)^2;
var_noise_measured = 1.8069e-07; % You need to change this to what you estimate
snr_estimated = 10*log10((var_signal-var_noise_measured)/var_noise_measured);

SER = SER;
freq_offset = mean(freq_offset_vec);
freq_offset_epsilon = freq_offset*sys_params_rx.T_symbol;
