#include "main.h"

int main(int argc, char *argv[]) {
   
   int estado, pid;
   
   // printf("%s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
   sleep(1);
   
   pid = fork();
   
   if (pid == 0) {

      sleep(1);
      // pid = fork();
   
      // if (pid == 0) {
      // if (execl(argv[1], argv[1], argv[2], argv[3], (char *) 0) < 0)
         if (execl("prompt", "prompt", (char *) 0) < 0)
            printf("erro no execl = %d\n", errno);
         
      // wait(&estado);
      
      // }
      
   }
   
   wait(&estado);
   
	return 0;
   
}
