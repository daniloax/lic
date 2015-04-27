/*
Declara��o visando identificar o m�dulo como servidor.
*/

#define SERVIDOR_CALCULO

/* 
Inclus�o de arquivo com a declara��o da interface.
*/

#include "interface_calculo.h"

/*
Defini��o do corpo da fun��o.
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
