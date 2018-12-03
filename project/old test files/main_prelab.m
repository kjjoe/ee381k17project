%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% main_prelab.m
%
% This is script allowing iteratively calling the transmitter.m and
% receiver.m to simulate your estimation performance. You should understand
% the code before using it.
%
% Created Oct. 12, 2018 
% Modified Nov. 1, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all;
% YOU NEED TO COMMENT THE clear all and the variables that are defined in this file
% to avoid overwritten AT BOTH receiver.m and transmitter.m
%file FOR USING THIS SCRIPT
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Parameters
h1 = [1];
h2 = [1, -j/2].';
h4 = [1, -j/2, 1/4+ j/4, 1/8].';
LOOP = 100; % Number of loops
M = 4; % Modulation scheme to test
channel_snr_dB_set = [5:5:30]; % SNR in dB
payload_size_in_ofdm_symbols = 10;
num_h_to_test = 3;
MSE = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));
NMSE_numerator_LOOP = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));
NMSE_denumerator_LOOP = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));
ser = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));
ber = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));
fer = zeros(LOOP,length(channel_snr_dB_set),length(num_h_to_test));

%% Repetition of simulation
for loop = 1:1:LOOP
     
    for m = 1:length(channel_snr_dB_set)
        channel_snr_dB = channel_snr_dB_set(m);
        for n = 1:num_h_to_test
            fprintf('Loop: %d, SNR: %d, Channel: %d\n',loop,channel_snr_dB,n)
            switch n
                case 1
                    channel_tap = h1;
                case 2
                    channel_tap = h2;
                case 3
                    channel_tap = h4;
            end
            % Run transmitter
            transmitter
            % Run receiver 
            receiver
            % Fetch quantity
            MSE(loop,m,n) = MSE_one_simulation;
            NMSE_numerator_LOOP(loop,m,n) = NMSE_one_simulation_numerator;
            NMSE_denumerator_LOOP(loop,m,n) = NMSE_one_simulation_denumerator;
            ser(loop,m,n) = SER;
            ber(loop,m,n) = BER;
            fer(loop,m,n) = FER;
        end
    end
end

%% Plot result
plot_params.LineWidth = 3;
plot_params.MarkerSize = 8;
plot_params.FontSize = 14;
set(0, 'DefaultLineLineWidth', plot_params.LineWidth);
set(0, 'DefaultAxesFontSize', plot_params.FontSize);
set(0, 'DefaultLineMarkerSize', plot_params.MarkerSize);
%MSE = squeeze(mean(MSE));
NMSE = squeeze((mean(NMSE_numerator_LOOP)))./squeeze((mean(NMSE_denumerator_LOOP)));
ave_ser = squeeze(mean(ser));
ave_ber = squeeze(mean(ber));
ave_fer = squeeze(mean(fer));

num = 1;
figure(num)
plot(channel_snr_dB_set,MSE(:,1));hold on;
plot(channel_snr_dB_set,MSE(:,2));grid on;
plot(channel_snr_dB_set,MSE(:,3));grid on;
title('Mean Square Errof of Channel Estimation')
xlabel('SNR (dB)')
ylabel('MSE')
legend('h1','h2','h4');
%print(['MSE'],'-djpeg');
str = sprintf('fig%d.jpg',num);
saveas(num,str)
num = num+1;

figure(num)
plot(channel_snr_dB_set,NMSE(:,1));hold on;
plot(channel_snr_dB_set,NMSE(:,2));grid on;
plot(channel_snr_dB_set,NMSE(:,3));grid on;
title('Normalized Mean Square Errof of Channel Estimation')
xlabel('SNR (dB)')
ylabel('NMSE')
legend('h1','h2','h4');
%print(['NMSE_Channel'],'-djpeg');
str = sprintf('fig%d.jpg',num);
saveas(num,str)
num = num+1;

figure(num)
plot(channel_snr_dB_set,ave_ser(:,1));hold on;
plot(channel_snr_dB_set,ave_ser(:,2));grid on;
plot(channel_snr_dB_set,ave_ser(:,3));grid on;
title('SER')
xlabel('SNR (dB)')
ylabel('SER')
legend('h1','h2','h4');
%print(['SER'],'-djpeg');
str = sprintf('fig%d.jpg',num);
saveas(num,str)
num = num+1;

% Plot Correlation
figure(num)
for i=1:1:length(channel_snr_dB_set)
    channel_snr_dB = channel_snr_dB_set(i);
    load(['R_SNR_' num2str(channel_snr_dB) '.mat'],'R');
    plot(0:1:length(R)-1,R);hold on;grid on
end
title('Correlation performed in frame synchronization')
xlabel('Index')
ylabel('Correlation')
legend(['SNR=' num2str(channel_snr_dB_set(1))],...
       ['SNR=' num2str(channel_snr_dB_set(2))],...
       ['SNR=' num2str(channel_snr_dB_set(3))],...
       ['SNR=' num2str(channel_snr_dB_set(4))],...
       ['SNR=' num2str(channel_snr_dB_set(5))],...
       ['SNR=' num2str(channel_snr_dB_set(6))]);
%print(['Correlation_frame_synchronziation'],'-djpeg');
str = sprintf('fig%d.jpg',num);
saveas(num,str)
num = num+1;

figure(num)
for i=1:1:length(channel_snr_dB_set)
    channel_snr_dB = channel_snr_dB_set(i);
    load(['R_SNR_' num2str(channel_snr_dB) '.mat'],'R');
    plot(0:1:100,R(1:101));hold on;grid on
end
title('Correlation performed in frame synchronization')
xlabel('Index')
ylabel('Correlation')
legend(['SNR=' num2str(channel_snr_dB_set(1))],...
       ['SNR=' num2str(channel_snr_dB_set(2))],...
       ['SNR=' num2str(channel_snr_dB_set(3))],...
       ['SNR=' num2str(channel_snr_dB_set(4))],...
       ['SNR=' num2str(channel_snr_dB_set(5))],...
       ['SNR=' num2str(channel_snr_dB_set(6))]);
%print(['Correlation_frame_synchronziation_zoom'],'-djpeg');
str = sprintf('fig%d.jpg',num);
saveas(num,str)
num = num+1;

