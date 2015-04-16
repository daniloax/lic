#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int pid;

	pid = fork();

   if (pid == 0)
     printf("child: %d\n", pid);

   else {
		sleep(1);     
		printf("father: %d\n", pid);
   }

	return 0;

}
