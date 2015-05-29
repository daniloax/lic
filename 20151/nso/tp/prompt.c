#include "prompt.h"

int main(int argc, char *argv[]) {
   
   char *inputs[3], input[64], *inputv;
   int idsem, inputc, key, cadastra, estadoCadastra;
   
   key = atoi(argv[1]);
   
   /** obtem semaforo */
   if ((idsem = semget(key, 1, 0)) < 0) {
      
      perror("semget");
      exit(EXIT_FAILURE);
   
   }
   
   /** exibe prompt */
   while (strcmp(input, "termina") != 0) {
      
      strcpy(input, "\0");

      printf("\n> ");
      scanf("%[^\n]s", input);
      getchar();

      inputv = strtok(input, " ");
      inputc = 0;

      while (inputv != NULL) {
         
         inputs[inputc] = inputv;
         inputv = strtok(NULL, " ");
         inputc++;
      
      }

      /** cria processo */
      if ((cadastra = fork()) < 0) {
        
         perror("fork");
         exit(EXIT_FAILURE);
      
      }
      
      /** cadastra programa */
      if ((cadastra == 0) && (strcmp(inputs[0], "termina") != 0)) {
                  
         if (execl(inputs[0], inputs[0], argv[1], argv[2], inputs[1], inputs[2], (char *) 0) < 0) {
            
            perror("execl");
            exit(EXIT_FAILURE);
            
         }
         
      } else if ((cadastra == 0) && (strcmp(inputs[0], "termina") == 0)) {
         
         exit(0);
         
      }
      
      wait(&estadoCadastra);

   }
      
   return 0;

}
