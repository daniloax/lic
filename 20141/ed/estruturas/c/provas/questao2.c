/*
Questao2

As disciplinas que um aluno deve cursar são identificadas por letras. Cada uma
delas pode ter pre-requisitos. O arquivo que guarda os dados tem a seguinte
forma:

a b c d e
a 3 b c d
b 2 e d
c 3 d e b
d 0
e 1 d

significando que a disciplina a só pode ser cursada depois de cursadas as
disciplinas b, c e d; a disciplina b só pode ser cursada depois de cursadas
as disciplinas e e d; e assim por diante. Na primeira linha do arquivo estão
presentes todas as disciplinas.

Abaixo estão disponíveis as funções para constuir a estrutura de dados a partir
do arquivo e para percorrer a estrutura, escrevendo-a na tela. O arquivo a1.txt
é apenas um exemplo para teste. Na lista principal não há elementos repetidos.
Suponha que os arquivos estão sempre corretamente construídos.

FAÇA UMA FUNÇÃO QUE RECEBE UM PONTEIRO DE ACESSO À ESTRUTURA DE DADOS E UM
CARACTERE X.  A FUNÇÃO DEVE MODIFICAR A ESTRUTURA DE MODO QUE A DISCIPLINA X
DEIXE DE SER PRE-REQUISITO PARA QUALQUER OUTRA DISCIPLINA;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_pre {
  struct lista_disc *ppre;
  struct lista_pre *proxp;
} lista2;

typedef struct lista_disc {
  int cursado;
  char disc;
  struct lista_disc *proxd;
  lista2 *pacesso;
} lista1;

//----------------------------------------
void ConstroiMalha(lista1 **epinicio) {
  FILE *arq;
  lista1 *pd1, *pd2;
  lista2 *pp1, *pp2;
  char lixo1, c;
  int i, n, ok = 0;

  *epinicio = NULL;
  arq = fopen ("b1.txt", "r");
  while (!ok){
    c = getc (arq);
    pd1 = malloc (sizeof (lista1));
    pd1->disc = c;
    pd1->cursado = 0;
    pd1->pacesso = NULL;
    pd1->proxd = NULL;
    if (*epinicio == NULL)
      *epinicio = pd1;
    else
      pd2->proxd = pd1;
    pd2 = pd1;
    lixo1 = getc(arq);
    if (lixo1 == '\n') ok = 1;
  }
  pd1 = *epinicio;
  while ((lixo1 = getc(arq)) != EOF)
    if (lixo1 != '\n'){
      fscanf (arq,"%d", &n);
      for (i=1; i !=n+1; i++) {
        lixo1 = getc(arq);
        c = getc (arq);
        pp1 = malloc (sizeof (lista2));
        pp1->ppre = *epinicio;
        while (pp1->ppre->disc != c)
          pp1->ppre = pp1->ppre->proxd;
        pp1->proxp = NULL;
        if (pd1->pacesso == NULL)
          pd1->pacesso = pp1;
        else pp2->proxp = pp1;
        pp2 = pp1;
      }
      pd1 = pd1->proxd;
    }
  fclose (arq);
}

//--------------------------------------------
void PercorreMalha(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;

  if (pini == NULL)
    printf ("lista vazia \n");
  else {
    pd1 = pini;
    while (pd1 != NULL) {
      printf("%c", pd1->disc);
      pp1 = pd1->pacesso;
      while (pp1 != NULL) {
        printf("%2c", pp1->ppre->disc);
        pp1 = pp1->proxp;
      }
      pd1 = pd1->proxd;
      printf("\n");
    }
  }
  printf("\n");
}

//--------------------------------------------
void ExcluiRequisito(char c, lista1 **epinicio) {

	lista1 *pd1;
	lista2 *pp1, *pp2;

	pd1 = *epinicio;

	while (pd1 != NULL) {

		if (pd1->pacesso != NULL) {

			pp1 = pd1->pacesso;
			pp2 = pp1;

			while (pp1 != NULL) {

				if (pp1->ppre->disc == c) {

					if (pp1 == pd1->pacesso) {

						pp1 = pp1->proxp;
						pd1->pacesso = pp1;

					} else {

						pp1 = pp1->proxp;
						pp2->proxp = pp1;

					}

				} else {

					pp2 = pp1;
					pp1 = pp1->proxp;

				}

			}

		}

		pd1 = pd1->proxd;

	}

}

//--------------------------------------------
main (){
  lista1 *pinicio;
  char x;

  ConstroiMalha (&pinicio);
  PercorreMalha (pinicio);
  printf("entre com a disciplina x\n");
  fflush(stdin);
  scanf ("%c" , &x);

  ExcluiRequisito(x, &pinicio);
  PercorreMalha(pinicio);

// coloque aqui a chamada de sua função

  system("pause");
}
