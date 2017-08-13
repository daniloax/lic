/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_PROJETO
#define MOD_DEF_PROJETO

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_lista.h"

/* 
Controle visando identificar o servidor.
*/

#ifdef MOD_IMPL_PROJETO
#define EXT_MOD_DEF_PROJETO
#else
#define EXT_MOD_DEF_PROJETO extern
#endif

/*
Declarações dos protótipos das funções.
*/

EXT_MOD_DEF_PROJETO void getListaProjeto(ListaProjeto *pinicio);
EXT_MOD_DEF_PROJETO void setListaProjeto(ListaProjeto **epinicio, char *arquivo);

typedef enum {
   NOME_PROJETO = 0,
   DESCRICAO_PROJETO = 1,
   ANO_INICIO = 2,
   SITUACAO = 3,
   NATUREZA = 4,
   REALIZADOR = 5,
   NOME_CITACAO = 6,
   INTEGRANTES = 7
} Propriedade;

#endif
