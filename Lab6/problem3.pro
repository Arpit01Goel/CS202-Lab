% To find if intersection of two lists is empty or not 
check([],_).
check(_,[]).
check([X|Tail1],Tail2) :-
    
    \+ member(X,Tail2),
    
    check(Tail1,Tail2).

main :-
    write('Give input list1: \n'),
    read(X),
    write('Give input list2: \n'),
    read(Y),
    check(X,Y).

