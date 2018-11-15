% transmitter mimo
% kevin


%% Simulation parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Initialize the system parameters for the transmitter
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Create the common system parameters between transmitter and receiver
M = 4;
payload_size_in_ofdm_symbols = 10;
sys_params_base = init_sdr('usrp_center_frequency', 2.40e9, ...
                           'sys_id',3, ...
                           'M',M, ...
                           'payload_size_in_ofdm_symbols', payload_size_in_ofdm_symbols, ... % Payload size in ofdm symbols per frame 
                           'training_seq_name','Zadoff-Chu',... % Choose your desired training sequence: "Barker", "Zadoff-Chu", "Golay_32", "Golay_64"
                           'training_seq_repetition',2,... % Number of repetition of the trainig sequence
                           'N_ZC',52,... % Length of Zadoff-Chu sequence
                           'M_ZC',3,... % Co-prime parameter with N_ZF for generating Zadoff-Chu sequence
                           'L_P', 16,... % Length of prefix for training sequence
                           'N_carriers',64,... % Numer of DFT N
                           'L_CP',16); % Length of cyclic prefix for data
                       
% System parameters for the transmitter                       
sys_params_tx = init_sdr_tx(sys_params_base,...
                           'usrp_sample_rate',5e6,... % USRP sampling rate
                           'usrp_gain',15,... % USRP transmitter gain
                           'upsampling_factor', 10,... % Upsampling factor
                           'roll_off', 0.5,... % Rolling factor
                           'filt_spans', 6,...  % Filter span of square root raised cosine (SRRC) filters (in symbols)
                           'downsampling_factor', 10); % Downsampling factor

%% Data generation 
% Step 1: generate random bit for transmission
bits_sent = randi([0 1], sys_params_tx.payload_size_in_bits, 1);

save bits_sent bits_sent; % save the transmitted bits for calculating the biterr

% Step 2: modulate the bit stream with QAM
qam_modulated_data = qam_mod(bits_sent, sys_params_tx.M);
save qam_modulated_data qam_modulated_data; % save the transmitted bits for calculating the symerr

% Step 3: genrate the frame (before pulse shaping) for specific system: SC, SC-FDE or OFDM
framed_data = frame_generator(qam_modulated_data, sys_params_tx);

% Step 4: pulse shaping
frame_to_send = pulse_shaping(framed_data, sys_params_tx);

% save the transmitted symbols for test with simulated channel 
type_frame_to_send = coder.newtype('double',[length(frame_to_send) 1],'complex',true);
save frame_to_send frame_to_send; 
