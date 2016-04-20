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
   
   char *args[3], *argv, *buf, input[64], *ptr;
   int argno, execute, executeStatus;
   long size;
   
   size = pathconf(".", _PC_PATH_MAX);
   
   displayMessageLine("");
   displayMessageLine("Programming Languages SHell 0.0.1 (Apr 14 2016)");
	displayMessageLine("[GCC 4.9.2] on linux2");
	displayMessageLine("Type \"help\" or \"man\" for more information.");
	
	if ((buf = (char *)malloc((size_t)size)) == NULL)
		perror("malloc");
   
   /** exibe prompt */
   while (strcmp(input, "quit") != 0) {
		
		args[0] = NULL;
		args[1] = NULL;
		args[2] = NULL;
		
      strcpy(input, "\0");
      
      ptr = getcwd(buf, (size_t)size);
      
		displayMessage("\n");
		displayMessage(ptr);
		displayMessage("$ ");

      scanf("%[^\n]s", input);
		getchar();
		
 		argno = 0;
		argv = strtok(input, " ");
		
		while (argv != NULL) {
			
			args[argno] = argv;
			argv = strtok(NULL, " ");
			argno++;
		
		}
		
		/** altera diretorio */
		if ((strcmp(args[0], "cd") == 0)  && (args[1] != NULL)) {
			
			if (chdir(args[1]) < 0) {
				
				perror("chdir");
			
			}
			
		} else if ((strcmp(args[0], "cd") == 0)  && (args[1] == NULL)) {
			
			if (chdir(args[1]) < 0) {
				
				perror("chdir");
			
			}
			
		/** exibe ajuda */
		} else if (strcmp(args[0], "help") == 0) {
									
			displayMessageLine("");
			displayMessageLine("List of classes of commands:");
			displayMessageLine("");
			displayMessageLine("cd -- altera diretório de trabalho");
			displayMessageLine("pwd -- imprime o caminho do diretório corrente");
			displayMessageLine("cat -- concatena arquivos e imprime na saída padrão");
			displayMessageLine("ls -- lista o conteúdo do diretório");
			displayMessageLine("mkdir -- cria diretórios");
			displayMessageLine("rmdir -- remove diretórios vazios");
			displayMessageLine("find -- procura por arquivo em uma hierarquia de diretórios");
			displayMessageLine("who -- exibe que está logado");
			displayMessageLine("");
			displayMessageLine("quit -- sai do interpretador de comandos PLSH");
				
		} else {
		
			/** cria processo */
			if ((execute = fork()) < 0) {
			  
				perror("fork");
				exit(EXIT_FAILURE);
			
			}
			
			if ((execute == 0) && (strcmp(args[0], "quit") != 0)) {
				
				/** exibe manual */
				if ((strcmp(args[0], "man") == 0) && (args[1] == NULL)) {
					
					if (execl("/usr/bin/less", "less", "PLSH.txt", (char *) 0) < 0) {
									
						perror("execl");
						exit(EXIT_FAILURE);
						
					}
					
				/** executa programa */
				} else {
							
					if (execl("execute", "execute", args[0], args[1], args[2], (char *) 0) < 0) {
									
						perror("execl");
						exit(EXIT_FAILURE);
						
					}
					
				}
				
			} else if ((execute == 0) && (strcmp(input, "quit") == 0)) {
					
					displayMessageLine("");
					displayMessageLine("Bye bye...");
					displayMessageLine("");
					exit(0);
					
			}
			
			/** aguarda execute */
			wait(&executeStatus);
			
		}

   }
      
   return 0;

}
