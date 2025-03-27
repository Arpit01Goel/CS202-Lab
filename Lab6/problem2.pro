% To write a program to check if a number is prime or not
factor(X,N) :- 
    Y is N*N,
    Y =< X,
    (
    X mod N =:= 0;
    N1 is N+1, 
    factor(X,N1)).

prime(X) :-
    X>1,
    \+ factor(X,2),
    write('Its is a prime number').

main :-
    write('Enter the number you want to check: '),
    read(X),
    prime(X).
% To check if any number q is prime or not, give query prime(q)