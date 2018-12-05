% perspective grid
r = 0:0.01:1;
p = r';
grid = p.*(1-1./r) + (1-p).*(1-1./(1-r));