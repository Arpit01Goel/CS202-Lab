% Write a Prolog program to reverse a list.
reverse_list([],[]).

reverse_list([Head|Tail],Reversed) :- 
    reverse_list(Tail,NewTail),
    append(NewTail,[Head],Reversed).

main:-
    write('give input the list to reverse \n'),
    read(L),
    
    reverse_list(L,Answer),
    write(Answer),
    nl.