/**	
*	@file main.c
* 	@brief Programa principal.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

/**
*	Declaração visando identificar o módulo como servidor.
*/

#define MAIN_C_

/**
*	Inclusão de bibliotecas do compilador.
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
*	Inclusão de módulos de definição.
*/

#include "main.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef MAIN_C_

int main() {
   
   int prompt, promptStatus;
   
   /** cria processo */
   if ((prompt = fork()) < 0) {
     
      perror("fork");
      exit(EXIT_FAILURE);
   
   }
   
   if (prompt == 0) {
      
      /** executa prompt */
      if (execl("prompt", "prompt", (char *) 0) < 0) {
         
         perror("execl");
         exit(EXIT_FAILURE);
         
      }
      
   }

   /** aguarda prompt */
   wait(&promptStatus);
   
   /** saida prompt */
   printf("%d exited, status = %d\n\n", prompt, WEXITSTATUS(promptStatus));
   
	return 0;
   
}
