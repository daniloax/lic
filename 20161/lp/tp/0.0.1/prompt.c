/**	
*	@file main.c
* 	@brief Prompt de comandos.
*	@author Danilo Alves.
*	@since 14/04/16.
*	@version 1.0.
*
*/

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
*	Declaração visando identificar o módulo como servidor.
*/

#define PROMPT_C_

/** 
*	Inclusão de módulos de definição.
*/

#include "prompt.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef PROMPT_C_

int main() {
   
   char *args[2], *argv, *buf, *ptr;
   int argc, execute, executeStatus;
   long size;
   
   size = pathconf(".", _PC_PATH_MAX);
	
	if ((buf = (char *)malloc((size_t)size)) == NULL)
		perror("malloc");
   
   /** exibe prompt */
   while (strcmp(input, "exit") != 0) {
		
		ptr = getcwd(buf, (size_t)size);
      strcpy(input, "\0");

      printf("\n%s$ ", ptr);
      getInput();

      argv = strtok(input, " ");
      argc = 0;

      while (argv != NULL) {
         
         args[argc] = argv;
         argv = strtok(NULL, " ");
         argc++;
      
      }

      /** cria processo */
      if ((execute = fork()) < 0) {
        
         perror("fork");
         exit(EXIT_FAILURE);
      
      }
      
      printf("prompt: %d\n", getpid());
      
      /** executa programa */
      if ((execute == 0) && (strcmp(args[0], "exit") != 0)) {
                  
         if (execl("execute", "execute", args[0], args[1], (char *) 0) < 0) {
            
            perror("execl");
            exit(EXIT_FAILURE);
            
         }
         
      } else if ((execute == 0) && (strcmp(args[0], "exit") == 0)) {
         
         exit(0);
         
      }
      
      wait(&executeStatus);

   }
      
   return 0;

}
