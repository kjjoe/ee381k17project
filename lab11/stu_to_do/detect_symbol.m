%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% detect_symbol.m
% function symbol_out = detect_symbol(signal_in,G,sys_params_rx)
%
% This function demodulates and detects symbols from the input signal.
%
% Input
%   signal_in is a matrix of samples after being synchronized, its
%       size is (sys_params_rx.frame_size by 2) where each column is
%       correspondes to the receive signal from an antenna
%
%   G is the pseudo-inverse of H, size (2 x 2 x 64), which is used for zero
%       forcing. Each G(:,:,k) corresponds to the channel estimate at 
%       frequency k
%
%   sys_params_rx is the system parameters employed at the receiver side
%
% Output
%    symbol_out is a (240 by 2) matrix that corresponds to the detected
%       symbols on the receive side. The first column vector corresponds to
%       the symbols detected from antenna 1 and second column vector is
%       similarly defined.
%
% Last Modified Dec. 10, 2018
% Robert W. Heath Jr.
% Yi Zhang
% Kevin Joe
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




function symbol_out = detect_symbol(signal_in,G,sys_params_rx)
    % basic constants
    data_start = sys_params_rx.data_start;
    frame_size = sys_params_rx.frame_size;
    N = sys_params_rx.N_carriers;
    N_rx = sys_params_rx.N_rx;
    M = sys_params_rx.M;
    Lc = sys_params_rx.L_CP;
    bps = length(sys_params_rx.data_carriers_index);  %bits per symbol
    blockps = sys_params_rx.payload_size_in_ofdm_symbols; % total number of blocks sent, 10
    
    % demodulate, go to freq domain
    Ydata = signal_in(data_start:frame_size,:); % no training
    Ydata = reshape(Ydata,[],blockps); % blocks in time  
    Ydata = Ydata(Lc+1:end,:); % no prefix in time
    Ydata = fft(Ydata,N,1)/sqrt(N); % data in freq domain
    Ydata = reshape(transpose(reshape(Ydata,[],2)),[],1); % remodulate, hard coded, should be length 640
    
%%%%% YOUR CODE GOES HERE %%%%%    
%%% Set up the combination of symbols that can be sent (total 16 for 4 C)
    qam = [1+1j; -1+1j; -1-1j; 1-1j]/sqrt(2);
    C = zeros(N_rx,1,M^2);
    C(1,1,:) = reshape(repmat(transpose(qam),4,1),[],1);
    C(2,1,:) = repmat(qam,4,1);

%%% Detect symbols retrieving each 2 block at a time. 
% Note Ydata is formatted such that every other point is from the same
% antenna. 
% Ydata(1:2:end) = refers to antenna 1
% Ydata(2:2:end) = refers to antenna 2.
% So, Ydata(1:2) are the observations of antenna 1 and antenna 2 at freq
% k=0 and Ydata(3:4) at freq k=1 and so on.
    symbol_plot = []; % for debugging
    symbol_out = zeros(bps*blockps/N_rx,N_rx);
    N2 = 2*N; % two blocks at a time for each antenna
    for block = 0:(blockps/N_rx)-1
        Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
        s_tmp = zeros(bps*2,1);
        index = 0;
        for k = (sys_params_rx.data_carriers_index)
            z_tmp = G(:,:,k+1)*Ydatablock(2*k+1:2*k+2);
            [~,ind] = min(reshape(vecnorm(z_tmp-C),[],1));
            symbol_plot = [symbol_plot; z_tmp]; % for debugging
            s_tmp(2*index+1:2*index+2) = C(:,:,ind);
            index = index+1;
        end
        symbol_out(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));
    end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end
