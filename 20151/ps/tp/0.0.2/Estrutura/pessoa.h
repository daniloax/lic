#ifndef PESSOA_H
#define PESSOA_H

#include "atividade.h"
#include "lista.h"
#include "string.h"

typedef struct Pessoa {
  struct TipoString *nome;
  int anoMatricula;
  int matricula;
  struct TipoString *vinculo;
  struct ListaNomeCitacao *nomesCitacao;
} TipoPessoa;

#endif
