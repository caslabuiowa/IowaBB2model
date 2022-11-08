function E = DegElevMatrix(N,M)
% INPUT: N: Order of the curve to be elevated; M: order to which it has to
% be elevated;
% OUTPUT: Elevation matrix E. 
% HOW TO USE: Given a Bernstein poly of order N with control points cpN (row vector),
% the control points of the Bernstein poly degree elevated to order N,
% namely cpM (row vector) is given by cpM = cpN*E;

% Written by: Venanzio Cichella       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



r = M-N;

for i = 1:1:N+1
    for j = 1:1:r+1
         E(i+j-1,i) = nchoosek_mod(N,i-1)*nchoosek_mod(r,j-1)/nchoosek_mod(M,i+j-2);
    end
end

E = E';


end









