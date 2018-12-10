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

hold on
%plot(totalsnr,totalser)
plot(snrs,totalser)