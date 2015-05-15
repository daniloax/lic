#include"Listas.h"
#include<stdio.h>
#include<stdlib.h>
static void Avanca(Lista**);
void Inicia ( Lista **inicio){
	(*inicio) = NULL;
}
void Insere( Lista **inicio, char *c, int tamanho){
	if( c != NULL ){	
		Lista *aux;
		int flag = 0;
		aux = *inicio;
		if ( aux == NULL ){
			*inicio = malloc(sizeof(Lista));
			if ( *inicio != NULL ){
				aux = *inicio;
				aux->prox = NULL;
				flag = 1;
			}
		}
		while ( aux->prox != NULL );
		if ( flag == 0 ){
			aux->prox = malloc(sizeof(Lista));
		}
		aux->c = calloc((size_t)tamanho+1, sizeof(char));
		aux->c = c;
		aux->prox = NULL;
	}
	else return NULL;
}

void Mostra(Lista *inicio){
	while ( inicio != NULL ){
		printf("\n%s\n",inicio->c);
	}
}

void Avanca(Lista **inicio){
	(*inicio) = (*inicio)->prox;
	return inicio;
}
