%9.
%a. For a list of integer number, write a predicate to add in list after
% 1-st, 3-rd, 7-th, 15-th element a given value e.


%insertAtPosition(L:list,E:element,Pos:int,PosList:list,R:list)
%     [] , sizeOf(L) = 0
%
%     L1 + E + insertAtPosition(L2...Ln,E,Pos+1,PosList2...PosListn,R),
%     Pos = PosList1
%
%     L1 + insertAtPosition(L2...Ln,E,Post+1,PostList,R),
%     otherwise

%flow model (i,i,i,i,o)


insertAtPosition([],_,_,[],[]).

insertAtPosition([],_,_,[_],[]).

insertAtPosition([H|T],E,Pos,[J|Y],[H,E|R]):- Pos =:= J, !,
    Pos1 is Pos + 1,
    insertAtPosition(T,E,Pos1,Y,R).

insertAtPosition([H|T],E,Pos,Y,[H|R]):-
    Pos1 is Pos + 1,
    insertAtPosition(T,E,Pos1,Y,R).




%insertIntoArray(L:list,E:element,R:list)
%flow model (i,i,o)

insertIntoArray(L,E,R):-
    insertAtPosition(L,E,1,[1,3,7,15],R).



% b. For a heterogeneous list, formed from integer numbers and list of
% numbers; add in every sublist after 1-st,
% 3-rd, 7-th, 15-th element the value found before the sublist in the
% heterogenous list. The list has the particularity
% that starts with a number and there aren’t two consecutive elements
% lists.




%hetList(L:list,R:list)
%     [], size(L) = 0
%
%     L1 + insertIntoArray(L2...Ln,L1,R) + hetList(L2...Ln,R),
%     is_list(L2) and number(L1)
%
%     L1 + hetList(L2...Ln,R), otherwise

%flow model (i,o)

hetList([],[]).

hetList([H1,H2|T],[H1,R1|R]):-
    is_list(H2),
    number(H1),
    !,
    insertIntoArray(H2,H1,R1),
    hetList(T,R).

hetList([H|T],[H|R]):-
    hetList(T,R).
