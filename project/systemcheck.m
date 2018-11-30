% system check over snr
ber = zeros(40,10);
ser = ber;
tic

for loop = 1:10
    transmitter
    for snr = 1:40
        receiver2
        
        ber(snr,loop) = ratio_ber;
        ser(snr,loop) = ratio_ser;
    end
end
toc
