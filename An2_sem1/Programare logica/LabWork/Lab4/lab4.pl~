%5.Two integers, n and m are given. Write a predicate to determine all
% possible sequences of numbers
% from 1 to n, such that between any two numbers from consecutive
% positions, the absolute difference
%to be >= m.

%difference(A:int,B:int,R:int)
%     R = A - B, A > B
%     R = B - A, B > A
%     R = 0, A = B

%flow model (i,i,o)


difference(A,B,R):-
    A > B,
    R is A - B.
difference(A,B,R):-
    B > A,
    R is B - A.
difference(A,B,R):-
    B = A,
    R is 0.



%numberSequence(N:int,I:int,L:list)
%     [],I > N
%     numberSequence(N,I+1,[I|L]), I <= N
%     numberSequence(N,I+1,L)


%flow model (i,i,o)

numberSequence(N,I,[]):-
    I > N,
    !.

numberSequence(N,I,[I|L]):-
    I =< N,
    I1 is I + 1,
    numberSequence(N,I1,L).

numberSequence(N,I,L):-
    I =< N,
    I1 is I + 1,
    numberSequence(N,I1,L).


%checkIfGreater(L:list,M:int):-
%      true, diff(L1,L2) >= M and size(L) = 2
%      checkIfGreater(L2...Ln,M), diff(L1,L2) >= M and size(L) > 2
%      false, otherwise
%flow model (i,i)


checkIfGreater([H1,H2],M):-
    difference(H1,H2,R),
    R >=M,
    !.

checkIfGreater([H1,H2|T],M):-
    difference(H1,H2,R),
    R >= M,
    checkIfGreater([H2|T],M).



%getSequence(N:int,M:int,R:list)
%flow model (i,i,o)

getSequence(N,M,R):-
    numberSequence(N,1,R),
    checkIfGreater(R,M).



%getAllSequences(N:int,M:int,R:List)
%flow model (i,i,o)

getAllSequences(N,M,R):-
    findall(R1,getSequence(N,M,R1),R).
