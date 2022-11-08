function  poly_t  = BernsteinPolyStable(Cp,t)

[m,n] = size(Cp);
poly_t = zeros(m,length(t));
count = 0;
for i = 1 : length(t)
    [~,poly_t(:,i)] = deCasteljau(Cp,t(i));
    count = count + 1;
end

end