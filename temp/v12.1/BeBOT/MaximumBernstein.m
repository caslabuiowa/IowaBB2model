function [dist, t] = MaximumBernstein(ctrl_pt,tol)

% This needs to be improved

if ~exist('tol','var')
     % third parameter does not exist, so default it 
      tol = 0.0000001;
end

N = length(ctrl_pt)-1;

cpts = [ctrl_pt; linspace(0,1,N+1);zeros(1,N+1)];

max_cpt = max(ctrl_pt);

poly = [max_cpt*ones(1,N+1); linspace(0,1,N+1);zeros(1,N+1)];

[dist, t, ~] = MinDistBernstein2Bernstein(cpts, poly, 'epsilon', tol);

dist = max_cpt - dist;


end

