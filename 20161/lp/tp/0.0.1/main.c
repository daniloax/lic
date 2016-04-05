#include "main.h"

int main() {
   
   int prompt, promptStatus;
   
   /** cria processo */
   if ((prompt = fork()) < 0) {
     
      perror("fork");
      exit(EXIT_FAILURE);
   
   }
   
   if (prompt == 0) {
      
      /** executa prompt */
      if (execl("prompt", "prompt", (char *) 0) < 0) {
         
         perror("execl");
         exit(EXIT_FAILURE);
         
      }
      
   }

   /** aguarda prompt */
   wait(&promptStatus);
   
   /** saida prompt */
   printf("%d exited, status = %d\n\n", prompt, WEXITSTATUS(promptStatus));
   
	return 0;
   
}
