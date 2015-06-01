#ifndef LISTA_H
#define LISTA_H

#include "atividade.h"
#include "pessoa.h"
#include "string.h"

typedef struct Integrante {
   struct TipoPessoa *integrante;
   struct Integrante *proximoIntegrante;
} ListaIntegrante;

typedef struct NomeCitacao {
   struct TipoString *nomeCitacao;
   struct NomeCitacao *proximaCitacao;
} ListaNomeCitacao;

typedef struct Projeto {
   struct TipoAtividade *projeto;
   struct Atividade *proximoProjeto;
} ListaProjeto;

typedef struct Discente {
   struct TipoPessoa *discente;
   struct Discente *proximoDiscente;
} ListaDiscente;

typedef struct Docente {
   struct TipoPessoa *docente;
   struct Docente *proximoDocente;
} ListaDocente;

#endif
