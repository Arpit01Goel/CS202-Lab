even(0).

even(X):- X>0, X1 is X-2,X1> -1, even(X1).
even(X):- X<0, X2 is -X,  even(X2).