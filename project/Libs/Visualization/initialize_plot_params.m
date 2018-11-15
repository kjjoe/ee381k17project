function plotParams = initialize_plot_params(varargin)
%function plot_params = initialize_plot_params(varargin)
%
% Purpose of this function is to initialize the default parameters for
% plots to make them more readable. You may need to modify these values to
% make it look good on your machine. Default takes no inputs, optionally can change defaults. 
%
%
% Created August 20, 2018
% Robert W. Heath Jr.
    plotParams.LineWidth = 3;
    plotParams.MarkerSize = 8;
    plotParams.FontSize = 14;
    plotParams.offset = -0.05;

    % Make adjustments to default values
    for k=1:nargin/2
        if ischar(varargin{2*k})
            plotParams.(varargin{2*k-1}) = num2str(varargin{2*k});
        else
            plotParams.(varargin{2*k-1}) = varargin{2*k};
        end %if
    end %k   
end 
