/**	
*	@file screen.c
*	@brief Saída padrão.
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

#define SCREEN_C_

/** 
*	Inclusão de módulos de definição.
*/

#include "screen.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef SCREEN_C_

void displayMessage(char *message) {
	printf("%s", message);
}

void displayMessageLine(char *message) {
	printf("%s\n", message);
}
