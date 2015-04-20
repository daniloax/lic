/*
Declaração visando identificar o módulo como servidor.
*/

#define SERVIDOR_APRESENTACAO

/* 
Inclusão de arquivo com a declaração da interface.
*/

#include <stdio.h>
#include "interface_apresentacao.h"
#include "interface_calculo.h"

void executar(){
     int dado, resultado;
     printf("\nDigite o valor: ");
     scanf("%d", &dado);
     resultado = fatorial(dado);
     if(resultado == ERRO_PARAMETRO)
         printf("\nErro no parametro informado.");
     else
         printf("\nFatorial = %d", resultado);
     printf("\n");
}
