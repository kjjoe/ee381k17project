%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% joint_sync.m
% function signal_out = joint_sync(signal_in,sys_params_rx)
%
% This function corrects the carrier frequency offset and frame
%   synchronizes each antenna separately. It computes it in two stages.
%
% Input
%    signal_in is a matrix of the size (2*frame_size-1 x 2). It is the signal
%       after downsampling. 
%
% Output
%    signal_out is a matrix of the size (frame_size x 2). It is the signal
%       after doing frame sync and freq sync.
%
% Last Modified Dec. 10, 2018
% Robert W. Heath Jr.
% Yi Zhang
% Kevin Joe
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function signal_out = joint_sync(signal_in,sys_params_rx,frame_id)
    signal_out = [jointsync1(signal_in(:,1),sys_params_rx,frame_id), ...
                  jointsync1(signal_in(:,2),sys_params_rx,frame_id)];
end

%%% single side only
function signal_out = jointsync1(signal_in,sys_params_rx,frame_id)
    M = sys_params_rx.M;
    N = sys_params_rx.N_carriers;
    STF_start = sys_params_rx.STF_start;
    CEF_start = sys_params_rx.CEF_start;
    data_start = sys_params_rx.data_start;
    Lc = sys_params_rx.L_CP;
    frame_size = sys_params_rx.frame_size;

%%%%%% FRAME SYNC STAGE 1 %%%%%%
    m = 1:(2*M+1);
    n = (1:Lc)'; % but usually 0 to Lc-1
    R1 = zeros(frame_size,1);
    frame_sync = signal_in(STF_start+Lc:end); 
    for delta = 0:frame_size-1
        numer = sum(sum(abs(conj(frame_sync(n + (m-1)*Lc + delta)).* frame_sync(n + m*Lc + delta))));
        denom = sum(sum(abs(frame_sync(n + (m-1)*Lc + delta)).^2));
        R1(delta+1) = numer/denom;
    end

    [~,offset1] = max(R1);
    frame_synced_data_stage1 = signal_in(offset1:offset1+sys_params_rx.frame_size-1,:);

%%%%% FREQ SYNC STAGE 1 %%%%%

    stf_sync1 = frame_synced_data_stage1((STF_start:data_start-1),1);

    ep11 = angle(sum(sum(conj(stf_sync1(n + (m-1)*Lc)).* stf_sync1(n + m*Lc))))/(2*pi*Lc);
    %ep11 = 0;
    
    n1 = (0:length(signal_in)-1)';
    cfo_stage1 = signal_in.*exp(-1j*2*pi*ep11*n1);

%%%%%% FRAME SYNC STAGE 2 %%%%%%
    freq_synced_input_data = cfo_stage1(CEF_start:end,1);  
    n = 1:(N+Lc);
    R2 = zeros(frame_size,1);
    for d = 0:frame_size-1
        num = abs(sum(freq_synced_input_data(n+N+d).*conj(freq_synced_input_data(n+d))))^2;
        den1 = sqrt(sum(abs(freq_synced_input_data(n+N+d)).^2));
        den2 = sqrt(sum(abs(freq_synced_input_data(n+d)).^2));
        R2(d+1) = num/(den1*den2);
    end
    [~,offset2] = max(R2);
    if offset2 > 2 % why does this improve my SER a lot?
        offset2 = offset2 - 2;
    end
    frame_synced_data = cfo_stage1(offset2:offset2+sys_params_rx.frame_size-1,:);

%%%%% FREQ SYNC STAGE 2 %%%%%

    cef_sync1 = frame_synced_data(CEF_start+Lc:data_start-1,1);
    n = 1:N;
    ep21 = (1/(2*pi*N))*angle(sum(conj(cef_sync1(n)).*cef_sync1(n+N)));
    %ep21 = 0;
    n1 = (0:length(frame_synced_data)-1)';
    signal_out = frame_synced_data.*exp(-1j*2*pi*ep21*n1);
end