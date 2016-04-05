#include "prompt.h"

int main() {
   
   char *args[2], *argv, *buf, *ptr, input[64];
   int argc, execute, executeStatus;
   long size;
   
   size = pathconf(".", _PC_PATH_MAX);
	
	if ((buf = (char *)malloc((size_t)size)) == NULL)
		perror("malloc");
   
   /** exibe prompt */
   while (strcmp(input, "exit") != 0) {
		
		ptr = getcwd(buf, (size_t)size);
      strcpy(input, "\0");

      printf("\n%s$ ", ptr);
      scanf("%[^\n]s", input);
      getchar();

      argv = strtok(input, " ");
      argc = 0;

      while (argv != NULL) {
         
         args[argc] = argv;
         argv = strtok(NULL, " ");
         argc++;
      
      }

      /** cria processo */
      if ((execute = fork()) < 0) {
        
         perror("fork");
         exit(EXIT_FAILURE);
      
      }
      
      /** executa programa */
      if ((execute == 0) && (strcmp(args[0], "exit") != 0)) {
                  
         if (execl("execute", "execute", args[0], args[1], args[2], (char *) 0) < 0) {
            
            perror("execl");
            exit(EXIT_FAILURE);
            
         }
         
      } else if ((execute == 0) && (strcmp(args[0], "exit") == 0)) {
         
         exit(0);
         
      }
      
      wait(&executeStatus);

   }
      
   return 0;

}
