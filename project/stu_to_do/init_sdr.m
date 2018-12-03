%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% init_sdr.m
%
% sys_params_base = init_sdr(varargin) generates the default system
% parameters for both transmitter and receiver. It outputs a struct array
% containing the relevant information. 
% 
% Passing customized system parameters is available using the following
% format: 'property_name_1", value_1, "property_name_2", value_2, ...
% 
% --------------------List of tunable system parameters--------------------
% Sys_ID: ID of the system with options 1, 2 and 3: 1 is "SC", 2 is "SC-FDE" and 3 represents "OFDM"
% usrp_center_frequency: center frequency of the system in Hz
% training_seq_name: training sequence used "BARKER_CODE", "ZC", "GOLAY_32", "GOLAY_64"
% M: modulation order of QAM
% usrp_transport_data_type: transport data type of the USRP with option "int16" and "int8"
% channel_tap: simulated channel taps
% channel_delay: simulated channel delays in seconds
% channel_cfo: simulated carrier frequency offset of the channel in Hz
% channel_snr_dB: simulated signal to noise ratio (SNR) in dB 
% N_ZF: Length of Zadoff-Chu sequence
% M_ZC: Co-prime parameter with N_ZF for generating Zadoff-Chu sequence
% L_P: Length of prefix for training sequence
% N_carriers: Number of total subcarriers for SC-FDE and OFDM (N-DFT)
% N_data_carriers:  Number of subcarriers used for data transmission in OFDM system
% data_carriers_index: Index of sub-carriers used in OFDM system for data transmission (begin from 0)
% null_tone: Index for DC carrier
% pilot_carriers_index: Index of subcarriers for pilots.
% sys_params_base.pilot: pilot sysmbol, modulated by bpsk
% sys_params_base.inactive_carriers_index: Index of inactive subcarriers.
% L_CP: Length of cyclic prefix for SC-FDE and OFDM, which should be larger than the order of channel
% payload_size_in_symbols is the payload size in symbols per frame 
% payload_size_in_ofdm_symbols is the payload size in ofdm symbols per frame 
%    
% --------------------List of tunable system parameters--------------------
%
%
% Created Aug. 20, 2018 
% Modified Oct. 25, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function sys_params_base = init_sdr(varargin)
    %% Tunable system parameters
    sys_params_base.sys_id = 1; % ID of the system
    sys_params_base.usrp_center_frequency = 2.40e9; % Center frequency in Hz
    sys_params_base.training_seq_name = "Golay_32"; % Name of training sequence
    sys_params_base.M = 4; % QAM modulation order
    sys_params_base.usrp_transport_data_type = 'int16'; % Use 'int8' can alleviate transmission burden of the Ethernet Cable     
    sys_params_base.channel_tap = [0.7*exp(1j*pi/3) 0.35*exp(1j*pi/4) 0.1*exp(1j*pi/5)]; % Channel taps
    sys_params_base.channel_tap2 = 1; % Channel taps
    sys_params_base.channel_delay = 2e-6; % Channel delay in second
    sys_params_base.channel_cfo = 201; % Carrier frequency offset of the channel in Hz
    sys_params_base.channel_snr_dB = 200; % Signal to noise ratio in dB 
    sys_params_base.training_seq_repetition = 1; % Repetition of training sequence
    sys_params_base.N_ZF = 32; % Length of Zadoff-Chu sequence
    sys_params_base.M_ZC = 3; % Co-prime parameter with N_ZF for generating Zadoff-Chu sequence
    sys_params_base.L_P = 0; % Length of prefix for training sequence
    sys_params_base.N_carriers = 64; % Number of total subcarriers for SC-FDE and OFDM (N-DFT)
    sys_params_base.N_data_carriers = 48; % Number of subcarriers used for data transmission in OFDM system
    sys_params_base.N_active_carriers = 52; % Number of active subcarriers in OFDM system
    sys_params_base.active_carriers_index = [[1:26] [-26:-1]+64]; % Index of active subcarriers in OFDM system
    sys_params_base.data_carriers_index = [[1:6 8:20 22: 26] [-26:-22 -20:-8 -6:-1]+64]; % Index of subcarriers used in OFDM system for data transmission
    sys_params_base.null_tone = [0]; % Index for DC carrier
    sys_params_base.pilot_carriers_index = [7,21,-21+64,-7+64]; % Index of subcarriers used for pilot transmission
    sys_params_base.pilot = [1 1 1 1]'; % pilot sysmbol is bpsk modulated
    sys_params_base.inactive_carriers_index = [27:37]; % Index of inactive subcarriers.
    sys_params_base.L_CP = 16;  % Length of cyclic prefix for SC-FDE and OFDM, which should be larger than the order of channel
    sys_params_base.payload_size_in_symbols = 500; % Payload size in symbols per frame 
    sys_params_base.payload_size_in_ofdm_symbols = 10; % Payload size in ofdm symbols per frame 
    sys_params_base.N_tx = 1; % Number of transmitter antennas 
    sys_params_base.N_rx = 1; % Number of receiver antennas
    
    %% Fixed parameters (not tunable)
    sys_params_base.usrp_platform = 'N200/N210/USRP2'; % Model name of the USRP device
    sys_params_base.usrp_master_clock_rate = 100e6; % Master clock rate in Hz
    sys_params_base.usrp_output_data_type = 'double'; % Data type of output
    BARKER_CODE = [-1 -1 -1 +1 +1 +1 -1 +1 +1 -1 +1]'; % Barker code
    GOLAY_32 = [1,1,1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,....
               1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1]'; % Golay sequence of 32 symbols
    GOLAY_64 = [-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,...
               -1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,1,1,...
               1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,...
               -1,1,1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1]'; % Golay sequence of 64 symbols
           
           
    %% Customize the parameters according to input arguments (varargin)
    n_var_in = length(varargin);
    if mod(n_var_in,2) ~= 0
        error('Number of input arguments should be even.')
        % Format for varargin: 'property_name_1", value_1, "property_name_2", value_2, ...
    else
        for k = 1 : 2 : n_var_in
            field_name = varargin{k};
            new_value = varargin{k+1};
            sys_params_base.(field_name) = new_value;
        end
    end
    
    %% Dependent parameters (not tunable)
    % choose system type/name
    switch sys_params_base.sys_id
        case 1
            sys_params_base.sys_name = "SC"; % Single carrier system
        case 2
            sys_params_base.sys_name = "SC-FDE"; % Single carrier system with frequency-domain equalization
        case 3
            sys_params_base.sys_name = "OFDM"; % OFDM system
    end
    
    % Preamble parameters
    switch sys_params_base.training_seq_name % Choose your desired training sequence
        case "Barker"
            sys_params_base.training_seq = BARKER_CODE;
        case "Zadoff-Chu"
            ZC = exp(-(1i*sys_params_base.M_ZC*pi*[0:sys_params_base.N_ZC-1]'.^2)/sys_params_base.N_ZC);% Generate root Zadoff-Chu sequence of complex symbols
            sys_params_base.training_seq = ZC;
        case "Golay_32"
            sys_params_base.training_seq = GOLAY_32;
        case "Golay_64"
            sys_params_base.training_seq = GOLAY_64;
    end
    
    % Generate SC-FDE preamable
    if sys_params_base.sys_name == "SC-FDE"
        prefix = sys_params_base.training_seq(end-sys_params_base.L_P+1:end); % Cyclic prefix of training sequence
        prefixed_training_sequence = [prefix;sys_params_base.training_seq]; % Cyclic prefixed training sequence
        sys_params_base.training_seq = prefixed_training_sequence; 
    end
    
    sys_params_base.training_seq_length = length(sys_params_base.training_seq); % Number of symbols in training sequence
    sys_params_base.sc_preamble = repmat(sys_params_base.training_seq,sys_params_base.training_seq_repetition,1); % The column of single carrier preamble
    sys_params_base.sc_preamble_length = length(sys_params_base.sc_preamble); % Number of symbols in single carrier preamble 
      
    % Generate OFDM preamble
    if sys_params_base.sys_name == "OFDM"
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        sys_params_base = ofdm_preamble_generator(sys_params_base);
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end
        
    % Modulation parameters
    sys_params_base.BPS = log2(sys_params_base.M); % Bits per symbols
    
    % Frame size and payload size parameters
        %-----------IMPORTANT NOTICE: If anything about the frame structure was changed-----------%
        %-----------please check that sys_params_base.frame_size is consistent to the changement-----------%
    switch sys_params_base.sys_name 
        case "SC"
            sys_params_base.frame_size = sys_params_base.sc_preamble_length + ...
                                         sys_params_base.payload_size_in_symbols; % The number of modulated symbols per frame
        case "SC-FDE"
            sys_params_base.payload_size_in_symbols = sys_params_base.N_carriers*10; % Payload size in symbols per frame
            sys_params_base.frame_size = sys_params_base.sc_preamble_length + ...
                                         sys_params_base.payload_size_in_symbols + ...
                                         sys_params_base.L_CP*(sys_params_base.payload_size_in_symbols/sys_params_base.N_carriers); % The number of modulated symbols per frame
        case "OFDM"
            sys_params_base.payload_size_in_symbols = sys_params_base.N_data_carriers*sys_params_base.payload_size_in_ofdm_symbols; % Payload size in symbols per frame
            sys_params_base.frame_size = sys_params_base.OFDM_preamble_length + ...
                                         sys_params_base.L_CP * sys_params_base.payload_size_in_ofdm_symbols/2 + ...
                                         sys_params_base.N_carriers * sys_params_base.payload_size_in_ofdm_symbols/2; % The number of modulated symbols per frame
            % per antenna, so divide payload size by 2
    end
    sys_params_base.payload_size_in_bits = sys_params_base.payload_size_in_symbols*sys_params_base.BPS; % Payload size in bits per frame
        
    %% Order the fields of structure in ASCII dictionary order
    sys_params_base = orderfields(sys_params_base);
end


