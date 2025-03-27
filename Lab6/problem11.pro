% 11.Write a Prolog program to check if a given number is an Armstrong number.

check_armstrong(0,0,_).
check_armstrong(N,Result,Size) :-
    N>0,
    S is N mod 10,  
    N1 is N // 10, 
    check_armstrong(N1, SubResult, Size), 
    Result is SubResult + S**Size.
size(0,0).
size(N,Ans) :-
    N>0,
      N1 is N//10,
        size(N1,SubAns),
        Ans is 1+SubAns.


main:-
write('enter the number to check'),
read(N),
size(N,Size),
check_armstrong(N,Result,Size),
Result =:= N.
