append([], Lista, Lista).
append([Cabeça | Lista_1], Lista_2, [Cabeça | Lista_3]) :-
		append(Lista_1, Lista_2, Lista_3).
