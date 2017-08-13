/**	
*	@file execute.h
*	@brief Arquivo cabeçalho para execução de programas.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Controle visando evitar inclusões múltiplas.
*/

#ifndef EXECUTE_H_
#define EXECUTE_H_

/**
*	Controle visando identificar o servidor.
*/

#ifdef EXECUTE_C_
#define EXT_EXECUTE_H_
#else
#define EXT_EXECUTE_H_ extern
#endif

/**
*	Declaração de protótipo de função.
*/

int main(int argc, char *argv[]);

#undef EXECUTE_H_

#endif
