function signal_out = joint_sync(signal_in,sys_params_rx)
    % initial constants     
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
    frame_sync = signal_in(STF_start+Lc:end,1);  % assuming both antennas are the same ...
    for delta = 0:frame_size-1
        numer = sum(sum(abs(conj(frame_sync(n + (m-1)*Lc + delta)).* frame_sync(n + m*Lc + delta))));
        denom = sum(sum(abs(frame_sync(n + (m-1)*Lc + delta)).^2));
        R1(delta+1) = numer/denom;
    end

    [~,offset1] = max(R1);
    frame_synced_data_stage1 = signal_in(offset1:offset1+sys_params_rx.frame_size-1,:);

%%%%% FREQ SYNC STAGE 1 %%%%%

    stf_sync1 = frame_synced_data_stage1((STF_start:data_start-1),1);
    stf_sync2 = frame_synced_data_stage1((STF_start:data_start-1),2);

    ep11 = angle(sum(sum(conj(stf_sync1(n + (m-1)*Lc)).* stf_sync1(n + m*Lc))))/(2*pi*Lc);
    ep12 = angle(sum(sum(conj(stf_sync2(n + (m-1)*Lc)).* stf_sync2(n + m*Lc))))/(2*pi*Lc);
    
    % Phase offset in comparison with the first symbol of the first frame
    % frame_id = 1;
%     phase_offset = exp(1j*2*pi*epsilon*(sys_params_rx.frame_size-1)*(frame_id-1)); % phase offset with respect to the first symbol of the first frame
%     freq_synced_data = input_data .* conj(phase_offset); % Compensate the phase offset

    n1 = (0:length(signal_in)-1)';
    
    final_e = mean([ep11, ep12]); % shouldnt each be evaluated separately?
    
    cfo_stage1 = signal_in.*exp(-1j*2*pi*final_e*n1);

%%%%%% FRAME SYNC STAGE 2 %%%%%%
    freq_synced_input_data = cfo_stage1(CEF_start:end,1);  % assuming both antennas are the same ...
    n = 1:(Lc+N);
    R2 = zeros(frame_size,1);
    for d = 0:frame_size-1
        num = abs(sum(freq_synced_input_data(n+N+d).*conj(freq_synced_input_data(n+d))))^2;
        den1 = sqrt(sum(abs(freq_synced_input_data(n+N+d)).^2));
        den2 = sqrt(sum(abs(freq_synced_input_data(n+d)).^2));
        R2(d+1) = num/(den1*den2);
    end


    [~,offset2] = max(R2);
    
    if offset2 > 1 % why does this improve my SER a lot?
        offset2 = offset2 - 1;
    end
    frame_synced_data = cfo_stage1(offset2:offset2+sys_params_rx.frame_size-1,:);

%%%%% FREQ SYNC STAGE 2 %%%%%

    cef_sync1 = frame_synced_data(CEF_start+Lc:data_start-1,1);
    cef_sync2 = frame_synced_data(CEF_start+Lc:data_start-1,2);

    n = 1:N;
    ep21 = (1/(2*pi*N))*angle(sum(conj(cef_sync1(n)).*cef_sync1(n+N)));
    ep22 = (1/(2*pi*N))*angle(sum(conj(cef_sync2(n)).*cef_sync2(n+N)));
    final_e = mean([ep21,ep22]);
    n1 = (0:length(frame_synced_data)-1)';
   
    signal_out = frame_synced_data.*exp(-1j*2*pi*final_e*n1);
end