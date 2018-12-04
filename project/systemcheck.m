% system check over snr
LOOP = 100;
snr_range = (1:0.2:30);
ber = zeros(length(snr_range),LOOP);
ser = ber;
tic

for loop = 1:LOOP
    transmitter
    aaa = 1;
    fprintf('LOOP: %d\n',loop);
    for snr = snr_range
        receiver2
        ber(aaa,loop) = mean(ber_ratio);
        ser(aaa,loop) = mean(ser_ratio);
        aaa = aaa+1;
    end
end
toc

%% plots

figure(1)
plot(snr_range,ser)
title('All iterations of 2x2 MIMO')
xlabel('SNR')
ylabel('SER')

figure(2)
plot(snr_range,mean(ser,2))
title('Average SER')
xlabel('SNR')
ylabel('SER')