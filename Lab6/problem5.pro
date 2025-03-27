% Write a Prolog program to print the Fibonacci series up to the nth term.

fibb(0,Result) :- Result is 0.
fibb(1,Result) :- Result is 1.

fibb(N,Result) :-
    N1 is N-1, 
    N2 is N-2, 
    fibb(N1, X),
    fibb(N2, Y), 
    Result is X+Y.



main:-
    write('give input the n : \n'),
    read(N),
    fibb(N,Result),
    write(Result).