% Write a Prolog program to compute the factorial of a given number.4

factorial(0,Result) :- Result is 1.

factorial(N,Result) :-N1 is N-1, factorial(N1,R1), Result is N*R1.

main:- 
    write('give input number \n'),
    read(N),
factorial(N,Result),
write(Result).