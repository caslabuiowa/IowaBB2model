function binom = nchoosek_mod(N,k)
% This function produces the same output as MATLAB's nchoosek, but it's more efficient 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

binom = 1;
    for j = 1:k
        binom = binom*(N-(k-j));
        binom = binom/j;
    end
end
