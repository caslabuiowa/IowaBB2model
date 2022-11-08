function  poly_t  = BernsteinPoly(Cp,t,t0,tf)

% INPUTS:
% Cp is a matrix n by N+1 (n: dimension of polynomial, N: order of polynomial) 
% t is a time vector
% OUTPUT:
% poly_t: n-dimensional polynomial evaluated at each time t

% if t is a scalar, it returns the value of Bernstein Poly at t in [t0,tf]
% if t0 and tf are not provided, it returns the value of Bernstein Poly at t in [0,1]

% Written by: Venanzio Cichella       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



[~, N] = size(Cp);
N = N-1;

if length(t) > 1
    B = BernsteinMatrix_a2b(N,t)';
    poly_t = Cp*B;
else
    if ~exist('t0','var')
        B = BernsteinMatrix_a2b(N,t)';
        poly_t = Cp*B;
    else
        B = BernsteinMatrix_a2b(N,t,t0,tf)';
        poly_t = Cp*B;
    end
end


end

