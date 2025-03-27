% Using the structures parent(X, Y), male(X), and female(X), write a structure that defines sister(X, Y).
% assume sister(X,y) means X is sister of Y
male(son).
female(daughter).
parent(son,father).
parent(daughter,father).
sister(X,Y) :- 
    
    female(X),
    parent(X,T),
    parent(Y,T),
    X\=Y.

% query1: sister(daughter,Q).
% query2: sister(daughter,son). returns true