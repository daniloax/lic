/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DISCENTE
#define MOD_DISCENTE

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_lista.h"

/* 
Controle visando identificar o servidor.
*/

#ifdef SERVIDOR_DISCENTE
#define EXT_MOD_DISCENTE
#else
#define EXT_MOD_DISCENTE extern
#endif

/*
Declarações dos protótipos das funções.
*/

EXT_MOD_DISCENTE void getListaDiscente(ListaDiscente *pinicio);
EXT_MOD_DISCENTE void setListaDiscente(ListaDiscente **epinicio, char *arquivo);

#endif
