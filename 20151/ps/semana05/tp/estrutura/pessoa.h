#ifndef PESSOA_H
#define PESSOA_H

#include "atividade.h"
#include "lista.h"
#include "string.h"

typedef struct Pessoa {
  int anoMatricula;
  int matricula;
  struct TipoString *nome;
  struct TipoString *vinculo;
  struct ListaNomeCitacao *nomesCitacao;
} TipoPessoa;

#endif
