%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% systemcheck.m
%
% This is script allowing iteratively calling the transmitter.m and
% receiver.m to simulate your estimation performance. 
%
% Modified Nov. 19, 2018 
% Robert W. Heath Jr.
% Yi Zhang
% Kevin Joe
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Make sure you comment out the following before running:
%   'snr' on the receive side
%   'rng( ... ) on the transmit side

clear all
LOOP = 10;
snr_range = (1:1:30);
ber = zeros(length(snr_range),LOOP);
ser = ber;

tic
for looop = 1:LOOP
    transmitter
    index = 1;
    fprintf('LOOP: %d\n',looop);
    for snr = snr_range
        receiver
        ber(index,looop) = mean(ber_ratio);
        ser(index,looop) = mean(ser_ratio);
        mse(index,looop) = MSE;
        index = index+1;
    end
end
toc

%% plots

% figure(1)
% plot(snr_range,ser)
% title('All iterations of 2x2 MIMO')
% xlabel('SNR')
% ylabel('SER')

figure(1)
hold on
plot(snr_range,mean(ser,2))
title('Average SER')
xlabel('SNR')
ylabel('SER')

figure(2)
hold on
plot(snr_range,mean(mse,2))
title('Average MSE')
xlabel('SNR')
ylabel('MSE')