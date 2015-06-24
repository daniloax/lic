/**	
*	@file mod_impl_docente.c 
*	@brief Módulo que faz a leitura dos docentes.
*	@author Danilo Alves.
* 	@author José Siqueira.
*	@since 01/03/15.
*	@version 1.0.
*
*/

/* 
Inclusão de biblioteca do compilador.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Declaração visando identificar o módulo como servidor.
*/

#define MOD_IMPL_DOCENTE

/* 
Inclusão de módulo de definição.
*/

#include "mod_def_docente.h"

/* 
Termina processamento de módulo de implementação.
*/

#undef MOD_IMPL_DOCENTE

/*
Definição de corpo de função.
*/

/**
* Uma função que retorna a lista de docentes.
* @param *pinicio um ponteiro para o inicio da lista de discentes.
* @return sem retorno.
*/
void getListaDocente(ListaDocente *pinicio) {

}

/**
* Uma função que constroi uma lista de docentes a partir do arquivo de entrada.
* @param **epinicio o endereco do ponteiro da lista de discentes.
* @param *arquivo um array de caracteres que contem o nome do arquivo.
* @return sem retorno.
*/
void setListaDiscente(ListaDiscente **epinicio, char *arquivo) {

}
