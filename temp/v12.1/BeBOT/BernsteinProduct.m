function Cp = BernsteinProduct(A,B)

% INPUT: A and B are row vectors of dimensions M+1 and N+1 elements, respectively (control points of two 1-dimensional Bernstein polynomials or order M and N)
% OUTPUT: cp is a row vector of dimension N+M+1 (control points of the Bernstein polynomial)  

% Written by: Venanzio Cichella       08/08/19
% Contact:    venanzio-cichella@uiowa.edu

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

M = length(A)-1;
N = length(B)-1;

C = zeros(M+N+1,1)';

for k = 0:M+N
    C(k+1) = 0;
    for j = max(0,k-N):min(M,k)
        C(k+1) = C(k+1) + nchoosek_mod(M,j)*nchoosek_mod(N,k-j)/nchoosek_mod(M+N,k)*A(j+1)*B(k-j+1);
    end
end

Cp = C;

end









