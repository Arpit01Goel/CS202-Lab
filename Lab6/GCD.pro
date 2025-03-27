gcd(A,0) :- A.
gcd(A,B) :- gcd(B,A mod B).

gcd(1000002, 350004).