#include "prompt.h"

int main() {
   
   /* printf("sou o programa %s\nparametro 1: %s\nparametro 2: %s\nparametro 3: %s\n", argv[0], argv[1], argv[2], argv[3]);
   sleep(1);
   
   if (execl(argv[1], argv[1], argv[2], argv[3], (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */

   char *args[3], *argv, input[64];
   int argc;
   
   while (1) {

      printf("\n> ");
      scanf("%[^\n]s", input);
      getchar();
      printf("%s\n", input);

      argv = strtok(input, " ");
      argc = 0;

      while (argv != NULL) {
         
         args[argc] = argv;
         
         // printf("argv[%d]: ", argc);
         // printf("%s\n", argv);
         
         argv = strtok(NULL, " ");
         argc++;
      
      }
      
      if (execl(args[0], args[0], args[1], args[2], (char *) 0) < 0)
            printf("erro no execl = %d\n", errno);
         

   }
   
   return 1;

}
