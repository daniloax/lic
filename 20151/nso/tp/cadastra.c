#include "cadastra.h"

int main(int argc, char *argv[]) {
   
   int estado, pid;
   
   printf("./%s %s %s\n", argv[0], argv[1], argv[2]);
   sleep(1);
   
   /* if (execl("main", "main", (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */

   /* cria semaforo */
   if ((idsem = semget(0x68f60b1, 1, IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   }

   /* cria processo filho */
   pid = fork();
   
   if (pid == 0) {
      
      /* codigo do filho */
      p_sem(idsem);
      
      /* if (execl(argv[1], argv[1], argv[2], (char *) 0) < 0)
         printf("erro no execl = %d\n", errno); */
         
      printf("filho - obtive o semaforo, vou dormir\n");
      sleep(1);
      printf("filho - dormi\n");
      v_sem(idsem);
      
      exit(0);
   
   }
   
   sleep(1);

   /* codigo do pai */
   p_sem(idsem);
   
   /* if (execl(argv[1], argv[1], argv[2], (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */
   
   printf("pai - obtive o semaforo, vou dormir\n");
   sleep(1);
   printf("pai - dormi\n");
   
   v_sem(idsem);
   
   wait(&estado);
   
   if (semctl(idsem, 0, IPC_RMID, arg) == -1) {
      
      printf ("The semctl call failed!, error number =  %d\n", errno);
      exit(0);
      
   } else
      printf ("The semctl call succeeded!\n");
   
   exit (0);
   
   return 0;
   
}
