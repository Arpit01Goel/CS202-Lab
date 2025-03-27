% 12.Write a Prolog program to determine whether a list has duplicate elements.


detect_duplicate([_]).
detect_duplicate([]).
detect_duplicate([Head|Tail]) :- 
    \+ member(Head,Tail),
    detect_duplicate(Tail).

main:-
    write('Enter the list to check for duplicates \n'),
    read(List),
    nl,
    detect_duplicate(List),
    write('no duplicate present \n').

% false means  duplicate is present