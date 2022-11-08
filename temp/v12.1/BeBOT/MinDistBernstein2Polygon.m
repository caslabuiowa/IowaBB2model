function [dist, t, pt] = MinDistBernstein2Polygon(cpts, poly, varargin)
%BEZ2POLY Finds the minimum distance between a Bezier curve and a polytope
%   INPUTS
%   cpts: Dx(N+1) Dth dimensional array of N+1 control points defining the
%       first Nth order curve.
%   poly: DxM Dth dimensional array of M vertices defining a polygon.
%   epsilon: Optional parameter, desired tolerance to meet. Default is 1e-6
%
%   OUTPUTS
%   dist: Minimum distance between the two curves
%   t: t value at which the minimum distance happens on the curve.
%       Note that t will be on the range [0, 1]
%   pt: Point at which the minimum distance happens on the polytope

% Written by Calvin Kielas-Jensen

[m,n] = size(cpts);
if m == 2
    cpts = [cpts;zeros(1,n)];
end
[m,n] = size(poly);
if m == 2
    poly = [poly;zeros(1,n)];
end

% --- Input parsing
p = inputParser;

addParameter(p, 'epsilon', 1e-6, @isnumeric)

parse(p, varargin{:})
epsilon = p.Results.epsilon;
% --- End input parsing

alpha = inf;
deg = size(cpts, 2) - 1;

[dist, t, pt] = bern2polyR(cpts, poly, alpha, deg, epsilon, 0, 1, 0);
end





















function [alpha, t, pt] = bern2polyR(cpts, poly, alpha, deg, epsilon, ...
    tL, tH, count)
%bern2polyR Recursive call for bern2polyR
%   

% Compute the upper and lower bounds
[ub, tlocal, pt] = upper_bound_poly(cpts, poly);
[lb, ~, ~, simplex] = gjk(cpts, poly);

% Maximum iteration check
count = count + 1;
if count > 1000
%     alpha = -1;
%     t = -1;
%     pt = -1;
    t = 0.5*(tH + tL);
    warning('B2PR: Maximum number of iterations met.')
    return
end

if ub < alpha
    alpha = ub;
    t = (1-tlocal)*tL + tlocal*tH;
else
    t = -1;
    pt = -1;
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
    idx = zeros(1, simplex.len);
    for i = 1:simplex.len
        idx(i) = find(all(bsxfun(approx, cpts, vertices{i}(:, 1)), 1), 1)-1;
    end

    % Find the point at which to split the curves
    if sum(baryVals) > 1
        tdiv = 0.5;
    else
        % By finding a good place to split, we significantly speed up the
        % convergence time
        tdiv = sum(idx.*baryVals / deg);
        if (tdiv == 0) || (tdiv == 1)
            tdiv = 0.5;
        end
    end
    
else
    % If there was a collision, divide at 0.5
    tdiv = 0.5;
    
end

% if lb >= alpha*(1-epsilon) % Relative tolerance
if lb >= alpha - epsilon % Absolute tolerance
    return
    
else
   % Split the curve
   cptsP = deCasteljau(cpts, tdiv);
   cptsPA = cptsP(:, 1:deg+1);
   cptsPB = cptsP(:, deg+1:end);
   
   tlen = tH - tL;
   
   % Recursively call and keep the minimum value along with its
   % corresponding t values
   [newAlpha, newT, newPt] = bern2polyR(cptsPA, poly, alpha, deg, ...
                                    epsilon, tL, tL + tdiv*tlen, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t = newT;
       pt = newPt;
   end
   
   [newAlpha, newT, newPt] = bern2polyR(cptsPB, poly, alpha, deg, ...
                                    epsilon, tL + tdiv*tlen, tH, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t = newT;
       pt = newPt;
   end
   
end

end




















function [ub, t, pt] = upper_bound_poly(cpts, poly)
%UPPER_BOUND_POLY Finds the upper bound on the distance between a Bezier
%   curve and a polytope.
%
%   Detailed explanation goes here

endpts = cpts(:, [1, end]);

[d1, ~, p1] = gjk(endpts(:, 1), poly);
[d2, ~, p2] = gjk(endpts(:, 2), poly);

if d1 < d2
    t = 0;
    pt = p1;
    ub = d1;
else
    t = 1;
    pt = p2;
    ub = d2;
end

end
