function collision = CollCheckBernstein2Bernstein(cpts1, cpts2, minDist, ...
                                          varargin)
%COLLCHECKBEZ Quickly checks for a collision between two Bezier curves
%   INPUTS
%   cpts1: Dx(N+1) Dth dimensional array of N+1 control points defining the
%       first Nth order curve.
%   cpts2: See cpts1, should also be Dx(N+1)
%   epsilon: Optional parameter, desired tolerance to meet. Default is 1e-6
%
%   OUTPUTS
%   collision: Boolean value where false means the curve ans polygon are at
%       least minDist appart. True means that a collision within epsilon
%       has been found.
%   dist: Minimum distance. Note that the true minimum distance may be
%       greater than this but this value is a conservative estimate.  


% Written by Calvin Kielas-Jensen

% --- Input parsing
p = inputParser;

addParameter(p, 'epsilon', 1e-6, @isnumeric)

parse(p, varargin{:})
epsilon = p.Results.epsilon;
% --- End input parsing

alpha = inf;
deg1 = size(cpts1, 2) - 1;
deg2 = size(cpts2, 2) - 1;

[dist, collision] = collCheckBernR(cpts1, cpts2, alpha, deg1, ...
                                deg2, epsilon, minDist, 0);
end



















function [alpha, collision] = collCheckBernR(cpts1, cpts2, alpha,...
    deg1, deg2, epsilon, minDist, count)
%collCheckBernR Recursive call for collCheckBernR
%   

% Maximum iteration check
count = count + 1;
if count > 1000
    alpha = -1;
    warning('Maximum number of iterations met.')
    return
end

collision = true;

% Compute the upper and lower bounds
[ub, ~, ~] = upper_bound(cpts1, cpts2);
[lb, ~, ~, simplex] = gjk(cpts1, cpts2);

if ub < alpha
    alpha = ub;
end

if lb > minDist
    collision = false;
    alpha = lb;
    return
end

if lb > 0
    % Convert the struct to a cell array
    vertices = cell(1, simplex.len);
    baryVals = zeros(1, simplex.len);
    if simplex.len >= 1
        vertices{1} = simplex.Apts;
        baryVals(1) = simplex.Au;
    end
    if simplex.len >= 2
        vertices{2} = simplex.Bpts;
        baryVals(2) = simplex.Bu;
    end
    if simplex.len >= 3
        vertices{3} = simplex.Cpts;
        baryVals(3) = simplex.Cu;
    end
    if simplex.len >= 4
        vertices{4} = simplex.Dpts;
        % There should not be a Du value since that would be for a 4D shape
    end

    % Find the index of where the simplex vertices are in cpts
    approx = @(x, y) abs(x-y) < 10000*eps; 
    idx1 = zeros(1, simplex.len);
    idx2 = zeros(1, simplex.len);
    for i = 1:simplex.len
        idx1(i) = find(all(bsxfun(approx, cpts1, vertices{i}(:, 1)), 1), 1)-1;
        idx2(i) = find(all(bsxfun(approx, cpts2, vertices{i}(:, 2)), 1), 1)-1;
    end

    % Find the point at which to split the curves
    if sum(baryVals) > 1
        t1div = 0.5;
        t2div = 0.5;
    else
        % By finding a good place to split, we significantly speed up the
        % convergence time (in one example it was 1.3s vs 0.064s)
        t1div = sum(idx1.*baryVals / deg1);
        t2div = sum(idx2.*baryVals / deg2);
    end
    
else
    % If there was a collision, divide at 0.5
    t1div = 0.5;
    t2div = 0.5;
    
end

% if lb >= alpha*(1-epsilon) % Relative tolerance
if lb >= alpha - epsilon % Absolute tolerance
    return
    
else
   % Split the curves
   cptsP = deCasteljau(cpts1, t1div);
   cptsPA = cptsP(:, 1:deg1+1);
   cptsPB = cptsP(:, deg1+1:end);
   cptsQ = deCasteljau(cpts2, t2div);
   cptsQA = cptsQ(:, 1:deg2+1);
   cptsQB = cptsQ(:, deg2+1:end);
   
   % Recursively call and keep the minimum value along with its
   % corresponding t values
   [newAlpha, newCol] = collCheckBernR(cptsPA, cptsQA, alpha, deg1,...
                                   deg2, epsilon, minDist, count);
   if newAlpha < alpha
       alpha = newAlpha;
       collision = newCol;
   end
   
   [newAlpha, newCol] = collCheckBernR(cptsPA, cptsQB, alpha, deg1,...
                                   deg2, epsilon, minDist, count);
   if newAlpha < alpha
       alpha = newAlpha;
       collision = newCol;
   end
   
   [newAlpha, newCol] = collCheckBernR(cptsPB, cptsQA, alpha, deg1,...
                                   deg2, epsilon, minDist, count);
   if newAlpha < alpha
       alpha = newAlpha;
       collision = newCol;
   end
   
   [newAlpha, newCol] = collCheckBernR(cptsPB, cptsQB, alpha, deg1,...
                                   deg2, epsilon, minDist, count);
   if newAlpha < alpha
       alpha = newAlpha;
       collision = newCol;
   end
   
   if alpha > minDist
       collision = false;
   end
   
end

end




















function [ub, t1, t2] = upper_bound(cpts1, cpts2)
%UPPER_BOUND Finds the upper bound of the minimum distance between two
%Bezier curves
%   Detailed explanation goes here

tvals = [1, 1;
         1, 2;
         2, 1;
         2, 2];
endpts1 = cpts1(:, [1, end]);
endpts2 = cpts2(:, [1, end]);

distances = zeros(1, 4);
for i = 1:4
    distances(i) = norm(endpts1(:, tvals(i, 1)) - endpts2(:, tvals(i, 2)));
end

[ub, idx] = min(distances);
t1 = tvals(idx, 1)-1;
t2 = tvals(idx, 2)-1;

end
