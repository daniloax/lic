#include "main.h"

int main(int argc, char *argv[]) {
   
   char *chave[10];
   int idsem, key = 0x68f60b1, pid, status;
   
   /** cria semaforo */
   /* if ((idsem = semget(key, 1, IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   } */
   
   // sprintf(chave, "%d", key);   
   
   if (( pid = fork()) < 0) {
     
     printf("erro no fork\n");
     exit(1);
   
   }
   
   if (pid == 0) {
      
      /** codigo do filho */
      /* v_sem(idsem);
      
      printf("filho - obtive o semaforo, vou dormir\n");
      sleep(1);
      printf("filho - dormi\n");
      
      p_sem(idsem);
      exit(0); */
      
      if (execl(argv[1], argv[1], (char *) 0) < 0)
         printf("erro no execl = %d\n", errno);
      
   }
   
   /** codigo do pai */
   /* v_sem(idsem);
   
   printf("pai - obtive o semaforo, vou dormir\n");
   sleep(1);
   printf("pai - dormi\n");
   
   p_sem(idsem); */

   wait(&status);
   
	return 0;
   
}
