% Write a Prolog program that implements an insertion sort.

insertion_sort([],[]).

insertion_sort([Head|Tail],Result) :- 
    insertion_sort(Tail,SubResult),
    insert(Head,SubResult,Result).

insert(X,[],[X]).
insert([],[],[]).
insert(X,[Head|Tail],[X,Head|Tail]) :- 
    X =< Head .
insert(X,[Head|Tail],[Head|SubResult]) :-
    X > Head, 
    insert(X,Tail,SubResult).

main:-
    write('insert input \n'),
read(List),
insertion_sort(List,Answer),
write(Answer),
nl.