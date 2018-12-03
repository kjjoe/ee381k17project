function frame_synced_data = frame_sync(downsampled,sys_params_rx)

if sys_params_rx.sim_delay
    
cfo_start = sys_params_rx.cfo_start;
Lc = 16;
frame_size = sys_params_rx.frame_size;
N = 64;
    
    % stage 1
%     m = 1:(2*M+1);
%     n = (1:Lc)'; % but usually 0 to Lc-1
%     R = zeros(frame_size,1);
%     frame_sync = downsampled(cfo_start+Lc:end,1); 
%     for delta = 0:700
%         numer = sum(sum(abs(conj(frame_sync(n + (m-1)*Lc + delta)).* frame_sync(n + m*Lc + delta))));
%         denom = sum(sum(abs(frame_sync(n + (m-1)*Lc + delta)).^2));
%         R(delta+1) = numer/denom;
%     end

    % stage 2
    
    
    freq_synced_input_data = downsampled(cfo_start+160:end,1); 
    n = 1:(Lc+N);
    D = length(freq_synced_input_data) - frame_size;
    R = zeros(D,1);
    for d = 0:D
        num = abs(sum(freq_synced_input_data(n+N+d).*conj(freq_synced_input_data(n+d))))^2;
        den1 = sqrt(sum(abs(freq_synced_input_data(n+N+d)).^2));
        den2 = sqrt(sum(abs(freq_synced_input_data(n+d)).^2));
        R(d+1) = num/(den1*den2);
    end


    [~,offset] = max(R);
    frame_offset = offset - 1;
    
    frame_synced_data = downsampled(offset:offset+sys_params_rx.frame_size-1,:);
else
    frame_synced_data = downsampled;
end

end