membro(Elemento, [ Elemento | _ ]).
membro(Elemento, [ _ | Lista]) :- membro(Elemento, Lista).
