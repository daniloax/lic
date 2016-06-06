/**	
*	@file keypad.h
*	@brief Arquivo cabeçalho para entrada padrão.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef KEYPAD_C_
#define EXT_KEYPAD_H_
#else
#define EXT_KEYPAD_H_ extern
#endif

/**
*	Declaração de tipo.
*/

char input[64];

/**
*	Declaração de protótipo de função.
*/

void getInput();

#undef KEYPAD_H_

#endif
