function [dist, t1, t2] = MinDistBernstein2Bernstein(cpts1, cpts2, varargin)
%BEZ2BEZ Finds the shortest distance between two Bezier curves
%   INPUTS
%   cpts1: Dx(N+1) Dth dimensional array of N+1 control points defining the
%       first Nth order curve.
%   cpts2: See cpts1, should also be Dx(N+1)
%   epsilon: Optional parameter, desired tolerance to meet. Default is 1e-6
%
%   OUTPUTS
%   dist: Minimum distance between the two curves
%   t1: t value at which the minimum distance happens on the first curve.
%       Note that both values of t will be on the range [0, 1]
%   t2: See t1

% Written by Calvin Kielas-Jensen

[m,n] = size(cpts1);
if m == 2
    cpts1 = [cpts1;zeros(1,n)];
end
[m,n] = size(cpts2);
if m == 2
    cpts2 = [cpts2;zeros(1,n)];
end

% --- Input parsing
p = inputParser;

addParameter(p, 'epsilon', 1e-6, @isnumeric)

parse(p, varargin{:})
epsilon = p.Results.epsilon;
% --- End input parsing

% % This rounding is necessary to avoid rounding error problems
% cpts1 = round(cpts1 / 1e-12)*1e-12;
% cpts2 = round(cpts2 / 1e-12)*1e-12;

alpha = inf;
deg1 = size(cpts1, 2) - 1;
deg2 = size(cpts2, 2) - 1;

[dist, t1, t2, err] = bern2bernR(cpts1, cpts2, alpha, deg1, deg2, epsilon,...
                          0, 1, 0, 1, 0);

if err.maxiter
    warning('Maximum iterations met.')
end

end




















function [alpha, t1, t2, error] = bern2bernR(cpts1, cpts2, alpha, deg1, ...
    deg2, epsilon, t1L, t1H, t2L, t2H, count)
%bern2bernR Recursive call for bern2bernR
%   Detailed explanation goes here

error.maxiter = false;

% Compute the upper and lower bounds
[ub, t1local, t2local] = upper_bound(cpts1, cpts2);
[lb, ~, ~, simplex] = gjk(cpts1, cpts2);

% Maximum iteration check
count = count + 1;
if count > 1000
%     alpha = -1;
%     t1 = -1;
%     t2 = -1;
    t1 = 0.5*(t1L + t1H);
    t2 = 0.5*(t2L + t2H);
%     warning('B2BR: Maximum number of iterations met.')
    error.maxiter = true;
    return
end

if ub < alpha
    alpha = ub;
    t1 = (1-t1local)*t1L + t1local*t1H;
    t2 = (1-t2local)*t2L + t2local*t2H; 
else
    t1 = -1;
    t2 = -1;
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
%         try
        idx1(i) = find(all(bsxfun(approx, cpts1, vertices{i}(:, 1)), 1), 1)-1;
        idx2(i) = find(all(bsxfun(approx, cpts2, vertices{i}(:, 2)), 1), 1)-1;
%         catch
%             disp('here')
%         end
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
    
%     % These assertions will sometimes fail due to rounding error making
%     % 1.00000000000 greater than 1
%     assert(t1div <= 1 && t2div <= 1, 'tdiv is greater than 1')
%     assert(t1div >= 0 && t2div >= 0, 'tdiv is less than 0')
    
else
    % If there was a collision, divide at 0.5
    t1div = 0.5;
    t2div = 0.5;
    
end

% if lb > ub+10000*eps
%     disp('lb > ub, probably a problem')
% end

% if lb >= alpha*(1-epsilon) % Relative tolerance
if lb >= alpha - epsilon % Absolute tolerance
    return
    
else
   
   if count > 10
       t1div = 0.5;
       t2div = 0.5;
   end
    
   % Split the curves
   cptsP = deCasteljau(cpts1, t1div);
   cptsPA = cptsP(:, 1:deg1+1);
   cptsPB = cptsP(:, deg1+1:end);
   cptsQ = deCasteljau(cpts2, t2div);
   cptsQA = cptsQ(:, 1:deg2+1);
   cptsQB = cptsQ(:, deg2+1:end);

   t1len = t1H - t1L;
   t2len = t2H - t2L;



   % Recursively call and keep the minimum value along with its
   % corresponding t values
   [newAlpha, newT1, newT2, newErr] = bern2bernR(cptsPA, cptsQA, alpha, ...
                                   deg1, deg2, epsilon, ...
                                   t1L, t1L + t1div*t1len, ...
                                   t2L, t2L + t2div*t2len, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t1 = newT1;
       t2 = newT2;
       error = newErr;
   end

   [newAlpha, newT1, newT2, newErr] = bern2bernR(cptsPA, cptsQB, alpha, ...
                                   deg1, deg2, epsilon, ...
                                   t1L, t1L + t1div*t1len, ...
                                   t2L + t2div*t2len, t2H, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t1 = newT1;
       t2 = newT2;
       error = newErr;
   end

   [newAlpha, newT1, newT2, newErr] = bern2bernR(cptsPB, cptsQA, alpha, ...
                                   deg1, deg2, epsilon, ...
                                   t1L + t1div*t1len, t1H, ...
                                   t2L, t2L + t2div*t2len, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t1 = newT1;
       t2 = newT2;
       error = newErr;
   end

   [newAlpha, newT1, newT2, newErr] = bern2bernR(cptsPB, cptsQB, alpha, ...
                                   deg1, deg2, epsilon, ...
                                   t1L + t1div*t1len, t1H, ...
                                   t2L + t2div*t2len, t2H, count);
   if newAlpha < alpha
       alpha = newAlpha;
       t1 = newT1;
       t2 = newT2;
       error = newErr;
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