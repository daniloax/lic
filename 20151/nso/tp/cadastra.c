#include "cadastra.h"

void p_sem() {
   
   operacao[0].sem_num = 0;
   operacao[0].sem_op = 0;
   operacao[0].sem_flg = 0;
   operacao[1].sem_num = 0;
   operacao[1].sem_op = 1;
   operacao[1].sem_flg = 0;
   
   if (semop(idsem, operacao, 2) < 0)
      printf("erro no p=%d\n", errno);

}

void v_sem() {
   
   operacao[0].sem_num = 0;
   operacao[0].sem_op = -1;
   operacao[0].sem_flg = 0;
   
   if (semop(idsem, operacao, 1) < 0)
      printf("erro no p=%d\n", errno);
      
}

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
      p_sem();
      printf("filho - obtive o semaforo, vou dormir\n");
      sleep(1);
      
      if (execl("executa", "executa",  argv[1], argv[2], (char *) 0) < 0)
         printf("erro no execl = %d\n", errno);
      
      printf("filho - dormi\n");
      v_sem();
      exit(0);
   
   }

   /* codigo do pai */
   p_sem();
   printf("pai - obtive o semaforo, vou dormir\n");
   sleep(1);
   
   // if (execl(argv[0], argv[0], argv[1], argv[2], (char *) 0) < 0)
      // printf("erro no execl = %d\n", errno);
      
   printf("pai - dormi\n");
   v_sem();

   wait(&estado);
   
   exit (0);
   
   return 0;
   
}
