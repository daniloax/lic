/* 
Controle visando evitar inclus�es m�ltiplas.
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
Declara��es dos prot�tipos das fun��es.
*/

EXT_MOD_APRESENTACAO void executar();

#endif
