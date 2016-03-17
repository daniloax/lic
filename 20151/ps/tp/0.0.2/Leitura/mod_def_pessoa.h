/* 
Controle visando evitar inclusões múltiplas.
*/

#ifndef MOD_DEF_PESSOA
#define MOD_DEF_PESSOA

/* 
Inclusão de arquivo de módulo de definição.
*/

#include "mod_def_atividade.h"
#include "mod_def_lista.h"
#include "mod_def_string.h"

/*
Definição de estrutura.
*/

typedef struct TipoPessoa {
  struct TipoString *nome;
  int anoMatricula;
  int matricula;
  struct TipoString *vinculo;
  struct ListaNomeCitacao *nomesCitacao;
} TipoPessoa;

#endif
