#ifndef LISTA_H
#define LISTA_H

#include "atividade.h"
#include "pessoa.h"
#include "string.h"

typedef struct Integrante {
   struct Pessoa *integrante;
   struct Integrante *proximoIntegrante;
} ListaIntegrante;

typedef struct NomeCitacao {
   struct String *nomeCitacao;
   struct NomeCitacao *proximoNome;
} ListaNomeCitacao;

typedef struct Projeto {
   struct Atividade *projeto;
   struct Projeto *proximoProjeto;
} ListaProjeto;

typedef struct Discente {
   struct Pessoa *discente;
   struct Discente *proximoDiscente;
} ListaDiscente;

typedef struct Docente {
   struct Pessoa *docente;
   struct Docente *proximoDocente;
} ListaDocente;

#endif
