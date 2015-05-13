#include "executa.h"

int main(int argc, char *argv[]) {
   
   char chave[10];
   int status, pid, semid;
   
   // printf("./%s\n", argv[0]);
   // printf("%s\n", argv[1]);
   // sprintf(chave, "%d", argv[1]);
   
   /** obtem semaforo */
   /* if ((idsem = semget(chave, 1, 0)) < 0) {
      
      printf("erro ao obter semaforo\n");
      exit(1);

   } */
   
   /** cria processo filho */
   /* pid = fork();
   
   if (pid == 0) {
      
      v_sem(idsem);
      
      printf("filho - obtive o semaforo, vou dormir\n");
      sleep(1);
      printf("filho - dormi\n");
      
      p_sem(idsem);
      
      exit(0);
      
   } */
   
   /** codigo do pai */
   /* v_sem(idsem);
   
   printf("pai - obtive o semaforo, vou dormir\n");
   sleep(1);
   printf("pai - dormi\n");
   
   p_sem(idsem);
   
   wait(&status); */
   
   while (1) {
      sleep(1);
   }
   
   return 0;
   
}
