%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OFDM_mod.m
% function ofdm_payload_symbols = OFDM_mod(payload_symbols, sys_params_tx)
%
% This function generates the OFDM symbols by modulating the payloads, M-QAM 
% modulated symbol.
% 
% Input: 
%    payload_symbols is a column vector of symbols after M-QAM modulation 
%        and its length is sys_params_tx.payload_size_in_symbols
%    sys_params_tx is the system parameters employed at the transmitter side  
%
% Output
%   ofdm_payload_symbols is a column vector of ofdm symbols after being
%   modulated by OFDM operations and its length is 
%   sys_params_tx.L_CP * sys_params_tx.payload_size_in_ofdm_symbols + ...
%   sys_params_tx.N_carriers * sys_params_tx.payload_size_in_ofdm_symbols.
%   This is because the pilot, DC, inactive subcarriers and cyclic prefix  
%   are added in OFDM modulation.
%
%
% Created Aug. 20, 2018 
% Modified Oct. 31, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function ofdm_payload_symbols = OFDM_mod(Input_data, sys_params_tx)
    % Fetch parameters
    L_CP = sys_params_tx.L_CP; % Length of prefix for training sequence
    N_carriers = sys_params_tx.N_carriers; % Number of total subcarriers for SC-FDE and OFDM (N-DFT)
    N_data_carriers = sys_params_tx.N_data_carriers; % Number of subcarriers used for data transmission
    data_carriers_index = sys_params_tx.data_carriers_index; % Index of subcarriers used for data transmission
    pilot_carriers_index = sys_params_tx.pilot_carriers_index; % Index of subcarriers used for pilot transmission
    pilot = sys_params_tx.pilot; % Pilot symbols
    null_tone = sys_params_tx.null_tone; % Index of DC subcarrier
    % OFDM modulation
    % Code here and this function would be called in frame_generator.m
    
    number_symbols = sys_params_tx.payload_size_in_ofdm_symbols;
    data_mat = reshape(Input_data,N_data_carriers,[]);
    data_block = zeros(N_carriers,number_symbols); 
    data_block(data_carriers_index+1,:) = data_mat; %indices start at 0
    data_block(pilot_carriers_index+1,:) = repmat(pilot,1,number_symbols); 
    % data_block(null_tone+1) = 0; %redundant
    
    s = ifft(data_block,N_carriers,1)*sqrt(N_carriers); % along the columns
  	w = [s(end-L_CP+1:end,:); s];
    
    ofdm_payload_symbols = reshape(w,[],1);
end
