/* 
Controle visando evitar inclus�es m�ltiplas.
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
Declara��es de constantes usadas.
*/

#define ERRO_PARAMETRO -1

/*
Declara��es dos prot�tipos das fun��es.
*/

EXT_MOD_CALCULO int fatorial(int valor);

#endif
