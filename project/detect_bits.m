%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% detect_bits.m
% function output_bit = detect_bits(symbol)
%
% This function undo's the spatial multiplexing and then detects the
% corresponding bits.
%
% Input
%    symbol is a (240 by 2) matrix that corresponds to the detected
%       symbols on the receive side. The first column vector corresponds to
%       the symbols detected from antenna 1 and second column vector is
%       similarly defined.
%
% Output
%    output_bit is (960 x 1) vector that corresponds to the detected bits
%    on the receive side.
%
% Last Modified Dec. 10, 2018
% Robert W. Heath Jr.
% Yi Zhang
% Kevin Joe
% The University of Texas at Austin
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function output_bit = detect_bits(symbol)
    detect = symbol;
    
    % undo spatial multiplex
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