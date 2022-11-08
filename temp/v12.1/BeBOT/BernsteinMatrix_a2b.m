function b = BernsteinMatrix_a2b(N, t, tmin, tmax)

% Inputs: order N, time vector t = [t0 ... tm], no need for tmin and tmax.
% Output: b = [b0N(t0) b1N(t0) ... bNN(t0);
%              b0N(t1) b1N(t1) ... bNN(t1);
%              ...
%              b0N(tm) b1N(tm) ... bNN(tm);
% Use: If Cp is a row vector of N+1 control points,
%       the Nth order Bezier curve is given by xN=Cp*b';
% This function is used in BernsteinPoly

% Alternatively
% Inputs: order n, scalar time t', tmin and tmax
% Output: b = [b0n(t') b1n(t') ... bnn(t')]
% Use: If Cp is a row vector of N+1 control points,
%       the Nth order Bezier curve evaluated at t' is given by xn=Cp*b';
% Comment: This is more efficient but not as robust as de Casteljau
%           It works best for low-order curves

% Written by: Venanzio Cichella       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if length(t) > 1
    tmax = t(length(t));
    tmin = t(1);
end

if ~exist('tmin','var')
    tmin = 0; tmax = 1;
end



% compute B(j+1) = binomial(n, j), j = 0..n
t = t';
B = ones(N+1, 1); 
for j = 1:ceil(N/2)
  B(j+1) = B(j)*(N+1-j)/j;
  B(N+1-j) = B(j+1);
end
% compute T(i, j) = (t(i)-tmin)^j, TT(i, j) = (tmax-t(i))^(N-j)
T = ones(length(t), N+1);
TT = ones(length(t), N+1);
% turn a row t into a column t so that 
% we can do diag(t)*T(:,j) by t.*T(:,j)
tp = reshape(t, length(t), 1)-tmin;
ttp = tmax - t;
% Compute binomial(N, j)*(t(i)-tmin)^j*(tmax-t(i))^(N-j)
for j = 1:N 
  T(:, j+1) = tp .* T(:, j); 
  T(:, j) = T(:, j) .* B(j);
 TT(:,N+1-j) = ttp .* TT(:,N+2-j);
end

% Compute binomial(N, j)*(t(i)-tmin)^j*(tmax-t(i))^(N-j)/((tmax-tmin)^N)
b =  T.*TT./((tmax-tmin)^N);

end
