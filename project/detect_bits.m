function output_bit = detect_bits(symbol)
    detect = symbol;

    detect = reshape(detect,[],1);

    L_out = length(detect)*2;

    output_bit = zeros(L_out,1);
    up = output_bit; % upsample 
    up(1:2:end) = detect;

    % first bit of the input symbol
    output_bit(imag(up) > 0) = 0;
    output_bit(imag(up) < 0) = 1;

    % second bit of the input symbol
    output_bit(circshift(real(up) > 0 , 1)) = 0;
    output_bit(circshift(real(up) < 0 , 1)) = 1;
end