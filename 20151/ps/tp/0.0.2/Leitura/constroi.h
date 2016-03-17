/*!	
*	Arquivo de construcao das listas de discentes, docentes, projetos.
*	\author Danilo Alves.
* 	\author José Siqueira.
*	\since 01/03/15.
*	\version 0.0.1.
*
*/

#ifndef CONSTROI_H_
#define CONSTROI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Estrutura/atividade.h"
#include "../Estrutura/lista.h"
#include "../Estrutura/pessoa.h"
#include "../Estrutura/string.h"

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

void ConstroiListaDiscente(ListaDiscente **epinicio, char *arquivo);
void ConstroiListaProjeto(ListaProjeto **epinicio, char *arquivo);
void OrdenaListaDiscente(ListaDiscente **epinicio);
void PercorreListaDiscente(ListaDiscente *pinicio);
void PercorreListaProjeto(ListaProjeto *pinicio);

#endif /* CONSTROI_H_ */
