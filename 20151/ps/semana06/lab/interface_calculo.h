/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_CALCULO
#define MOD_CALCULO

/* 
Controle visando identificar o servidor.
*/

#ifdef SERVIDOR_CALCULO
#define EXT_MOD_CALCULO
#else
#define EXT_MOD_CALCULO extern
#endif

/*
Declarações de constantes usadas.
*/

#define ERRO_PARAMETRO -1

/*
Declarações dos protótipos das funções.
*/

EXT_MOD_CALCULO int fatorial(int valor);

#endif
