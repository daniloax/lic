#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void createNew(int signal) {
   sleep(1);
}

int main() {
   
   int pid, status, w;
   char *parametro[2];

   parametro[0] = "abc";
   parametro[1] = "def";
   
   signal(SIGUSR1, createNew);
   
   while (1) {
      
      pid = fork();
      
      if (pid < 0) {
         printf("erro no fork\n");
         exit(1);
      }

      if (pid == 0) {
         
         printf("child PID is %ld\n", (long) getpid());

         if (execl("filho", "filho", parametro[1], (char *) 0) < 0)
            printf("erro no execl = %d\n", errno);

      } else {

         w = waitpid(pid, &status, 0);
         
         if (w == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
         }
         
         if (WIFEXITED(status)) {
            printf("exited, status = %d\n", WEXITSTATUS(status));
            kill(getpid(), SIGUSR1);
         }

      }
      
   }

   return 0;

}
