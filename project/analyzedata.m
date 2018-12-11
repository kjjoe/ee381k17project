%% analyze data
addpath(genpath([pwd '/labdata']));
snrs = [2,7,13,23,30,40];
index = 1;
for s = snrs
load(['snr',num2str(s),'.mat'])
receiver
totalser(index) = mean(reshape(ser_ratio,[],1));
totalsnr(index) = mean([snr1;snr2]);
index = index+1;
end
%%
hold on
%plot(totalsnr,totalser
plot(snrs,totalser)

% lab 10

snr2 = [39.9626; 29.0114; 15.8120;13.3753;  10.6074; 6.8144; 4.7891];
ser2 = [0      ; 0      ; 0.0450 ;0.1411; 0.3426; 0.4281; 0.5568]; 

%plot(snr2,ser2)
xlabel('SNR')
ylabel('SER')
%legend('MIMO','SISO')