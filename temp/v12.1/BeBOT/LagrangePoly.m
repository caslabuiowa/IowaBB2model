function xN = LagrangePoly(x,tnodes,time)

%% Get polynomials
n = length(x);

basis_polynomials = cell(n,1); %basis polynomials for values t

for i = 1:n
    basis_polynomials{i} = 0;
    numerator = 1;
    denominator = 1;
    for k = 1:n
        if i~=k
            numerator = numerator.*(time-tnodes(k));
            denominator = denominator.*(tnodes(i)-tnodes(k));
        end
    end
    basis_polynomials{i} = numerator./denominator;
end


% then find the Lagrange polynomial coefficients
xN = 0;

for k = 1:n
    xN = xN + x(k)*basis_polynomials{k};
end

end
