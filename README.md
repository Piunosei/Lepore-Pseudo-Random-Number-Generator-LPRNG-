# Lepore-Pseudo-Random-Number-Generator-LPRNG-
Lepore Pseudo-Random Number Generator (LPRNG)

Given a seed M-2, odd number

calculate N=M^2
calculate (2^(N^2)-2) mod (2*N^2) = X
calculate a=GCD(X,N)

if a!=M increment the counter count_0
and increment M=M+a+1

if a==M see if the value of count_0 is odd or even
if it is even print 0
if it is odd print 1
reset count_0=0
and increment M=M+1+1

I inserted count_pari and count_dispari to do some tests

for example with a seed
100000000000000000000000000000000000000000000000000000000001
generating 100000 values
we have
TRUE = 52587
FALSE = 47413



Instructions

takes the seed from input0.txt
and the length of the string of true and false to generate from terminal

