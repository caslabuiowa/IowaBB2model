function [tnodes,w,Dm] = BeBOT(N,T)
% derivative of a Bezier curve
% INPUT
% N: order of the curve
% T: tf-t0
% OUTPUT
% tnodes: equidistant time nodes
% w: integration weights
% Dm: differentiation matrix for Bernstein polynomials of order N 

% HOW TO USE:
% If Cp are the control points of the Bernstein polyomial (horizontal
% vector), then the integral from t0 to tf is Cp*w;
% If Cp are the control points of the Bernstein polyomial (horizontal vector), then the control points
% its derivative are Cpdot = Cp*Dm
% NOTE: Cpdot are control points of a Bernstein poly of order N. In order words, 
% degree elevation is performed on Dm

tnodes = linspace(0,T,N+1);
w = T/(N+1)*ones(N+1,1);
Dm = BernsteinDifferentiationMatrix(N,T)*DegElevMatrix(N-1,N);


end







