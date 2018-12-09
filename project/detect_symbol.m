function symbol_out = detect_symbol(signal_in,H,G,sys_params_rx)
    % basic constants
    data_start = sys_params_rx.data_start;
    frame_size = sys_params_rx.frame_size;
    N = sys_params_rx.N_carriers;
    N_rx = sys_params_rx.N_rx;
    M = sys_params_rx.M;
    Lc = sys_params_rx.L_CP;
    bps = length(sys_params_rx.data_carriers_index);  %bits per symbol
    blockps = sys_params_rx.payload_size_in_ofdm_symbols;
    qam = setup_mimo_qam(M,N_rx);
    
    % demodulate, go to freq domain
    Ydata = signal_in(data_start:frame_size,:); % no training
    Ydata = reshape(Ydata,[],blockps); % blocks in time  
    Ydata = Ydata(Lc+1:end,:); % no prefix in time
    Ydata = fft(Ydata,N,1)/sqrt(N); % data in freq domain                 
    Ydata = reshape(transpose(reshape(Ydata,[],2)),[],1); % remodulate, hard coded

    % detect 1 block at a time
    symbol_out = ZF(Ydata,G,bps,blockps,N_rx,N,qam,sys_params_rx);
    %symbol_out = noZF(Ydata,H,bps,blockps,N_rx,N,qam,sys_params_rx);
end

function qam2 = setup_mimo_qam(M,N_rx)
    qam = [1+1j; -1+1j; -1-1j; 1-1j]/sqrt(2);
    qam2 = zeros(N_rx,1,M^2);
    qam2(1,1,:) = reshape(repmat(transpose(qam),4,1),[],1);
    qam2(2,1,:) = repmat(qam,4,1);
end

%no zero forcing if you want
function symbol_out = noZF(Ydata,H,bps,blockps,N_rx,N,qam,sys_params_rx)
    s_est2 = zeros(bps*blockps/N_rx,N_rx);
    N2 = 2*N;
%     forplots2 = [];
%     forplots3 = [];

    qam3 = cell(N,1);
    for k = (sys_params_rx.data_carriers_index)
        for index = 1:16
            qam3{k}(:,:,index) = H(:,:,k)*qam(:,:,index);
        end
    end

    for block = 0:(blockps/N_rx)-1
        Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
        s_tmp = zeros(bps*2,1);
        index = 0;
        for k = (sys_params_rx.data_carriers_index)
            [~,ind] = min(reshape(vecnorm(Ydatablock(2*k+1:2*k+2)-qam3{k}),[],1));
            s_tmp(2*index+1:2*index+2) = qam(:,:,ind);
            index = index+1;
%             forplots2 = [forplots2; qam3{k}(:,:,ind)];
%             forplots3 = [forplots3; Ydatablock(2*k+1:2*k+2)];
        end
        s_est2(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));
    end
    symbol_out = reshape(s_est2,[],1);
end

% zero forcing
function symbol_out = ZF(Ydata,G,bps,blockps,N_rx,N,qam,sys_params_rx)
    symbol_out = zeros(bps*blockps/N_rx,N_rx);
    N2 = 2*N; % hard coded...
    forplots = []; %For debugging
    for block = 0:(blockps/N_rx)-1
        Ydatablock = Ydata(N2*block+1 : N2*block+N2  );
        s_tmp = zeros(bps*2,1);
        index = 0;
        for k = (sys_params_rx.data_carriers_index)
            z_tmp = G(:,:,k+1)*Ydatablock(2*k+1:2*k+2);
            [~,ind] = min(reshape(vecnorm(z_tmp-qam),[],1));
            forplots = [forplots; z_tmp];
            s_tmp(2*index+1:2*index+2) = qam(:,:,ind);
            index = index+1;
        end
        symbol_out(bps*block+1 : bps*block+bps,:) = transpose(reshape(s_tmp,2,[]));

    end
end
  