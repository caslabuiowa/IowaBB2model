function M = adtranspose(M)
%  ADTRANSPOSE  The anti-diagonal transpose
%
%    B = ADTRANSPOSE(A) computes the transpose of A about the anti-diagonal.
%
%    See also TRANSPOSE, ROT90.

M = transpose(rot90(M, 2));
end
