/**	
*	@file prompt.h 
*	@brief Arquivo cabeçalho para prompt de comandos.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef PROMPT_H_
#define PROMPT_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef PROMPT_C_
#define EXT_PROMPT_H_
#else
#define EXT_PROMPT_H_ extern
#endif

/** 
*	Inclusão de módulos de definição.
*/

#include "screen.h"

/**
*	Declaração de protótipo de função.
*/

int main();

#undef PROMPT_H_

#endif
