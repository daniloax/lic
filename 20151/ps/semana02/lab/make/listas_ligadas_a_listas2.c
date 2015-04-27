/* listas ligadas a listas
As disciplinas que um aluno deve cursar são identificadas por letras. Cada uma
delas pode ter pre-requisitos. O arquivo que guarda os dados tem a seguinte 
forma:

a 3 b c d
b 2 e d
c 3 d e b
d 0
e 1 d

significando que a disciplina a só pode ser cursada depois de cursadas as 
disciplinas b, c e d; a disciplina b só pode ser cursada depois de cursadas
as disciplinas e e d; e assim por diante.

O programa deve montar a estrutura de dados depois de ler o arquivo, e em 
seguida mostar uma sequencia linear possível de disciplinas, respeitando todos
os pre-requisitos.
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
  char c;
  int i, n;

  arq = fopen ("t103.txt", "r");
  *epinicio = NULL;
  while ((c = getc (arq)) != EOF) {
    pd1 = malloc (sizeof (lista1));
    pd1->cursado = 0;
    pd1->disc = c;
    pd1->pacesso = NULL;
    pd1->proxd = NULL;
    if (*epinicio == NULL)
      *epinicio = pd1;
    else
      pd2->proxd = pd1;
    pd2 = pd1;
    while ((c = getc (arq)) != '\n');
  }
  fclose (arq);
  arq = fopen ("t103.txt", "r");
  pd1 = *epinicio;
  while ((c = getc (arq)) != EOF) {
    fscanf (arq, "%d ", &n); 
    for (i=1; i !=n+1; i++) {
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
      c = getc (arq);  
    }
    pd1 = pd1->proxd;
  }
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
void PercursoLinear(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;
  int ok;

  pd1 = pini;
  while (pd1 != NULL) {  
    if (pd1->cursado)
      ok = 0;
    else {
      ok = 1;
      pp1 = pd1->pacesso;
      while (pp1 != NULL) {  
        if (!pp1->ppre->cursado)
          ok = 0;
        pp1 = pp1->proxp;
      }
    }
    if (ok) {  
      pd1->cursado = 1;
      printf("%c\n", pd1->disc);
      pd1 = pini;
    }
    else pd1 = pd1->proxd;
  }
}

//--------------------------------------------
main (){
  struct lista_disc *pinicio;

  ConstroiMalha (&pinicio);
  PercorreMalha (pinicio);
  PercursoLinear (pinicio);
    
  system("pause");
}
     
     
     
     
     
     
     
     
     
