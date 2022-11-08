function [tnodes,w,Dm] = PiecewiseBeBOT(N,tknots)
% write description
% N is the order of 1 Bernstein poly
% tknots include first and final time

M = length(tknots) - 1; % M is the number of piece-wise polynomials
T = tknots(end)-tknots(1);
tnodes = realmin*ones(1,(N+1)*M);

Dm = [];
for i = 1 : M
    if i == 1
        tnodes(1,(i-1)*N+i:i*N+i) = linspace(tknots(i),tknots(i+1)-eps,N+1);
    end
    if i == M
        tnodes(1,(i-1)*N+i:i*N+i) = linspace(tknots(i)+eps,tknots(i+1),N+1);
    end
    if i > 1 && i < M
        tnodes(1,(i-1)*N+i:i*N+i) = linspace(tknots(i)+eps,tknots(i+1)-eps,N+1);
    end
            
    Dm = blkdiag(Dm, BernsteinDifferentiationMatrix(N,tknots(i+1)-tknots(i))*DegElevMatrix(N-1,N));
end


w = T/((N+1)*M)*ones(((N+1)*M),1);

end

