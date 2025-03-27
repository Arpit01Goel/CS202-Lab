factorial(0,1).

factorial(X,Y):-
    X>0,
    X1 is X-1,
    factorial(X1,Y2),
    Y is X * Y2.