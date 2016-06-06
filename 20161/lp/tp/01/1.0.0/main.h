/**	
*	@file main.h
* 	@brief Arquivo cabeçalho para o programa principal.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef MAIN_H_
#define MAIN_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef MAIN_C_
#define EXT_MAIN_H_
#else
#define EXT_MAIN_H_ extern
#endif

/**
*	Declaração de protótipo de função.
*/

int main();

#undef MAIN_H_

#endif
