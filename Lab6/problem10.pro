% 10.Write a Prolog program to merge two sorted lists into a single sorted list.
merge_lists([],List,List).
merge_lists(List,[],List).

merge_lists([Head1|Tail1],[Head2|Tail2],[Head1|List3]) :-
    Head1 =< Head2 ,
    merge_lists(Tail1,[Head2|Tail2],List3).

merge_lists([Head1|Tail1],[Head2|Tail2],[Head2|List3]) :-
    Head1 > Head2 ,
    merge_lists([Head1|Tail1],Tail2,List3).

main:-
    write('Please enter both lists:- \n'),
    read(List1),
    read(List2),
    merge_lists(List1,List2,Answer),
    write(Answer),
    nl.