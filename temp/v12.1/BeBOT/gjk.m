function [dist, pt1, pt2, simplex] = gjk(shape1, shape2, varargin)
%GJK Efficiently finds the minimum distance between two shapes
%   [dist, pt1, pt2] = gjk(shape1, shape2)
%   [dist, pt1, pt2] = gjk(shape1, shape2, 'MaxIter', maxiter)
%
%   University of Iowa - Cooperative Autonomous Systems (CAS) Laboratory
%   AUTHOR: Calvin Kielas-Jensen - ckielasjensen@uiowa.edu
%   Last Updated: 8/12/2019
%
%   This algorithm was originally developed by Gilbert-Johnson-Keerthi in
%   their paper "A fast procedure for computing the distance between
%   complex objects in three-dimensional space".
%
%   The algorithm builds on a few simple concepts. First, the Minkowski
%   difference, which is the difference between all the points of each
%   shape, can be used to determine whether a collision exists or what the
%   minimum distance is between two shapes. If the Minkowski difference
%   encloses the origin, then we know that a collision exists. Otherwise,
%   the minimum distance between the convex hull of the Minkowski
%   difference and the origin is equal to the minimum distance between the
%   shapes.
%
%   Next, the support function is a function that returns the point in the
%   furthest direction on a convex shape. Since this algorithm only needs a
%   point in a direction, the support function can be modified to handle
%   any type of convex shape (although polygons are the most common).
%
%   The simplex is a subset of the Minkowski difference. This is useful
%   because it means that we do not have to compute the entire Minkowski
%   difference, we only need to build the simplex.
%
%   The GJK algorithm iteratively tries to build a simplex which will
%   enclose the origin.
%
%   INPUTS
%   shape1: N dimensional shape in which to determine the minimum
%       distance/collision with the second shape. This shape can be any
%       arbitrary object as long as it works properly with the support
%       function.
%
%   shape2: Second of the two shapes. See shape1.
%
%   maxiter: Optional value signifying the maximum number of iterations the
%       algorithm attempts before giving up. Default value is 256.
%
%   OUTPUTS
%   dist: Minimum distance between the two convex shapes. Note that if a
%   non-convex shape is used, the minimum distance between the convex hull
%   of the shapes will be found instead.
%
%   pt1: Point at which the minimum distance occurs on shape 1.
%
%   pt2: Point at which the minimum distance occurs on shape 2.
%   
%   simplex: Struct containing 1 to 4 points which are a subset of the
%       Minkowski difference. For more information see dosimplex.

% --- Input parsing
p = inputParser;

addParameter(p, 'maxiter', 256, @isnumeric)

parse(p, varargin{:})
maxIter = p.Results.maxiter;
% --- End input parsing

% This rounding is necessary to avoid rounding error problems
shape1 = round(shape1 / 1e-12)*1e-12;
shape2 = round(shape2 / 1e-12)*1e-12;

% Verify both shapes are the same dimension
[ndim, ~] = size(shape1);
[ndim2, ~] = size(shape2);
assert(ndim == ndim2, 'Shape 1 and Shape 2 need to be the same dimension.')
assert((ndim == 2) || (ndim == 3), 'Shapes can only be 2D or 3D.')

% If the shapes are 2D, zero pad to 3D
if ndim == 2
    shape1(3, :) = 0;
    shape2(3, :) = 0;
end

simplex = struct('len', 0, ...);%, 'dir', shape1(:, 1) - shape2(:, 1), ...
                 'collision', false);

% Loop until we 
for iter = 1:maxIter
    oldSimplex = simplex;
    simplex = dosimplex(simplex, shape1, shape2);
    
    % Check termination conditions: collision, repeated point, or the
    % newest point added to the simplex does not cross the origin
    if simplex.collision
        break
    elseif (simplex.len > 1) && all(simplex.A == simplex.B)
        break
    elseif (simplex.len > 2) && all(simplex.A == simplex.C)
        break
    elseif (simplex.len > 3) && all(simplex.A == simplex.D)
        break
    elseif dot(simplex.A, simplex.dir) < 0
        break
    elseif isequal(oldSimplex, simplex)
        break
    end
end

if iter == maxIter
    warning('[!] Maximum number of iterations met')
end

if simplex.collision
    dist = 0;
    pt1 = zeros(1, ndim);
    pt2 = zeros(1, ndim);
else
    [dist, pt1, pt2, simplex] = minimumdist(simplex, shape1, shape2, 100);
end

end



















function simplex = dosimplex(simplex, shape1, shape2)
%DOSIMPLEX Builds the simplex
%   Adds or removes a point from the simplex. This function is used as a
%   wrapper for the simplex1, 2, 3, and 4 functions.
%
%   INPUTS
%   simplex: Struct containing points from the Minkowski difference. The
%       struct has 3 required parameters and several optional parameters:
%           * simplex.len - Number of points in the simplex. Should be some
%             value between 0 and 4. Required.
%           * simplex.dir - N dimensional vector signifying the direction
%             of the current support search. If no direction has been
%             created, it can be an arbitrary direction. Required.
%           * simplex.collision - Boolean value signifying whether a
%             collision has occured. Required.
%           * simplex.A - Vertex on the simplex. A will always be the most
%             recently added vertex.
%           * simplex.Au - Barycentric weight for a point on the line AB or
%             on the plane ABC
%           * simplex.Apts - Nx2 matrix containing the point from shape 1
%             and the point from shape 2 used to create simplex.A.
%           * simplex.B, C, D - See simplex.A. Note that simplex.B, C, D
%             will be sorted arbitrarily (i.e. C is not guaranteed to be
%             the least recently added point to the simplex ABC).
%           * simplex.Bu, Cu, Du - See simplex.Au
%           * simplex.Bpts, Cpts, Dpts - See simplex.Apts
%
%   shape1: N dimensional shape in which to determine the minimum
%       distance/collision with the second shape. This shape can be any
%       arbitrary object as long as it works properly with the support
%       function.
%
%   shape2: Second of the two shapes. See shape1.
%
%   OUTPUTS
%   simplex: See simplex in INPUT.

switch simplex.len
    case 0
%         pt1 = support(shape1, simplex.dir);
%         pt2 = support(shape2, -simplex.dir);
%         
%         simplex.Apts = [pt1, pt2];
%         simplex.A = pt1 - pt2;

%         simplex.Au = 1;
%         [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
%         simplex.len = 1;

        simplex.Au = 1;
        simplex.Apts = [shape1(:, 1), shape2(:, 1)];
        simplex.A = shape1(:, 1) - shape2(:, 1);
        simplex.dir = simplex.A;
        simplex.len = 1;
        
    case 1
        simplex = simplex1(simplex, shape1, shape2);
        
    case 2
        simplex = simplex2(simplex, shape1, shape2);
        
    case 3
        simplex = simplex3(simplex, shape1, shape2);
        
    case 4
        simplex = simplex4(simplex, shape1, shape2);
        
    otherwise
        error('The simplex should only have between 0 and 4 points')
end

end



















function [dist, pt1, pt2, simplex] = minimumdist(simplex, shape1, shape2, maxIter)
%MINIMUMDIST Finds the minimum distance between shapes 1 and 2
%   [dist, pt1, pt2] = minimumdist(simplex, shape1, shape2, maxIter)
%
%   The minimum distance is found by continuing to evolve the simplex after
%   a termination condition has already been met. Once a repeated vertex is
%   added to the simplex, we know that our simplex is the closest it can be
%   to the origin.
%
%   INPUTS
%   simplex: Struct containing points from the Minkowski difference. The
%       struct has 3 required parameters and several optional parameters:
%           * simplex.len - Number of points in the simplex. Should be some
%             value between 0 and 4. Required.
%           * simplex.dir - N dimensional vector signifying the direction
%             of the current support search. If no direction has been
%             created, it can be an arbitrary direction. Required.
%           * simplex.collision - Boolean value signifying whether a
%             collision has occured. Required.
%           * simplex.A - Vertex on the simplex. A will always be the most
%             recently added vertex.
%           * simplex.Au - Barycentric weight for a point on the line AB or
%             on the plane ABC
%           * simplex.Apts - Nx2 matrix containing the point from shape 1
%             and the point from shape 2 used to create simplex.A.
%           * simplex.B, C, D - See simplex.A. Note that simplex.B, C, D
%             will be sorted arbitrarily (i.e. C is not guaranteed to be
%             the least recently added point to the simplex ABC).
%           * simplex.Bu, Cu, Du - See simplex.Au
%           * simplex.Bpts, Cpts, Dpts - See simplex.Apts
%
%   shape1: N dimensional shape in which to determine the minimum
%       distance/collision with the second shape. This shape can be any
%       arbitrary object as long as it works properly with the support
%       function.
%
%   shape2: Second of the two shapes. See shape1.
%
%   maxIter: Maximum number of iterations to evolve the simplex.
%
%   OUTPUTS
%   dist: Minimum Euclidean distance between shape 1 and shape 2.
%
%   pt1: Point at which the minimum distance occurs on shape 1.
%
%   pt2: Point at which the minimum distance occurs on shape 2.

% firstRound = false;
simplex.converged = false;
% Loop until we add a repeated point
for i = 1:maxIter
%     oldA = simplex.A;
    oldSimplex = simplex;
    simplex = dosimplex(simplex, shape1, shape2);
        
    if (simplex.len > 1) && all(abs(simplex.A-simplex.B) < 1000*eps)
        simplex.Apts = simplex.Bpts;
        simplex.Au = simplex.Bu;
        simplex.A = simplex.B;
        
        if simplex.len == 3
            simplex.Bpts = simplex.Cpts;
            simplex.Bu = simplex.Cu;
            simplex.B = simplex.C;
            
        elseif simplex.len == 4
            simplex.Bpts = simplex.Dpts;
            simplex.Bu = simplex.Du;
            simplex.B = simplex.D;
        end
        
        % By subtracting 1 from the length, we effectively remove the
        % alphabetically last point from the simplex (e.g. len==3, we
        % remove C)
        simplex.len = simplex.len - 1;
        break
        
    elseif (simplex.len > 2) && all(abs(simplex.A-simplex.C) < 1000*eps)
        simplex.Apts = simplex.Cpts;
        simplex.Au = simplex.Cu;
        simplex.A = simplex.C;
        
        if simplex.len == 4
            simplex.Cpts = simplex.Dpts;
            simplex.Cu = simplex.Du;
            simplex.C = simplex.D;
        end
        
        simplex.len = simplex.len - 1;
        break
        
    elseif (simplex.len > 3) && all(abs(simplex.A-simplex.D) < 1000*eps)
        simplex.Apts = simplex.Dpts;
        simplex.Au = simplex.Du;
        simplex.A = simplex.D;
        
        simplex.len = simplex.len - 1;
        break
    
    elseif simplex.converged
        break
        
    elseif isequal(oldSimplex, simplex)
        break
        
%     elseif all(simplex.A == oldA)
%         if firstRound
%             break
%         else
%             firstRound = true;
%         end

    end
end

if i == maxIter
    warning('[!] Maximum number of iterations in minimum distance met.')
end

if simplex.collision
    dist = 0;
    pt1 = zeros(1, size(shape1, 1));
    pt2 = zeros(1, size(shape2, 1));
else

    switch simplex.len
        case 1
            pt1 = simplex.Apts(:, 1);
            pt2 = simplex.Apts(:, 2);

        case 2
%             [~, t] = dist2line(simplex.A, simplex.B);
%             Au = 1-t;
%             Bu = t;
%             pt1 = Au*simplex.Apts(:,1) + Bu*simplex.Bpts(:,1);
%             pt2 = Au*simplex.Apts(:,2) + Bu*simplex.Bpts(:,2);

            pt1 = simplex.Au*simplex.Apts(:,1) + simplex.Bu*simplex.Bpts(:,1);
            pt2 = simplex.Au*simplex.Apts(:,2) + simplex.Bu*simplex.Bpts(:,2);

        case 3
            pt1 = simplex.Au*simplex.Apts(:, 1) + ...
                  simplex.Bu*simplex.Bpts(:, 1) + ...
                  simplex.Cu*simplex.Cpts(:, 1);
            pt2 = simplex.Au*simplex.Apts(:, 2) + ...
                  simplex.Bu*simplex.Bpts(:, 2) + ...
                  simplex.Cu*simplex.Cpts(:, 2);

        otherwise
            error(['For minimum distance, the simplex should only have ', ...
                   'between 1 and 3 points'])

    end

    dist = norm(pt1 - pt2);
    
end

end



















function simplex = simplex1(simplex, shape1, shape2)
%SIMPLEX1 Adds a point to a 1 point simplex
%   simplex = simplex1(simplex, shape1, shape2)
%
%   Adding a point to a 1 point simplex is done by simply adding the
%   support point in the opposite direction. This guarantees that the
%   origin will be crossed by the Minkowski difference if there is an
%   intersection.
%
%   For input and output descriptions, see dosimplex.

simplex.Bpts = simplex.Apts;
simplex.Au = 0.5;
simplex.Bu = 0.5;
simplex.B = simplex.A;
simplex.dir = -simplex.dir;
simplex.len = 2;

[simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);

end



















function simplex = simplex2(simplex, shape1, shape2)
%SIMPLEX2 Adds a new point to a 2 point simplex.
%   simplex = simplex2(simplex, shape1, shape2)
%
%   Let AB be the line between the two points in the simplex. This function
%   finds a point on the line AB whose vector is normal to the origin. Note
%   that it is assumed that the normal vector lies on the line AB and not
%   outside of AB because a check is performed after adding the second
%   point to the simplex that guarantees this.
%
%   For input and output descriptions, see dosimplex.

if all(abs(simplex.A - simplex.B) < 100*eps)
    simplex.dir = -simplex.A;
%     simplex.len = 1;
    simplex.Au = 1;
    simplex.Bu = 0;
    
else
    v = simplex.B - simplex.A;
    u = simplex.A;
%     t = -dot(v, u) / dot(v, v);
    t = -(v'*u) / (v'*v);

    % If t is out of the range [0, 1] we are closest to A or B
    if t > 1
        simplex.dir = -simplex.B;
%         simplex.Apts = simplex.Bpts;
%         simplex.Au = 1;
%         simplex.Bu = 0;
%         simplex.A = simplex.B;

%         simplex.len = 1;

        simplex.len = 2;
        [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
        
    elseif t < 0
        simplex.dir = -simplex.A;
        simplex.Bpts = simplex.Apts;
        simplex.B = simplex.A;
%         simplex.Au = 1;
%         simplex.Bu = 0;

%         simplex.len = 1;

        simplex.len = 2;
        [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
        
    else
        closestPt = (1-t)*simplex.A + t*simplex.B;

        % Barycentric coordinates, we set Cu instead of Au since A will be
        % replaced with the newest point
        simplex.Bu = t;
        simplex.Cu = 1 - t;

        simplex.dir = -closestPt;
        simplex.Cpts = simplex.Apts;
        simplex.C = simplex.A;

        simplex.len = 3;
        [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
        
%         % If the point that we add has not passed the origin and is also
%         % not closer to the origin, then we know the line is already the
%         % closest
%         if simplex.dir'*simplex.A < 0
%             if norm(simplex.A) > norm(simplex.B) || ...
%                     norm(simplex.A) > norm(simplex.C)
%                 simplex.Apts = simplex.Cpts;
%                 simplex.Au = simplex.Cu;
%                 simplex.A = simplex.C;
%     %             simplex.Bpts = simplex.Cpts;
%     %             simplex.Bu = simplex.Cu;
%     %             simplex.B = simplex.C;
%                 simplex.dir = simplex.A;
%                 simplex.len = 2;
%             end
%         end
    end
end

end





















function simplex = simplex3(simplex, shape1, shape2)
%SIMPLEX3 Evolves a 3 point simplex
%   A point can be added or removed from the 3 point simplex. By using
%   Voronoi regions, we can check whether the origin is outside of or
%   enclosed by the simplex. A point is added to create a tetrahedron if
%   the origin is found to be above or below the plane of the simplex. A
%   point is removed if the origin is found to be closest to a line (while
%   still on the plane of the simplex and not enclosed by it).
%
%   For input and output descriptions, see dosimplex.

% Name line vectors for clarity
A0 = -simplex.A;
AB = simplex.B - simplex.A;
AC = simplex.C - simplex.A;
BC = simplex.C - simplex.B;
ABC = cross(AB, AC);

% If the triangle area is zero, we have collinear points
if norm(ABC) < 10*eps
    simplex.converged = true;
    % Find the two points on the line that are furthest appart
    [~, idx] = max(vecnorm([AB, AC, BC], 2, 1));
    switch idx
        case 1 % AB
            Apts = simplex.Apts;
            A = simplex.A;
            Bpts = simplex.Bpts;
            B = simplex.B;
        case 2 % AC
            Apts = simplex.Apts;
            A = simplex.A;
            Bpts = simplex.Cpts;
            B = simplex.C;
        case 3 % BC
            Apts = simplex.Bpts;
            A = simplex.B;
            Bpts = simplex.Cpts;
            B = simplex.C;
    end
    
    % Perform the same min distance to a line calculation found in simplex2
    v = B - A;
    u = A;
    t = -(v'*u) / (v'*v);

    % If t is out of the range [0, 1] we are closest to A or B
    if t > 1
        simplex.dir = -B;
        simplex.Apts = Bpts;
        simplex.Au = 1;
        simplex.A = B;
        simplex.len = 1;
        
    elseif t < 0
        simplex.dir = -A;
        simplex.Apts = Apts;
        simplex.Au = 1;
        simplex.A = A;
        simplex.len = 1;
        
    else
        closestPt = (1-t)*A + t*B;

        % Barycentric coordinates, we set Cu instead of Au since A will be
        % replaced with the newest point
        simplex.Bu = 1 - t;
        simplex.Cu = t;

        simplex.dir = -closestPt;
        simplex.Bpts = Apts;
        simplex.B = A;
        simplex.Cpts = Bpts;
        simplex.C = B;

        simplex.len = 3;
        [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
        % Make sure the new point isn't collinear
        if all(cross(simplex.B-simplex.A, simplex.C-simplex.A) <= eps*10)
            simplex.Apts = simplex.Bpts;
            simplex.Au = simplex.Bu;
            simplex.A = simplex.B;
            simplex.Bpts = simplex.Cpts;
            simplex.Bu = simplex.Cu;
            simplex.B = simplex.C;
            simplex.len = 2;
            simplex.coverged = true;
        end
    end

% If origin is out of simplex and closest to A or AC
elseif A0'*cross(ABC, AC) > 0
    % If closest to line AC
    if A0'*AC > 0
        simplex.dir = cross(cross(AC, A0), AC);
        % Keep points A and C, replace B
        simplex.Bpts = simplex.Cpts;
        simplex.B = simplex.C;
        simplex.len = 2;
        
        simplex = simplex2(simplex, shape1, shape2);
       
    % Otherwise we are closest to A or AB
    else
        % If closest to AB
        if A0'*AB > 0
            simplex.dir = cross(cross(AB, A0), AB);
            % Keep points A and B, remove C
            simplex.len = 2;
            simplex = simplex2(simplex, shape1, shape2);
            
        % Otherwise we are closest to A
        else
            simplex.dir = simplex.A;
            simplex.len = 1;
        end
    end
    
% If closest to A or AB
elseif A0'*cross(AB, ABC) > 0
    % If closest to AB
%     if dot(AB, A0) > 0
    if AB'*A0 > 0
        simplex.dir = cross(cross(AB, A0), AB);
        % Keep points A and B, remove C
        simplex.len = 2;
        simplex = simplex2(simplex, shape1, shape2);
               
    % Otherwise we are closest to A
    else
        simplex.dir = simplex.A;
        simplex.len = 1;
    end
    
% Otherwise we are on, above, or below the ABC plane
else
    % If we are on the ABC plane, then there is a collision
    if all(abs(A0'*ABC) < 100*eps)
        simplex.collision = true ;
        
    else
        if A0'*ABC > 0
            simplex.dir = ABC;

            simplex.Dpts = simplex.Cpts;
            simplex.D = simplex.C;
            simplex.Cpts = simplex.Bpts;
            simplex.C = simplex.B;
            simplex.Bpts = simplex.Apts;
            simplex.B = simplex.A;

        else
            % If the origin is below the simplex, swap the points to make the
            % search direction positive in the normal direction
            simplex.dir = -ABC;

            simplex.Dpts = simplex.Bpts;
            simplex.D = simplex.B;
            simplex.Bpts = simplex.Apts;
            simplex.B = simplex.A;
        end
        
        % Find the barycentric center of the simplex BCD, we are avoiding A
        % since it will be the new point added below.
        P1 = simplex.B;
        P2 = simplex.C;
        P3 = simplex.D;
        
        u = P2 - P1;
        v = P3 - P1;
        w = - P1;
        n = cross(u, v);
        
        gamma = n'*cross(u, w) / sum(n.^2);
        beta = n'*cross(w, v) / sum(n.^2);
        alpha = 1 - beta - gamma;
        
        simplex.Bu = alpha;
        simplex.Cu = beta;
        simplex.Du = gamma;
        simplex.dir = -alpha*simplex.B - beta* simplex.C - gamma*simplex.D;
        
        simplex.len = 4;
        [simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);
        
        % If we just added one of the same points, simply return
        if all(simplex.A == simplex.B) || ...
           all(simplex.A == simplex.C) || ...
           all(simplex.A == simplex.D)
            
            return
       
        % Otherwise, see whether that new point is coplanar
        else
            % Test to see if the newest point is coplanar to the other 3
            vol = det( ...
                [simplex.A', 1;
                 simplex.B', 1;
                 simplex.C', 1;
                 simplex.D', 1]);

             % Use 10*eps instead of ==0 due to possible roundoff errors
             if vol <= 10*eps
                 simplex.Apts = simplex.Bpts;
                 simplex.Au = simplex.Bu;
                 simplex.A = simplex.B;
                 simplex.Bpts = simplex.Cpts;
                 simplex.Bu = simplex.Cu;
                 simplex.B = simplex.C;
                 simplex.Cpts = simplex.Dpts;
                 simplex.Cu = simplex.Du;
                 simplex.C = simplex.D;
                 simplex.len = 3;
                 simplex.converged = true;
             end
        end 
    end
end

end



















function simplex = simplex4(simplex, shape1, shape2)
%SIMPLEX4 Evolves a 4 point simplex
%   For a 4 point simplex, either the origin is enclosed (which means a
%   collision exists), the origin is closest to one of the three faces of
%   the tetrahedron (note that we ignore the "bottom" face because when we
%   added A to the simplex, we made sure it was added in the positive
%   direction), the origin is closest to one of the three edges (again
%   ignoring the "bottom" edges), or the origin is closest to A.
%
%   If we are closest to one of the faces, we remove the furthest point and
%   return a 3 point simplex. If we are closest to one of the edges, we
%   return a simplex with the two points that comprise that edge. If we are
%   closest to A, we simply return a size 1 simplex with the point A.
%
%   For input and output descriptions, see dosimplex.

% A0 = -simplex.A;
% B0 = -simplex.B;
AB = simplex.B - simplex.A;
AC = simplex.C - simplex.A;
AD = simplex.D - simplex.A;
BC = simplex.C - simplex.B;
BD = simplex.D - simplex.B;
CB = simplex.C - simplex.B;
DB = simplex.B - simplex.D;

% ABC = cross(AB, AC);
% ACD = cross(AC, AD);
% ADB = cross(AD, AB);
% BDC = cross(BD, BC);

% % Note that dots is logical, not numerical, since we only care about the
% % sign of the dot product
% dots = A0'*[ABC, ACD, ADB, BDC] > 0;
% 
% if sum(dots) == 0
%     simplex.collision = true;
%     return
% end

% Check to see if a point is the closest to the origin
[ptAB, tAB] = dist2line(simplex.A, simplex.B);
[ptAC, tAC] = dist2line(simplex.A, simplex.C);
[ptAD, tAD] = dist2line(simplex.A, simplex.D);
[ptBC, tBC] = dist2line(simplex.B, simplex.C);
[ptBD, tBD] = dist2line(simplex.B, simplex.D);
[ptCD, tCD] = dist2line(simplex.C, simplex.D);

% Closest to point A
if tAB == 0 && tAC == 0 && tAD == 0
    simplex.len = 1;
    simplex.dir = -simplex.A;
    return

% Closest to point B
elseif tAB == 1 && tBC == 0 && tBD == 0
    simplex.Apts = simplex.Bpts;
    simplex.Au = simplex.Bu;
    simplex.A = simplex.B;
    simplex.len = 1;
    simplex.dir = -simplex.A;
    return
    
% Closest to point C
elseif tAC == 1 && tBC == 1 && tCD == 0
    simplex.Apts = simplex.Cpts;
    simplex.Au = simplex.Cu;
    simplex.A = simplex.C;
    simplex.len = 1;
    simplex.dir = -simplex.A;
    return
    
% Closest to point D
elseif tAD == 1 && tBD == 1 && tCD == 1
    simplex.Apts = simplex.Dpts;
    simplex.Au = simplex.Du;
    simplex.A = simplex.D;
    simplex.len = 1;
    simplex.dir = -simplex.A;
    return
    
end
   
% Check to see if an edge is closest to the origin
[ptABC, abgABC] = dist2plane(simplex.A, simplex.B, simplex.C);
[ptACD, abgACD] = dist2plane(simplex.A, simplex.C, simplex.D);
[ptADB, abgADB] = dist2plane(simplex.A, simplex.D, simplex.B);
[ptBCD, abgBCD] = dist2plane(simplex.B, simplex.C, simplex.D);

% Closest to AB
if abgABC(3) < 0 && abgADB(2) < 0 && tAB > 0 && tAB < 1
    simplex.Au = 1-tAB;
    simplex.Bu = tAB;
    
    simplex.dir = -ptAB;
    simplex.len = 2;
    return

% Closest to AC
elseif abgABC(2) < 0 && abgACD(3) < 0 && tAC > 0 && tAC < 1
    simplex.Au = 1-tAC;
    simplex.Bu = tAC;
    
    simplex.Bpts = simplex.Cpts;
    simplex.B = simplex.C;
    
    simplex.dir = -ptAC;
    simplex.len = 2;
    return
    
% Closest to AD
elseif abgACD(2) < 0 && abgADB(3) < 0 && tAD > 0 && tAD < 1
    simplex.Au = 1-tAD;
    simplex.Bu = tAD;
    
    simplex.Bpts = simplex.Dpts;
    simplex.B = simplex.D;
    
    simplex.dir = -ptAD;
    simplex.len = 2;
    return
    
% Closest to BC
elseif abgABC(1) < 0 && abgBCD(3) < 0 && tBC > 0 && tBC < 1
    simplex.Au = 1-tBC;
    simplex.Bu = tBC;
    
    simplex.Apts = simplex.Bpts;
    simplex.A = simplex.B;
    simplex.Bpts = simplex.Cpts;
    simplex.B = simplex.C;
    
    simplex.dir = -ptBC;
    simplex.len = 2;
    return
    
% Closest to BD
elseif abgADB(1) < 0 && abgBCD(2) < 0 && tBD > 0 && tBD < 1
    simplex.Au = 1-tBD;
    simplex.Bu = tBD;
    
    simplex.Apts = simplex.Bpts;
    simplex.A = simplex.B;
    simplex.Bpts = simplex.Dpts;
    simplex.B = simplex.D;
    
    simplex.dir = -ptBD;
    simplex.len = 2;
    return
    
% Closest to CD
elseif abgACD(1) < 0 && abgBCD(1) < 0 && tCD > 0 && tCD < 1
    simplex.Au = 1-tCD;
    simplex.Bu = tCD;
    
    simplex.Apts = simplex.Cpts;
    simplex.A = simplex.C;
    simplex.Bpts = simplex.Dpts;
    simplex.B = simplex.D;
    
    simplex.dir = -ptCD;
    simplex.len = 2;
    return
    
end

% Barycentric coordinates to see which face we are closest to
% denom = AB'*cross(AC, AD);
denom = CB'*cross(AB, DB);
if denom == 0
    vol = 1;
else
    vol = 1/denom;
end
% uABCD = B0'*cross(BD, BC)*vol;
% vABCD = A0'*cross(AC, AD)*vol;
% wABCD = A0'*cross(AD, AB)*vol;
% xABCD = A0'*cross(AB, AC)*vol;
uABCD = simplex.C'*cross(simplex.D, simplex.B)*vol;
vABCD = simplex.C'*cross(simplex.A, simplex.D)*vol;
wABCD = simplex.D'*cross(simplex.A, simplex.B)*vol;
xABCD = simplex.B'*cross(simplex.A, simplex.C)*vol;

% % If the origin is within 3 or more planes, then it is enclosed by the
% % simplex (i.e. a collision has been found)
% if sum(all([abgABC; abgACD; abgADB; abgBCD] > 0, 2) .* ...
%         all([abgABC; abgACD; abgADB; abgBCD] < 1, 2)) > 2
%     
%     simplex.collision = true;
%     return

% Closest to ABC
if all(abgABC > 0) && all(abgABC < 1) && xABCD <= 0
    simplex.dir = -ptABC;
    simplex.Au = abgABC(1);
    simplex.Bu = abgABC(2);
    simplex.Cu = abgABC(3);
    lastVert = simplex.D;
    simplex = cullSimplex(simplex, 'D');
    
% Closest to BCD
elseif all(abgBCD > 0) && all(abgBCD < 1) && uABCD <=0
    simplex.dir = -ptBCD;
    simplex.Bu = abgBCD(1);
    simplex.Cu = abgBCD(2);
    simplex.Du = abgBCD(3);
    lastVert = simplex.A;
    
% Closest to ACD
elseif all(abgACD > 0) && all(abgACD < 1) && vABCD <= 0
    simplex.dir = -ptACD;
    simplex.Au = abgACD(1);
    simplex.Cu = abgACD(2);
    simplex.Du = abgACD(3);
    lastVert = simplex.B;
    simplex = cullSimplex(simplex, 'B');
    
% Closest to ADB
elseif all(abgADB > 0) && all(abgADB < 1) && wABCD <= 0
    simplex.dir = -ptADB;
    simplex.Au = abgADB(1);
    simplex.Du = abgADB(2);
    simplex.Bu = abgADB(3);
    lastVert = simplex.C;
    simplex = cullSimplex(simplex, 'C');
    
% If alpha, beta, and gamma are all equal to 0 or 1, then we are ON one of
% the surfaces which would meana collision has been detected
else
    simplex.collision = true;
    return
end

simplex.len = 4;
[simplex.Apts, simplex.A] = supporthelper(simplex, shape1, shape2);

% If we added a duplicate point, then we know we have converged
if all(abs(simplex.A - simplex.B) < 10*eps) || ...
        all(abs(simplex.A - simplex.C) < 10*eps) || ...
        all(abs(simplex.A - simplex.D) < 10*eps) || ...
        all(abs(simplex.A - lastVert) < 10*eps)
    
    simplex = cullSimplex(simplex, 'A');
    simplex.len = 3;
    simplex.converged = true;
end

% if sum(all([abgABC; abgACD; abgADB] > 0, 2) .* ... 
%         all([abgABC; abgACD; abgADB] < 1, 2)) == 2
%     disp('Closest to two planes')
% end

end



















function simplex = cullSimplex(simplex, vertex)
%CULLSIMPLEX Removes a point from the simplex
%   Since A is always replaced with the newest point on the simplex, all
%   points must be moved to make room for the new A. When a single point is
%   culled, it is replaced with another point on the simplex.
%
%   Note that each operation effectively right shifts all the points except
%   for A. If A is the value to cull, all points are shifted left.

switch upper(vertex)
    case 'A'
        simplex.Apts = simplex.Bpts;
        simplex.Au = simplex.Bu;
        simplex.A = simplex.B;
        
        simplex.Bpts = simplex.Cpts;
        simplex.Bu = simplex.Cu;
        simplex.B = simplex.C;
        
        simplex.Cpts = simplex.Dpts;
        simplex.Cu = simplex.Du;
        simplex.C = simplex.D;
        
    case 'B'
        simplex.Bpts = simplex.Apts;
        simplex.Bu = simplex.Au;
        simplex.B = simplex.A;
        
    case 'C'
        simplex.Cpts = simplex.Bpts;
        simplex.Cu = simplex.Bu;
        simplex.C = simplex.B;
        
        simplex.Bpts = simplex.Apts;
        simplex.Bu = simplex.Au;
        simplex.B = simplex.A;
        
    case 'D'
        simplex.Dpts = simplex.Cpts;
        simplex.Du = simplex.Cu;
        simplex.D = simplex.C;
        
        simplex.Cpts = simplex.Bpts;
        simplex.Cu = simplex.Bu;
        simplex.C = simplex.B;
        
        simplex.Bpts = simplex.Apts;
        simplex.Bu = simplex.Au;
        simplex.B = simplex.A;
        
    otherwise
        error('The vertex should be A, B, C, or D only')
end

end


















function [Apts, A] = supporthelper(simplex, shape1, shape2)
%SUPPORTHELPER Helper function to compute the support for both shapes
%   [Apts, A] = supporthelper(simplex, shape1, shape2)
%
%   Since the support function is originally defined for one shape, a lot
%   of code was being rewritten for two shapes. This helper function solves
%   that problem by wrapping the support function to handle two shapes.
%
%   For input and output descriptions, see dosimplex.
pt1 = support(shape1, simplex.dir);
pt2 = support(shape2, -simplex.dir);
Apts = [pt1, pt2];
A = pt1 - pt2;

end



















function point = support(polygon, direction)
%SUPPORT Gives the furthest point on the polygon in some direction
%   point = support(polygon, direction)
%
%   This function is used for the GJK algorithm to find the furthest point
%   on a polygon in a certain direction. The GJK algorithm works in such a
%   way that any arbitrary convex shape can be used as long as a support
%   function exists. It is important to note that this specific support
%   function was only designed for a 2 or 3 dimensional polygon.
%
%   If two or more points are equally far away, one will be arbitrarily
%   chosen.
%
%   By using the dot product, we can determine which point is the furthest
%   in a certain direction. We simply need to find the maximum dot product
%   and do not care about the actual value of it.
%
%   INPUTS
%   polygon: Nxm matrix representing an N dimensional polygon where m is
%       the number of points in the polygon.
%
%   direction: N dimensional vector representing the desired search
%       direction.t
%
%   OUTPUTS
%   point: Furthest point in the given direction.
%
%   EXAMPLE
%   poly = [1 1 2 1.5 2 4;
%           1 2 2 1.5 1 0;]
%   plot(polyshape(poly'))
%   direction = [1 1]
%   idx = support(poly, direction)
%   poly(:, idx) % Furthest point on the polygon
%
%   poly3d = [0 0 1 1 0 0 1 1;
%             0 1 1 0 0 1 1 0;
%             0 0 0 0 1 1 1 1]
%   direction3d = [0 1 1]
%   idx3d = support(poly3d, direction3d)
%   poly3d(:, idx3d) % Furthest point on the polygon

[~, npts] = size(polygon);

% maxDist = dot(direction, polygon(:, 1));
maxDist = direction'*polygon(:, 1);
point = polygon(:, 1);
for i = 2:npts
%     curDist = dot(direction, polygon(:, i));
    curDist = direction'*polygon(:, i);
    if curDist > maxDist
        maxDist = curDist;
        point = polygon(:, i);
    end
end

end




















function [closestPt, t] = dist2line(A, B)
%DIST2LINE Finds the closest point on a line segment to the origin.
%   This function finds the point on the line segment AB which is closest
%   to the origin. This is done by representing the line segment as a 1st
%   order Bernstein polynomial, f(t) = (1-t)*A + t*B, t = [0, 1]. We then
%   square f to create a quadratic minimization problem. Finally, take the
%   derivative and set equal to zero to solve for t. If t is outside the
%   range of [0, 1] we know that the origin is closest to either point A or
%   point B. Otherwise, the origin is closest to a point on the line.
%
%   Note that this will retun NaN if the points A and B are equal.
%
%   INPUTS
%   A: N dimensional point on the line segment AB.
%   B: N dimensional point on the line segment AB.
%
%   RETURNS
%   closestPt: N dimensional point on line segment AB which is closest to
%       the origin.
%   t: Weight used to solve for the point on the Bernstein polynomial,
%       where f(t) = (1-t)*A + t*B, t = [0, 1]

    if all(abs(A - B) < 1000*eps)
        t = 0;
        closestPt = A;
        return
    end

    v = B - A;
    u = A;
    t = -(v'*u) / (v'*v);

    % If t is out of the range [0, 1] we are closest to A or B
    if t > 1
        t = 1;
        closestPt = B;
    elseif t < 0
        t = 0;
        closestPt = A;
    else
        closestPt = (1-t)*A + t*B;
    end
end




















function [pt, abg] = dist2plane(A, B, C)
%DIST2PLANE Finds the minimum distance between a plane and the origin
%   Find the barycentric center of the simplex ABC.
%
% Note that if the points are collinear, the result will be NaNs due to a
% divide by zero error. A good solution to this would be to check for
% collinear points. If they are collinear, find the two points that are
% furthest apart from each other and then use the dist2line function.
%
% INPUTS
% A: 3x1 3D point comprising one of the three vertices of the plane.
% B: See A
% C: See A
%
% OUTPUTS
% pt: 3x1 point on the plane at which the minimum distance occurs
% abg: 1x3 vector containing the normalized barycentric values alpha, beta,
%   and gamma.

u = B - A;
v = C - A;
w = - A;
n = cross(u, v);

gamma = n'*cross(u, w) / sum(n.^2);
beta = n'*cross(w, v) / sum(n.^2);
alpha = 1 - beta - gamma;

pt = alpha*A + beta*B + gamma*C;

abg = [alpha, beta, gamma];

end