#include "prompt.h"

void exibePrompt() {

   char *args[3], *argv, *input;
   int argc;
   
   while (1) {

      printf("\n> ");
      scanf("%[^\n]s", input);
      getchar();
      printf("%s\n", input);
      
      if (input == NULL)
         printf("%s not found. please try again.\n", input);
         
      else {
         
         argc = 0;
         argv = strtok(input, " ");

         while (argv != NULL) {
            
            args[argc] = argv;
            
            printf("argv[%d]: ", argc);
            printf("%s\n", argv);
            
            argv = strtok(NULL, " ");
            argc++;
         
         }
         
         printf("programa: %s\nparametro: %s\n", args[1], args[2]);
         
         if (execl(args[0], args[0], args[1], args[2], (char *) 0) < 0)
               printf("erro no execl = %d\n", errno);
         
         
      }

   }

}
