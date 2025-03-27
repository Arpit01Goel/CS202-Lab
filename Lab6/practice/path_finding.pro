edge(a,b).
edge(b,c).
edge(a,c).
edge(e,f).
edge(f,g).
edge(g,e).

edge(A,B) :- edge(B,A).
path(A,B) :- 
    edge(A,B);
    edge(A,C), path(C,B).