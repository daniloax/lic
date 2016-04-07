#include "execute.h"

int main(int argc, char *argv[]) {
   
   int pid, status;
   
	/** cria processo */
	if ((pid = fork()) < 0) {
			
		perror("fork");
		exit(EXIT_FAILURE);

	}
	
	printf("execute: %d\n", getpid());

	/** executa programa */
	if (pid == 0) {
		
		if (execl(argv[1], argv[1], argv[2], (char *) 0) < 0) {
			
			perror("execl");
			exit(EXIT_FAILURE);
			
		}
		
		exit(0);
		
	}

	wait(&status);
		
	return 0;

}
