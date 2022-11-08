function Dm = BernsteinDifferentiationMatrix(N,T)
% derivative of a Bezier curve
% INPUT
% N: order of the curve
% T: tf-t0
% OUTPUT
% Dm: differentiation matrix for Bernstein polynomials of order N 

% HOW TO USE:
% If Cp are the control points of the Bernstein polyomial, then the control points
% its derivative are Cpdot = Cp*Dm
% NOTE: Cpdot are control points of a Bernstein poly of order N-1. To
% obtain Cpdot of order N, degree elevation must be performed, i.e. Cpdot =
% Cp*Dm*DegElevMatrix(N-1,N)


Dm = -[N/T*eye(N); zeros(1,N)]+[zeros(1,N);N/T*eye(N)];

end
