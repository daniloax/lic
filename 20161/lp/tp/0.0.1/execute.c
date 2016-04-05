#include "execute.h"

int main(int argc, char *argv[]) {
   
   int pid, status;
   
	/** cria processo */
	if ((pid = fork()) < 0) {
	  
		perror("fork");
		exit(EXIT_FAILURE);
	
	}

	/** executa programa */
	if (pid == 0) {
		
		printf("%s %s", argv[1], argv[2]);'
					
		/* if (execl(argv[1], argv[1], argv[2], (char *) 0) < 0) {
			
			perror("execl");
			exit(EXIT_FAILURE);
			
		}*/
		
	} else if (pid == 0) {
		
		exit(0);
		
	}
	
	wait(&status);
		
   return 0;
   
}
