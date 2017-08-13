
/**	
*	@file help.h
*	@brief Arquivo cabeçalho para ajuda.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef HELP_H_
#define HELP_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef HELP_C_
#define EXT_HELP_H_
#else
#define EXT_HELP_H_ extern
#endif

#undef KEYPAD_H_

int main(int argc, char *argv[]);

#endif
