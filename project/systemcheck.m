% system check over snr
LOOP = 5;
snr_range = (1:0.1:30);
ber = zeros(length(snr_range),LOOP);
ser = ber;
tic

for loop = 1:LOOP
    transmitter
    aaa = 1;
    for snr = snr_range
        receiver2
        ber(aaa,loop) = ratio_ber;
        ser(aaa,loop) = ratio_ser;
        aaa = aaa+1;
    end
end
toc
