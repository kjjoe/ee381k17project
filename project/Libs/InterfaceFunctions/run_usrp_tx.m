%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% run_usrp_tx.m
% function run_usrp_tx(sys_params_tx,frame_to_send) 
%
% This function allows creating an interface function for a transmitter
% USRP and further feed the data to it for transmission
%
% Created August 30, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function run_usrp_tx(sys_params_tx,frame_to_send) 
    persistent tx_radio
    if isempty(tx_radio)
        % Create the interface function to control the Tx USRP 
        tx_radio = comm.SDRuTransmitter(...
         'IPAddress',               sys_params_tx.usrp_ip_address, ...
         'Platform',                sys_params_tx.usrp_platform, ...
         'InterpolationFactor',     sys_params_tx.usrp_interpolation_factor, ...
         'Gain',                    sys_params_tx.usrp_gain, ...
         'CenterFrequency',         sys_params_tx.usrp_center_frequency, ...
         'TransportDataType',       sys_params_tx.usrp_transport_data_type, ...
         'LocalOscillatorOffset',   sys_params_tx.usrp_local_oscillator_offset, ...    
         'ClockSource',             sys_params_tx.usrp_clock_source, ...
         'PPSSource',               sys_params_tx.usrp_pps_source,...
         'ChannelMapping',          sys_params_tx.usrp_channelmapping);
       %coder.varsize('tx_radio.ChannelMapping');
       %tx_radio.ChannelMapping =  sys_params_tx.usrp_channelmapping;
       %set(tx_radio,'ChannelMapping',sys_params_tx.usrp_channelmapping);
        % Initialize the number of frame to be sent
        frame_id = 1;
        % Transmitting signal
        disp('********** Start transmitting signal **********');        
        while frame_id <= sys_params_tx.total_frames_to_send    
            % Feed one frame to the USRP device and the frame is
            % automatically transmitted by the USRP device
            step(tx_radio, frame_to_send);
            % Update the number of next frame to be transmitted
            frame_id = frame_id + 1;
        end    
        disp('********** Stop transmitting signal **********');
        release(tx_radio);
    end
end