female(ada).
female(polly).
female(linda).
female(grace).
female(lizzie).
female(esme).
female(ruby).

male(charles).
male(billy).
male(karl).
male(thomas).
male(john).
male(arthur_jr).
male(arthur_sr).
male(finn).
male(michael).
male(freddie).

parent(arthur_sr,arthur_jr).
parent(arthur_sr,thomas).
parent(arthur_sr,john).
parent(arthur_sr,finn).
parent(arthur_sr,ada).


parent(arthur_jr,billy).
parent(linda,billy).

parent(thomas,charles).
parent(grace,charles).

parent(thomas,ruby).
parent(lizzie,ruby).

parent(freddie,karl).
parent(ada,karl).

parent(polly,michael).

mother(X,Y) :- parent(X,Y),female(X).
father(X,Y) :- parent(X,Y),male(X).

wife(X,Y):- parent(X,Z),parent(Y,Z),female(X),male(Y).
husband(X,Y):- parent(X,Z),parent(Y,Z),male(X),female(Y).

sister(X,Y) :- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y) :- parent(Z,X),parent(Z,Y),male(X),X\==Y.

grandfather(X,Y) :- male(X), parent(X,Z),parent(Z,Y).
grandmother(X,Y) :- female(X), parent(X,Z),parent(Z,Y).

masi(X,Y) :- female(X),mother(Z,Y),sister(Z,X).
mama(X,Y) :- male(X),mother(Z,Y),brother(Z,X).

bua(X,Y) :- female(X),father(Z,Y),sister(Z,X).
chacha(X,Y) :- male(X),father(Z,Y),brother(Z,X).

haschild(X) :- parent(X,_).
