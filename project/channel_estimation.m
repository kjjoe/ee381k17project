%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% channel_estimation.m
% function [G,h_est] = channel_estimation(signal_in, sys_params_rx)
%
% This function allows estimating the channel for MIMO-OFDM system
%
% Input
%   signal_in is a matrix of samples after being synchronized, its
%       size is (sys_params_rx.frame_size by 2) where each column is
%       correspondes to the receive signal from an antenna
%   sys_params_rx is the system parameters employed at the receiver side
%
% Output
%    G is the pseudo-inverse of H, the frequency domain channel estimate.
%    The size of G is (2 by 2 by 64). Each G(:,:,k) corresponds to the
%    channel estimate at frequency k. 
%    
%    h_est is the time domain channel estimate, size (2 x 2 x L), where L
%    is the length of the channel order estimate. Each vector h_est(i,j,:)
%    corresponds to the channel from transmit antenna j to receive 
%    antenna i.
%
% Last Modified Dec. 10, 2018
% Robert W. Heath Jr.
% Yi Zhang
% Kevin Joe
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



function [G,h_est] = channel_estimation(signal_in,sys_params_rx)
    % basic constants
    Lc = sys_params_rx.L_CP; % length of cyclic prefix
    N = sys_params_rx.N_carriers;
    L = sys_params_rx.channel_order_estimate;
    N_tx = sys_params_rx.N_tx; % number of transmit antennas 
    N_rx = sys_params_rx.N_rx; % number of receive antennas
    
    t1 = sys_params_rx.single_CE_freq_domain{1}; % training seq 1
    t2 = sys_params_rx.single_CE_freq_domain{2}; % training seq 2
    CE = signal_in((Lc+1:Lc+N),:); % channel estimation field without cyclic prefix in time domain
    
%%%%%% YOUR CODE GOES HERE %%%%%%    
    Y = reshape(transpose(fft(CE,N)/sqrt(N)),[],1); % why does sqrt(8) provide the correct scaling?
    
    training = reshape(transpose([t1, t2]),[],1);

    l = transpose(0:L);

    T = zeros(64*N_rx,N_tx*N_rx*(max(l)+1)); % pre allocation
    index = 0; % could be only active carriers for estimate.
    for k = 0:63  % is i possible to vectorize this?
        e = exp(-1i*2*pi*l*k/N);
        tmp = training(2*k+1:2*k+2);
        T((N_rx*index+1:N_rx*index+N_rx),:) = kron(kron(transpose(e),transpose(tmp)),eye(N_rx));
        index = index+1;
    end

    h_vec = inv(T'*T)*T'*Y/2; % vectorized 
    h_est = reshape(h_vec,N_rx,N_tx,L+1); % back to matrix (R x T x L), for testing

    H = zeros(N_rx,N_tx,N); % idk which to pick 
    G = H;  % zero forcing requires less computation later
    for k = 0:63  % is i possible to vectorize this?
        e = exp(-1i*2*pi*l*k/N);
        tmp = kron(kron(transpose(e),eye(N_tx)),eye(N_rx));
        H(:,:,k+1) = reshape(tmp*h_vec,N_rx,N_tx);
        G(:,:,k+1) = pinv(H(:,:,k+1));
    end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
end