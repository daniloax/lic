/**	
*	@file help.c
*	@brief Entrada padrão.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Inclusão de bibliotecas do compilador.
*/

#include <stdio.h>
#include <stdlib.h>

/**
*	Declaração visando identificar o módulo como servidor.
*/

#define HELP_C_

/** 
*	Inclusão de módulos de definição.
*/

#include "help.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef help_C_

int main(int argc, char *argv[]) {
	
	char buffer[256], c;
	int i;
	FILE *pFile;
	
	pFile = fopen("PLSH.txt", "r");
   
   if (!pFile)
      printf("'PLSH.txt' not exist\n");
      
	printf("\n");

	while ((c = getc(pFile)) != EOF) {

		/** inicializa contador */
		i = 0;
		
		/** leitura de linha */
		do {
			
			buffer[i] = c;
			i++;
		
		} while (((c = getc(pFile)) != '\n') && (c != EOF));
		
		/** adiciona caracter de termino de string */
		buffer[i] = '\0';
		
		printf("%s\n", buffer);
	
	}
	
	return 0;
	
}
