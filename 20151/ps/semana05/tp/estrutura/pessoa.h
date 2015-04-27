#ifndef PESSOA_H
#define PESSOA_H

#include "atividade.h"
#include "lista.h"

struct Pessoa {
  struct String *nome;
  struct String *vinculo;
  struct ListaNomeCitacao *nomesCitacao;
};

#endif
