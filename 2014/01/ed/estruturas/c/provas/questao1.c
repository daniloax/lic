/*
Questao1

São dadas abaixo as funções ConstroiListaAS2 e PercorreListaAS, para construir
e para ler, respectivamente, uma lista aberta de encadeamento simples contendo
caracteres nos elementos. Também é dado o arquivo a1.txt para teste.

FAÇA UMA FUNÇÃO QUE CONSTRUA UMA LISTA ABERTA DE ENCADEAMENTO DUPLO, CONTENDO
APENAS AS VOGAIS DA LISTA ABERTA DE ENCADEAMENTO SIMPLES. ESSA FUNÇÃO DEVE
OPERAR APENAS EM MEMÓRIA, SEM USAR O ARQUIVO.

Para facilitar os testes, são dados:
a) definição de tipo de lista de encadeamento duplo;
b) uma função para ler uma lista aberta de encadeamento duplo;
c) um ponteiro pini2 para vc inicar a construção da nova lista.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento1 {
  char dado;
  struct elemento1 *prox;
} listaS;

typedef struct elemento2 {
  char dado;
  struct elemento2 *prox, *ant;
} listaD;


//--------------------------------------------
void ConstroiListaAS2(listaS **epinicio) {
  FILE *arq;
  listaS *p1, *p2;
  char c;

  arq = fopen ("a1.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaS));
    p1->dado = c;
    if (*epinicio == NULL)
      *epinicio = p1;
    else
      p2->prox = p1;
  p2 = p1;
  }
  p1->prox = NULL;
  fclose (arq);
}

//--------------------------------------------
void ConstroiListaAD(listaS *pinicio, listaD **epinicio) {

	listaS *p1;
	listaD *pd1, *pd2;

	p1 = pinicio;
	*epinicio = NULL;

	while (p1 != NULL) {

		if ((p1->dado == 'a') || (p1->dado == 'e') || (p1->dado == 'i') || (p1->dado == 'o') || (p1->dado == 'u')) {

			pd1 = malloc (sizeof (listaD));
			pd1->dado = p1->dado;

			if (*epinicio == NULL) {
				*epinicio = pd1;
				pd1->ant = NULL;
				pd1->prox = NULL;

			} else {

				pd1->ant = pd2;
				pd1->prox = NULL;
				pd2->prox = pd1;

			}

			pd2 = pd1;

		}

		p1 = p1->prox;

	}

}

//--------------------------------------------
void PercorreListaAS(listaS *pinicio) {
  listaS *p1;

  if (pinicio == NULL)
    printf ("lista vazia \n");
  else {
    p1 = pinicio;
    while (p1 != NULL) {
      printf("elemento:  %c \n", p1->dado);
      p1 = p1->prox;
    }
  }
}

//--------------------------------------------
void PercorreListaAD(listaD *pinicio) {
  listaD *p1;

  if (pinicio == NULL)
    printf ("lista vazia \n");
  else {
    p1 = pinicio;
    while (p1 != NULL) {
      printf("elemento:  %c \n", p1->dado);
      p1 = p1->prox;
    }
    p1 = pinicio;
    while (p1->prox != NULL)
      p1 = p1->prox;
    while (p1 != NULL) {
      printf("elemento (para tras):  %c \n", p1->dado);
      p1 = p1->ant;
    }
  }
}

//--------------------------------------------
main () {
  listaS *pini1;
  listaD *pini2;

  ConstroiListaAS2 (&pini1);
  PercorreListaAS (pini1);

  ConstroiListaAD(pini1, &pini2);
  PercorreListaAD(pini2);

  system("pause");
}
