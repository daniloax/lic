reverse([], []).
reverse([Cabeça | Cauda], Lista) :- reverse(Cauda, Resultado),
				append(Resultado, [Cabeça], Lista).
