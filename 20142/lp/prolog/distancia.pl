velocidade(ford, 100).
velocidade(chevy, 105).
velocidade(dodge, 95).
velocidade(volvo, 80).
tempo(ford, 20).
tempo(chevy, 21).
tempo(dodge, 24).
tempo(volvo, 24).
distancia(X, Y) :- velocidade(X, Velocidade),
		tempo(X, Tempo),
		Y is Velocidade * Tempo.

