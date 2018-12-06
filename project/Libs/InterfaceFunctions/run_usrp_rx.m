    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% run_usrp_rx.m
% function rx_sig_all = run_usrp_rx(sys_params_rx) 
%
% This function allows creating an interface function for a receiver USRP 
% and further fetch the data received
%
% Created August 30, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function rx_sig_all = run_usrp_rx(sys_params_rx) 
    % Create the signal sink for storing the received signal
    rx_sig_temp = complex(zeros(sys_params_rx.usrp_samples_per_frame,1)); % Temporal signal sink
    rx_sig_all = complex(zeros(sys_params_rx.usrp_samples_per_frame* ... 
                              sys_params_rx.total_frames_to_receive/sys_params_rx.rx_buffered_frame,2)); % Signal sink
    persistent rx_radio
    if isempty(rx_radio)
        % Create the interface function to control the Rx USRP 
        rx_radio = comm.SDRuReceiver(...
             'IPAddress',               sys_params_rx.usrp_ip_address, ...
             'Platform',                sys_params_rx.usrp_platform, ...
             'DecimationFactor',        sys_params_rx.usrp_decimation_factor, ...
             'Gain',                    sys_params_rx.usrp_gain, ...
             'CenterFrequency',         sys_params_rx.usrp_center_frequency, ...
             'TransportDataType',       sys_params_rx.usrp_transport_data_type, ...
             'LocalOscillatorOffset',   sys_params_rx.usrp_local_oscillator_offset, ...    
             'ClockSource',             sys_params_rx.usrp_clock_source, ...
             'PPSSource',               sys_params_rx.usrp_pps_source, ...
             'OutputDataType',          sys_params_rx.usrp_output_data_type, ...
             'SamplesPerFrame',         sys_params_rx.usrp_samples_per_frame,...
             'ChannelMapping',          sys_params_rx.usrp_channelmapping); 
        % Initialize the number of frame to be received
        frame_id = 1;
        num_inital_frames_to_ignore = 100;
        frames_to_ignore_id = 1;
        % Receving singal
        disp('********** Start receiving signal **********');        
        while frame_id <= sys_params_rx.total_frames_to_receive/sys_params_rx.rx_buffered_frame
            %Fetch one frame from the USRP device
            len=uint32(0);
            while len <= 0
                [rx_sig_temp, len] = step(rx_radio); 
            end
            % Put the fetched frame into the signal sink
            rx_sig_all(1+(frame_id-1)*sys_params_rx.usrp_samples_per_frame:...
                            frame_id*sys_params_rx.usrp_samples_per_frame,:) = rx_sig_temp;
            % Update the number of next frame to be received
            if frames_to_ignore_id < num_inital_frames_to_ignore
                frames_to_ignore_id = frames_to_ignore_id+1;
            else
                frame_id = frame_id + 1;
            end
        end
        disp('********** Stop receiving signal **********');
        release(rx_radio); 
    end
end