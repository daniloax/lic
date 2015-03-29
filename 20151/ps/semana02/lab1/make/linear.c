#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

void PercursoLinear(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;
  int ok;

  if (pini == NULL)
    printf ("\nLista Vazia");
  else {
     printf("%s","\nPre-requisitos:\n"); 
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
         printf("\n%c", pd1->disc);
         pd1 = pini;
       }
       else pd1 = pd1->proxd;
     }
   }
   printf("\n");
}
