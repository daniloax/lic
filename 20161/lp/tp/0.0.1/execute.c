/**	
*	@file execute.c
*	@brief Execução de programas.
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

#define EXECUTE_C_

/** 
*	Inclusão de módulos de definição.
*/
#include "execute.h"

/** 
*	Término de processamento de módulo de implementação.
*/

#undef EXECUTE_C_

int main(int argc, char *argv[]) {
   
   int pipe_fd[2], pid, status;
   char buffer[32];
   
   if (pipe(pipe_fd) < 0) {
		perror("pipe");
      exit(EXIT_FAILURE);
	}
   
	/** cria processo */
	if ((pid = fork()) < 0) {
			
		perror("fork");
		exit(EXIT_FAILURE);

	}
	
	/** localiza programa */
	if (pid == 0) {
		
		printf("i'm the child used for whereis\nmy pid is %d\n", getpid());
		dup2(pipe_fd[1], STDOUT_FILENO);
		
		if (execl("/usr/bin/whereis", "/usr/bin/whereis", argv[1], (char *) 0) < 0) {
			
			perror("execl");
			exit(EXIT_FAILURE);
			
		}
		
	}
	
	wait(&status);
	
	printf("i'm in the excecute process, which will be used to run whereis stdout\nmy pid is %d\n", getpid());
	
	if (read(pipe_fd[1], buffer, sizeof(buf)) < 0) {
		perror("read");
      exit(EXIT_FAILURE);
   }
   
   close(pipe_fd[1]);
	
	printf("whereis %s: %s\n", argv[1], buffer);
	
	
	
	return 0;

}
