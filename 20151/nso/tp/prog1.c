#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	int pid;
   char *parametro[2];
   
   parametro[0] = "abc";
   parametro[1] = "def";
   
   pid = fork();

	if (pid < 0) {
		printf("erro no fork\n");
		exit(1);
	}

	if (pid == 0) {
		
		if (execl("filho", "filho", parametro[1], (char *) 0) < 0)
         printf("erro no execl = %d\n", errno);
	
	} else {
		
		if (execl("pai", "pai", parametro[0], (char *) 0) < 0)
         printf("erro no execl = %d\n", errno);
		
	
	}

	return 0;

}
