/*
Declaração visando identificar o módulo como servidor.
*/

#define SERVIDOR_CALCULO

/* 
Inclusão de arquivo com a declaração da interface.
*/

#include "interface_calculo.h"

/*
Definição do corpo da função.
*/

int fatorial(int valor) {
    int n;
    int resultado = 1;
    
    if (valor < 0)
       return ERRO_PARAMETRO;        
    for(n = 1; n <= valor; n++) {
       resultado *= n;
    }
    return resultado;
}
