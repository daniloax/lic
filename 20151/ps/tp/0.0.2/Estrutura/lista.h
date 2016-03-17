#ifndef LISTA_H
#define LISTA_H

#include "atividade.h"
#include "pessoa.h"
#include "string.h"

typedef struct ListaIntegrante {
   struct TipoPessoa *integrante;
   struct ListaIntegrante *proximoIntegrante;
} ListaIntegrante;

typedef struct ListaNomeCitacao {
   struct TipoString *nomeCitacao;
   struct ListaNomeCitacao *proximaCitacao;
} ListaNomeCitacao;

typedef struct ListaProjeto {
   struct TipoProjeto *projeto;
   struct ListaProjeto *proximoProjeto;
} ListaProjeto;

typedef struct ListaDiscente {
   struct TipoPessoa *discente;
   struct ListaDiscente *proximoDiscente;
} ListaDiscente;

typedef struct ListaDocente {
   struct TipoPessoa *docente;
   struct ListaDocente *proximoDocente;
} ListaDocente;

#endif
