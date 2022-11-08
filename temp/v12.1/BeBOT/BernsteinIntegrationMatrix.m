function I = BernsteinIntegrationMatrix(N,T)

% Let xdot be a Bernstein polynomial with control points xndot (raw vector)
% The control points of x are xn = xndot*I


A = T/(N+1)*ones(N+2,N+2);
B = tril(A,-1);
I = B(:,1:end-1)';

end

