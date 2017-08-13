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
   
   char *args[2], buffer[1024];
   int fd[2], pid, status;
   
   printf("execute: %d\n", getpid());
	printf("argc: %d\n", argc);
	printf("argv[1]: %s\n", argv[1]);
	printf("argv[2]: %s\n", argv[2]);
   
	if ((pipe(fd)) < 0) {

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
		
		printf("child: %d\n", getpid());
		printf("argv[1]: %s\n", argv[1]);
		printf("argv[2]: %s\n", argv[2]);
		
		/** fecha pipe de leitura */
		close(fd[0]);           
		
		/** envia saida padrao para o pipe */
		dup2(fd[1], 1);
		
		/** fecha pipe de escrita */
		close(fd[1]);
		
		/** localiza argv[1] */
		if (execl("/usr/bin/whereis", "whereis", argv[1], (char *) 0) < 0) {
			
			perror("execl");
			exit(EXIT_FAILURE);
			
		}
		
		exit(0);
		
	}
	
	wait(&status);

	/** fecha pipe de escrita */
	close(fd[1]);
	
	/** le pipe de leitura   */
	int len = read(fd[0], buffer, sizeof(buffer));
	
	if (len < 0) {

		perror("read error");

	} else {

		buffer[len] = 0;
		printf("Buffer received: %s\n", buffer);

	}
	
	/** fecha pipe de leitura */
	close(fd[0]);
	
	args[0] = strtok(buffer, ":");
	args[1] = strtok(NULL, " ");
	
	printf("whereis %s: %s", args[0], args[1]);	
	
	/** cria processo */
	if ((pid = fork()) < 0) {
			
		perror("fork");
		exit(EXIT_FAILURE);

	}
	
	/** executa programa */
	if (pid == 0) {
		
		printf("execute child: %d\n", getpid());
		printf("%s %s\n", argv[1], argv[2]);
		
		/** executa args[1] */
		if (execl(args[1], args[1], argv[2], (char *) 0) < 0) {
			
			perror("execl");
			exit(EXIT_FAILURE);
			
		}
		
		exit(0);
		
	}
	
	wait(&status);
	
	return 0;

}
