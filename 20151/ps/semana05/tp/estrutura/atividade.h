#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "lista.h"
#include "pessoa.h"

typedef struct Atividade {
  struct String *nome;
  struct ListaIntegrante *integrantes;
  struct Pessoa *coordenador;
} TipoAtividade;

#endif
