%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% joint_frame_freq_sync.m
% function [synced_data, frame_offset, freq_offset] = joint_frame_freq_sync(frame_id, input_data, sys_params_rx)
%
% This function performs carrier frequency offset (CFO) estimation and 
% frame synchronization sequentially 
%
% Input
%   frame_id is the id of the frame
%   input_data is a column vector of samples after being downsampled, its
%       length is 2*sys_params_rx.frame_size-1, 
%       long enough samples are buffered so that there is one frame of data but not so long that 
%       there are multiple training sequence
%   sys_params_rx is the system parameters employed at the receiver side
%
% Output
%   synced_data is a column vector of samples after frame and frequency
%       synchronization, the length of synced_data is sys_params_rx.frame_size. 
%       This is because 2*sys_params_rx.frame_size - 1 symbols are buffered 
%       for frame synchronization. 
%   frame_offset is a scaler indicating the frame offset
%   freq_offset is a scaler indicating the CFO
%
% Created Aug. 30, 2018
% Modified Oct. 24, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [synced_data, frame_offset, freq_offset] = joint_frame_freq_sync(frame_id, input_data, sys_params_rx)
    % Frame synchronization
    if sys_params_rx.sys_name == "OFDM"
        [frame_synced_data, frame_offset] = frame_sync_ofdm(input_data, sys_params_rx);
    else
        [frame_synced_data, frame_offset] = frame_sync(input_data, sys_params_rx);
    end

    % Frequency synchronization
    if sys_params_rx.correct_cfo
        if sys_params_rx.sys_name == "OFDM"
            if sys_params_rx.training_seq_repetition == 1 
                [freq_synced_data, freq_offset] = freq_sync_schmidl_cox(frame_id, frame_synced_data, sys_params_rx);
            else
                [freq_synced_data, freq_offset] = freq_sync_ofdm(frame_id, frame_synced_data, sys_params_rx);
            end
        else
            if sys_params_rx.training_seq_repetition == 1
                [freq_synced_data, freq_offset] = freq_sync_single_training_seq(frame_synced_data, sys_params_rx);
            else
                [freq_synced_data, freq_offset] = freq_sync(frame_synced_data, sys_params_rx);
            end
        end
    else
        freq_synced_data = frame_synced_data;
        freq_offset = 0;
    end
    
    % Output the synchronized data
    synced_data = freq_synced_data;
end
