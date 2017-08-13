#include "cadastra.h"

int main(int argc, char *argv[]) {
   
   int idmsq, idsem, key;
   
   key = atoi(argv[1]);
   
   /** obtem fila */
   if ((idmsq = msgget(key, 0x180)) < 0) {
     
      perror("msgget");
      exit(EXIT_FAILURE);
   
   }
   
   /** obtem semaforo */
   if ((idsem = semget(key, 1, 0)) < 0) {
      
      perror("semget");
      exit(EXIT_FAILURE);
   
   }
   
   /** produz mensagem */
   mensagem_env.pid = getpid();
   strcpy(mensagem_env.executa, argv[3]);
   strcpy(mensagem_env.parametro, argv[4]);
   
   /** envia mensagem */
   msgsnd(idmsq, &mensagem_env, sizeof(mensagem_env) - sizeof(long), IPC_NOWAIT);
   msgrcv(idmsq, &mensagem_rec, sizeof(mensagem_rec) - sizeof(long), 0, 0);
   
   printf("%ld %s\n", (long) mensagem_rec.pid, mensagem_rec.executa);
   
   return 0;
   
}
