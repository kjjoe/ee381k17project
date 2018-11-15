%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ofdm_preamble_generator.m
% function sys_params_base = ofdm_preamble_generator(sys_params_base)
%
% This function generates the preamble for OFDM systems and add relative
% properties to the basic system parameters sys_params_base, which is the
% base of the system parameters sys_params_tx and sys_params_rx
% 
% Input: 
%    sys_params_base is the common system parameters employed  
%
% Output
%    sys_params_base is the common system parameters employed  
%
%
% Created Aug. 20, 2018 
% Modified Oct. 30, 2018
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function sys_params_base = ofdm_preamble_generator(sys_params_base)
        % Fetch parameters
        N_active_carriers = sys_params_base.N_active_carriers; % Generate Zadoff-Chu sequnce with length of active subcarriers
        if sys_params_base.training_seq_length ~= N_active_carriers
            zadoff_chu_training = exp(-(1i*sys_params_base.M_ZC*pi*[0:N_active_carriers-1]'.^2)/N_active_carriers);    
            sys_params_base.training_seq = zadoff_chu_training;
        end
        N_carriers = sys_params_base.N_carriers;  % Number of total subcarriers for SC-FDE and OFDM (N-DFT)
        active_carriers_index = sys_params_base.active_carriers_index;  % Number of active subcarriers
        N_tx = sys_params_base.N_tx;
        
        if N_tx > 1 % second training sequence required
            zadoff_chu_training = exp(-(1i*sys_params_base.M_ZC2*pi*[0:sys_params_base.N_ZC-1]'.^2)/sys_params_base.N_ZC);    
            sys_params_base.training_seq2 = zadoff_chu_training;
        end
        
        %insert 0's
        for loop = 1:N_tx

            t = zeros(N_carriers,1);
            if loop == 1
                t(active_carriers_index+1) = sys_params_base.training_seq; % i think indices start at 0 ...
            else
                t(active_carriers_index+1) = sys_params_base.training_seq2;
            end

            L_P = sys_params_base.L_P;
            w = sqrt(N_carriers)*ifft(t,N_carriers);
            prefix = w(end-L_P+1:end);
            totalw = [prefix ; w]; 
            preamble = [totalw; w];
        
            sys_params_base.single_OFDM_training_seq_freq_domain{loop} = t;
            sys_params_base.single_OFDM_training_seq_time_domain{loop} = w;
            sys_params_base.OFDM_preamble{loop} = preamble;
        end
        sys_params_base.single_OFDM_training_seq_time_domain_length = N_carriers; 
        sys_params_base.OFDM_preamble_length = length(preamble);
end



