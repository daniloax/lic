#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "lista.h"
#include "pessoa.h"

typedef struct Atividade {
  struct TipoString *nome;
  struct TipoString *tipo;
  struct Pessoa *coordenador;
  struct ListaIntegrante *integrantes;
} TipoAtividade;

#endif
