%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OFDM_demod.m
% function sub_payload = OFDM_demod(equalized_data, sys_params_rx)
%
% This function demodulates the OFDM symbol and output the QAM modulated payload data
% 
% Input: 
%    equalized_data is a column vector of OFDM symbols after
%    equalization, in particular, the cyclic prefix has been removed
%    already
%
% Output
%    sub_payload is a column vector of QAM symbols demodulated from OFDM symbols. 
%    The length of SubPayload is sys_params_rx.payload_size_in_symbols
%
%
% Created Aug. 20, 2018 
% Modified Oct. 31, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function sub_payload = OFDM_demod(equalized_data, sys_params_rx)
    % Fetch parameters
    N_carriers = sys_params_rx.N_carriers; % Number of total subcarriers for SC-FDE and OFDM (N-DFT)
    data_carriers_index = sys_params_rx.data_carriers_index; % Index of subcarriers for data transmission
    % Demodulation
    % Code here
    
    blocks = reshape(equalized_data,N_carriers,[]);
    sub_payload = reshape(blocks(data_carriers_index+1,:),[],1);
    
end
