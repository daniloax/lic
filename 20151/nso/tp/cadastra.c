#include "cadastra.h"

int main(int argc, char *argv[]) {
   
   char chave[10];
   int status, key = 0x68f60b1, pid;
   
   printf("./%s %s %s\n", argv[0], argv[1], argv[2]);
   // printf("%x\n", key);
   
   /* if (execl("main", "main", (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */

   /** cria semaforo */
   /* if ((idsem = semget(key, 1, IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   } */
   
   // sprintf(chave, "%d", key);
   
   // printf("%s\n", chave);

   /** cria processo filho */
   // pid = fork();
   
   // if (pid == 0) {
      
      /** codigo do filho */
      // v_sem(idsem);
      
      /** executa programa argv[1] */
      // if (execl(argv[1], argv[1], argv[2], chave, (char *) 0) < 0)
      //    printf("erro no execl = %d\n", errno);
         
      // printf("filho - obtive o semaforo, vou dormir\n");
      // sleep(1);
      // printf("filho - dormi\n");
     
      // chave = atoi(argv[2]);
      // printf("%x\n", chave);
   
      /** obtem semaforo */
      /* if ((idsem = semget(chave, 1, 0)) < 0) {
         
         printf("erro na criacao do semaforo\n");
         exit(1);
      
      } */
      
      // printf("%d\n", idsem);
      
      // p_sem(idsem);
      // exit(0);
   
   // }

   /** codigo do pai */
   // v_sem(idsem);
   // printf("pai - obtive o semaforo, vou dormir\n");
   // sleep(1);
   // printf("pai - dormi\n");
   // p_sem(idsem);
   
   // wait(&status);
   
   /** remove semaforo */
   // if (semctl(idsem, 0, IPC_RMID, arg) == -1)
   //   printf ("The semctl call failed!, error number =  %d\n", errno);
   
   // else
   //   printf ("The semctl call succeeded!\n");
   
   /** executa prompt */
   if (execl("prompt", "prompt", (char *) 0) < 0)
      printf("erro no execl = %d\n", errno);
   
   return 0;
   
}
