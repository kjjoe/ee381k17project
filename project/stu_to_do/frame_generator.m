%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% frame_generator.m
% function framed_data = frame_generator(payload_symbols, sys_params_tx)
%
% This function generates the frame by adding preamble to the payload_symbols
% 
% Input: 
%    payload_symbols is a column vector of symbols after M-QAM
%       modulation without being attached preamble. Its length is sys_params_tx.payload_size_in_symbols
%    sys_params_tx is the system parameters employed at the transmitter side  
%
% Output
%   framed_data is a column vector of symbols after being added a preamble
%   The length of framed_data is sys_params_tx.payload_size_in_symbols +
%   sys_params_tx.sc_preamble
%
%
% Created Aug. 20, 2018 
% Modified Oct. 12, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function framed_data = frame_generator(payload_symbols, sys_params_tx)
    switch sys_params_tx.sys_name
        case "SC"
            framed_data = [sys_params_tx.sc_preamble;payload_symbols]; 
        case "SC-FDE"
            framed_data = SC_FDE_mod(payload_symbols, sys_params_tx);
        case "OFDM"
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            ofdm_payload_symbols = OFDM_mod(payload_symbols, sys_params_tx);
            framed_data = [sys_params_tx.OFDM_preamble; ofdm_payload_symbols];
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%--Your Implemented Function---%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    end
end

function framed_data = SC_FDE_mod(input_data, sys_params_rx)
    % Fetch parameters
    L_CP = sys_params_rx.L_CP;
    N = sys_params_rx.N_carriers;
    % Modulation
    parallel_symbol_stream = S2P(input_data, N);
    cp_parallel_bit_stream = add_CP(parallel_symbol_stream, L_CP);
    payload = P2S(cp_parallel_bit_stream);
    % Insert preamble
    framed_data = [sys_params_rx.sc_preamble; payload]; 
end
