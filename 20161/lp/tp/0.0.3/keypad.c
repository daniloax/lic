/**	
*	@file execute.c
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

#define KEYPAD_C_

/** 
*	Inclusão de módulos de definição.
*/

#include "keypad.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef KEYPAD_C_

void getInput() {
	scanf("%[^\n]s", input);
   getchar();		
}
