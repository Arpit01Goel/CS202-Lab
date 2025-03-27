% 13.Write a Prolog program to implement the bubble sort algorithm.

bubble_sort(List, Sorted) :-
    bubble_pass(List, List1, Swapped),
    (   Swapped = true
    ->  bubble_sort(List1, Sorted)
    ;   Sorted = List1).

bubble_pass([X, Y|T], [Y|Rest], true) :-
    X > Y, !,
    bubble_pass([X|T], Rest, _).

bubble_pass([X, Y|T], [X|Rest], Swapped) :-
    bubble_pass([Y|T], Rest, Swapped).

bubble_pass([X], [X], false).
bubble_pass([], [], false).

main:-
    write('give input'),
    read(List),
bubble_sort(List,Answer),
write(Answer),
nl.