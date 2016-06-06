/**	
*	@file screen.h
*	@brief Arquivo cabeçalho para saída padrão.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef SCREEN_H_
#define SCREEN_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef SCREEN_C_
#define EXT_SCREEN_H_
#else
#define EXT_SCREEN_H_ extern
#endif

/**
*	Declaração de protótipo de função.
*/

void displayMessage(char *message);
void displayMessageLine(char *message);

#undef SCREEN_H_

#endif
