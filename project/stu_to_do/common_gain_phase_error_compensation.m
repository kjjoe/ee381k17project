%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% common_gain_phase_error_compensation.m
% function equalized_data_corrected = common_gain_phase_error_compensation(equalized_data, sys_params_rx)
%
% This function helps to estimates the common gain and phase error.
%
% Input
%   equalized_data is a column vector consisting of one frame of received
%       data after equalization. In particular, the preamble and the cyclic 
%       prefix has been removed already.
%   sys_params_rx is the system parameters employed at the receiver side
%
% Output
%   equalized_data_corrected is a column consisting of one frame of received
%   data after the compensation of common gain and the phase error. Its
%   size is the same as the input equalized_data.
%
% Created Aug. 30, 2018
% Modified Oct. 31, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function equalized_data_corrected = common_gain_phase_error_compensation(equalized_data, sys_params_rx)
    % Fetch parameters
    pilot = sys_params_rx.pilot; % a column vector of pilot symbol
    pilot_carriers_index = sys_params_rx.pilot_carriers_index; % Index of subcarriers for pilots.
    N_carriers = sys_params_rx.N_carriers; % Number of total subcarriers (N-DFT)

    % Common gain and phase error estimaton
    % Code here
    blocks = fft(reshape(equalized_data,N_carriers,[]),64)/sqrt(N_carriers);
    eq = blocks(pilot_carriers_index+1,:);
    a = (pilot' * eq)/sum(abs(pilot).^2);
    equalized_data_corrected = reshape(blocks./a,[],1);
end


