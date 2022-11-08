function  poly_t  = PiecewiseBernsteinPoly(Cp,tknots,time)

% INPUTS:
% 
% OUTPUT:
% 
% 
% Written by: Venanzio Cichella       

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

M = length(tknots)-1;
[dim, totN] = size(Cp);
N = totN/M - 1;

poly_t = zeros(dim,length(time));

for i = 1 : M
    for k = 1 : length(time)   
        if time(k) >= tknots(i) && time(k) <= tknots(i+1) 
            t = time(k);
            if i < M
                poly_t(:,k) = BernsteinPoly(Cp(:,(i-1)*N+i:i*N+i),t,tknots(i),tknots(i+1));
            else
                poly_t(:,k) = BernsteinPoly(Cp(:,(i-1)*N+i:end),t,tknots(i),tknots(i+1));
            end
        end
    end
end


end







