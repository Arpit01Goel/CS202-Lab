% to define a symmetric relation in prolog

friends(a,b).
friends(c,d).



friends(X,Y) :-friends(Y,X).
