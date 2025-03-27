% Write a Prolog program to check if a given list is a palindrome.

%use build in reverse function. generally used as reverse(A,B) and B gives reversed list. use by giving value of A then it will be just a chekc giving true or false

palindrome(A):- reverse(A,A).
main:-
    write('give input list \n'),
    read(X),
    palindrome(X),
    write('It was a palindrome\n').