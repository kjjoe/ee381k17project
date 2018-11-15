%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% init_sdr_rx.m
%
% sys_params_rx = init_sdr_rx(sys_params_base, varargin) generates the 
% default system parameters for a receiver based on the input basic
% system parameter sys_params_base (struct array). It outputs a struct
% array containing the relevant information of the receiver.
% 
% Passing customized system parameters is available using the following
% format: sys_params_base, 'property_name_1", value_1, "property_name_2", value_2, ...
% 
% --------------------List of tunable system parameters--------------------
% upsampling_factor: upsampling factor of the square root raised cosine
%                    (SRRC) filter for matched filtering
% roll_off: rolling factor of the SRRC filter for matched filtering
% filt_spans: number of filter spans in symbols of the SRRC filter for matched filtering
% downsampling_factor: downsampling factor
% usrp_ip_address: ip address of the receiver USRP device
% usrp_sample_rate: receiver sampling rate
% usrp_gain: receiving gain of the USRP device in dB
% usrp_local_oscillator_offset: local oscillator offset of the usrp
% usrp_clock_source: source of frequency reference of the usrp
% usrp_pps_source : source of timing reference of the usrp
% rx_buffered_frame: number of frames fetched from the USRP device at each call
% total_frames_to_receive: total number of frames to receive, 
% which should be a multiple of rx_buffered_frame
% P: number of samples used to estimate the maximum output energy in symbol synchronization, 
% it should be a multiple of the oversampling factor, i.e. upsampling factor
% delta: parameter used in symbol synchronization, a multiple of T_sample/upsammpling_factor, typical value 1
% use_moose_frame_sync: boolean variable to indicate whether use Moose algorithm in frame synchronization
% correct_cfo: boolean variable to indicate whether estimate carrier frequency offset
% channel_order_estimate: estimated channel order
% equalizer_delay: equalizer delay
% equalizer_order: equalizer order Lf, which should be smaller than the 
%                  length of the training sequence and the rule of thumb is to take Lf 
%                  at least 4L, where L is the channel order
% --------------------List of tunable system parameters--------------------
%
%
% Created September 12, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function sys_params_rx = init_sdr_rx(sys_params_base, varargin)
    %% Inherit basic parameters
    sys_params_rx = sys_params_base;
        
    %% Tunable receiver parameters 
    % Matched filtering parameters
    sys_params_rx.upsampling_factor = 4; % Upsampling factor
    sys_params_rx.roll_off = 0.5; % Rolling factor
    sys_params_rx.filt_spans = 10; % Filter span of square root raised cosine (SRRC) filters (in symbols)
    sys_params_rx.downsampling_factor = 4; % Downsampling factor

    % Receiver USRP hardware parameters
    sys_params_rx.usrp_ip_address = '192.168.10.3'; % USRP IP address 
    sys_params_rx.usrp_sample_rate = 5e6; % USRP baseband sample rate   
    sys_params_rx.usrp_gain = 10; % Receiving gain
    sys_params_rx.rx_buffered_frame = 10; % Number of frames fetched from the USRP device at each call
    sys_params_rx.total_frames_to_receive = sys_params_rx.rx_buffered_frame * 5; % The total number of frames to receive, which should be a multiple of rx_buffered_frame
    sys_params_rx.usrp_local_oscillator_offset = 0; % Local oscillator offset
    sys_params_rx.usrp_clock_source = 'Internal';  % Source of frequency reference
    sys_params_rx.usrp_pps_source = 'Internal';    % Source of timing reference
    
    % Post processing parameters
        % Symbol synchronization parameters
    sys_params_rx.delta = 1; % parameter used in symbol synchronization, it should be a multiple of T_sample/upsammpling_factor, typical value is 1
        % Frame synchronization
    sys_params_rx.use_moose_frame_sync = true; % boolean variable to indicate whether use Moose algorithm in frame synchronization
    sys_params_rx.correct_cfo = true; % To correct carrier frequency offset
        % Frequency synchronization and channel estimation parameters
    sys_params_rx.direct_equalization = false;    
    sys_params_rx.channel_order_estimate = 3; % Estimated channel order (length of channel plus 1), which should be smaller than the length of the training sequence
    sys_params_rx.equalizer_delay = 3; % Equalizer delay
    sys_params_rx.equalizer_order = 8; % Equalizer order Lf, which should be smaller than the length of the training sequence and the rule of thumb is to take Lf at least 4L, where L is the channel order
    sys_params_rx.correct_common_gain_phase_error = true; % Whether correct the common gain and phase error
        
    %% Customize the parameters according to input arguments (varargin)
    n_var_in = length(varargin);
    if mod(n_var_in,2) ~= 0
        error('Number of input arguments excluding "sys_params_base" should be even.')
        % Format for varargin: sys_params_base, 'property_name_1", value_1, "property_name_2", value_2, ...
    else
        for k = 1 : 2 : n_var_in
            field_name = varargin{k};
            new_value = varargin{k+1};
            sys_params_rx.(field_name) = new_value;
        end
    end
    
    %% Dependent parameters (not tunable)
    sys_params_rx.P = sys_params_rx.upsampling_factor * sys_params_rx.payload_size_in_symbols; % Number of samples that are used to estimate the maximum output energy in symbol synchronization, it should be a multiple of the oversampling factor, i.e. upsampling factor
    sys_params_rx.usrp_decimation_factor = sys_params_rx.usrp_master_clock_rate / sys_params_rx.usrp_sample_rate; % Receiving decimation factor       
    sys_params_rx.usrp_samples_per_frame_tx = sys_params_rx.upsampling_factor * sys_params_rx.frame_size; % Number of samples of in each frame transmitted by each call of the tramsmitter USRP
    sys_params_rx.usrp_samples_per_frame = sys_params_rx.rx_buffered_frame * sys_params_rx.usrp_samples_per_frame_tx; % Number of total samples of buffered frames at one call to the Rx USRP device.     
    sys_params_rx.T_sample = 1/sys_params_rx.usrp_sample_rate;  % Sample duration
    sys_params_rx.T_symbol = sys_params_rx.upsampling_factor * sys_params_rx.T_sample; % Symbol duration
    sys_params_rx.frame_time = sys_params_rx.usrp_samples_per_frame * sys_params_rx.T_sample; % Frame duration
    sys_params_rx.reception_time = sys_params_rx.total_frames_to_receive * sys_params_rx.frame_time; % Receiving duration in seconds
    
    %% Order the fields of structure in ASCII dictionary order
    sys_params_rx = orderfields(sys_params_rx);
end

