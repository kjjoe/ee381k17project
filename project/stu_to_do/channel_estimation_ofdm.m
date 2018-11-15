%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% channel_estimation_ofdm.m
% function h_est = channel_estimation_ofdm(input_data, sys_params_rx)
%
% This function allows estimating the channel for ofdm system
%
% Input
%   input_data is a column vector of samples after being synchronized, its
%       length is sys_params_rx.frame_size
%   sys_params_rx is the system parameters employed at the receiver side
%
% Output
%   h_est is a column vector representing the estimated channel, its length
%       is the estimated channel order plus one, i.e. sys_params_rx.channel_order_estimate + 1. 
%
% Created Aug. 30, 2018
% Modified Oct. 12, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function h_est = channel_estimation_ofdm(input_data, sys_params_rx)
    % Fetch parameters
    Lt = sys_params_rx.L_P; % Cyclic prefix for ofdm training symbols
    L = sys_params_rx.channel_order_estimate; % Estimated channel order
    t = sys_params_rx.single_OFDM_training_seq_freq_domain;  % A single ofdm training symbol in frequence domain
    N_carriers = sys_params_rx.single_OFDM_training_seq_time_domain_length; % Length of a single ofdm training symbol in time domain, it equals to sys_params_rx.N_carriers 
    OFDM_preamble_length = sys_params_rx.OFDM_preamble_length; % Length of the complete OFDM preamble
    active_carriers_index = sys_params_rx.active_carriers_index + 1; % Acctive carriers used for data and pilots transmission
    % Channel estimation
    % Code here
    
    y1 = fft(input_data(Lt+1: Lt + N_carriers),N_carriers)/sqrt(N_carriers);
    y2 = fft(input_data(Lt+1+N_carriers: Lt + 2*N_carriers),N_carriers)/sqrt(N_carriers);

    P = diag(t);
    W = dftmtx(N_carriers);
    E = W(:,1:L+1);
    
    h_est = 0.5*inv(E'*(P'*P)*E)*E'*P'*y1 + 0.5*inv(E'*(P'*P)*E)*E'*P'*y2;

end

