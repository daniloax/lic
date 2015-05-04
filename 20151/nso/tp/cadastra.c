#include "cadastra.h"

int main(int argc, char *argv[]) {
   
   char chave[10];
   int estado, key = 0x68f60b1, pid;
   
   printf("./%s %s %s\n", argv[0], argv[1], argv[2]);
   printf("%x\n", key);
   
   sleep(1);
   
   /* if (execl("main", "main", (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */

   /* cria semaforo */
   if ((idsem = semget(key, 1, IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   }
   
   // itoa(idsem, semid, 10);
   sprintf(chave, "%d", key);
   
   printf("%s\n", chave);

   /* cria processo filho */
   pid = fork();
   
   if (pid == 0) {
      
      /* codigo do filho */
      p_sem(idsem);
      
      if (execl(argv[1], argv[1], argv[2], chave, (char *) 0) < 0)
         printf("erro no execl = %d\n", errno);
   
   }
   
   sleep(1);

   /* codigo do pai */
   p_sem(idsem);
   
   if (execl("pai", "pai", argv[2], chave, (char *) 0) < 0)
      printf("erro no execl = %d\n", errno);
   
   wait(&estado);
   
   if (semctl(idsem, 0, IPC_RMID, arg) == -1) {
      
      printf ("The semctl call failed!, error number =  %d\n", errno);
      exit(0);
      
   } else
      printf ("The semctl call succeeded!\n");
   
   exit (0);
   
   return 0;
   
}
