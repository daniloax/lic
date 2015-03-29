#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

void PercorreMalha(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;

  if (pini == NULL)
    printf ("\nLista Vazia");
  else {
    printf("%s","\nGrade de Disciplinas:\n");
    pd1 = pini;
    while (pd1 != NULL) {
      printf("\n%c", pd1->disc);
      pp1 = pd1->pacesso;
      while (pp1 != NULL) {
        printf("%2c", pp1->ppre->disc);
        pp1 = pp1->proxp;
      }  
      pd1 = pd1->proxd; 
    }
  }
  printf("\n");
}  
