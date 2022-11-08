function [tnodes,w,Dm] = LGL_PS(N,Tf)

% This function outputs LGL nodes, weights (for integration), and
% differentiation matrix Dm for an interval [0,tf]
% if fN (row vector) are the nodes of a poly, the nodes of its derivative are fN*Dm 

% Written by Venanzio Cichella


%% Find nodes

z = cos(pi*(0:N)/N)';
L  = zeros(N+1,N+1);
zprev = 1;

% Find roots of (1-z^2)LNdot using Newton Rapson

while max(abs(zprev-z)) > eps
    zprev = z; % update
    
    L(:,1)=1;    
    L(:,2)=zprev;   
    
    for i = 2:N
        L(:,i+1)=( (2*i-1)*zprev.*L(:,i)-(i-1)*L(:,i-1) )/i;
    end
    
    % (1-z^2)LNdot = (1-z^2)(zLN-LN-1)
    num = (N+1)*(zprev.*L(:,N+1)-L(:,N));
    
    % d((1-z^2)LNdot)/dt = -2zLNdot ( + 2zLNdot - N(N+1)LN )
    % Legendre Functions of the Second Kind and Related Functions, Dunham
    % Jackson (Eq. 10)
    den = (N+1)*(N+2)*L(:,N+1);
    
    % Newton Rapson: z = zprev - fdot/fddot
    z = zprev - num./den;
end 

z = fliplr(z');
tnodes = ((z+1)./(2/Tf));


%% Compute weights

w=Tf./(N*(N+1)*L(:,N+1).^2);
w(1) = Tf./(N*(N+1));
w(end) = Tf./(N*(N+1));


%% Differentiation Matrix

for i = 1:N+1
    for k = 1:N+1
        if i == k
            Dm(i,k) = 0;
        else
            Dm(i,k) = (L(k,N+1)/L(i,N+1))/((tnodes(k)-tnodes(i)));
        end
        if i == 1 && k == 1 
            Dm(i,k) = -N*(N+1)/(2*Tf);
        end
        if i == N+1 && k == N+1
            Dm(i,k) = N*(N+1)/(2*Tf);
        end
    end
end




end



