predecessor(X,Z) :-
	parent(X,Z).
predecessor(X,Z) :-
	parent(X,Y),
	predecessor(Y,Z).
parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).
parent(pam,liz).

/*
predecessor(pam, X).
p\/aridade 2
X <- pam
Z <- X
true
parent(pam,Z).
p\/aridade 2
pam <- pam
bob <- Z
true
predecessor(pam,bob).
p\/aridade 2
X <- pam
Z <- bob
true
parent(pam,Y).
p\/aridade 2
pam <- pam
liz <- Y
predecessor(bob, Z).*/
