% Write a Prolog program to find the greatest common divisor of two numbers.
gcd(X,0) :-
    write('Required gcd is: \n'),
    write(X),
    nl.
% nl is to go to new line, just like endl
gcd(X,Y) :- 
    Z is X mod Y,
    gcd(Y,Z).

main:- 
    write('Enter first Number and second no in each line \n'),
    read(X),
    read(Y),
    gcd(X,Y).