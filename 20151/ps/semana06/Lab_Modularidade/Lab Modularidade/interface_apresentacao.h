/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_APRESENTACAO
#define MOD_APRESENTACAO

/* 
Controle visando identificar o servidor.
*/

#ifdef SERVIDOR_APRESENTACAO
#define EXT_MOD_APRESENTACAO
#else
#define EXT_MOD_APRESENTACAO extern
#endif

/*
Declarações dos protótipos das funções.
*/

EXT_MOD_APRESENTACAO void executar();

#endif
