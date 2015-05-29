#include <stdio.h>
#include <stdlib.h>

#include "Listas.h"

void Inicia(Lista /*@out@*/ **inicio) {
	(*inicio) = NULL;
}

void Insere(Lista **inicio, char *c, int *tamanho) {
	
   if (c != NULL) {
		
      Lista *aux;
		
      int flag = 0;
		aux = *inicio;
		
      if (aux == NULL) {
			
         *inicio = malloc(sizeof(Lista));
			
         if (*inicio != NULL) {
				
            aux = *inicio;
				aux->prox = NULL;
				flag = 1;
			
         }
		
      }
		
      while (aux->prox != NULL)
         aux = aux->prox;
		
      if (flag == 0) {
			aux->prox = malloc(sizeof(Lista));
         aux = aux->prox;
		}
		
      aux->c = calloc((size_t)tamanho + 1, sizeof(char));
		aux->c = c;
		aux->prox = NULL;
	
   }
      
}

void Mostra(Lista *inicio) { 
	
   Lista *aux;
   
   if (inicio == NULL)
      printf("lista vazia\n");
      
   else { 
      
      aux = inicio;
   
      while (aux != NULL) {
         
         printf("\n%s\n", aux->c);
         aux = aux->prox;
         
      }
      
   }

}

Lista** Avanca(Lista **inicio) {
	
   (*inicio) = (*inicio)->prox;
	
   return inicio;

}
