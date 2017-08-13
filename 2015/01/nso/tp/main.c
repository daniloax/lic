#include "main.h"

int main() {
   
   struct shmid_ds *shmbuf;
   struct msqid_ds *msqbuf;
   
   char chave[10], shmid[10];
   int executa, idmsq, idsem, idshm, key = 0x68f60b1, prompt, estadoExecuta, estadoPrompt;
   
   shmbuf = NULL;
   msqbuf = NULL;
   
   /** cria semaforo */
   if ((idsem = semget(key, 1, IPC_CREAT|0x180)) < 0) {
      
      perror("semget");
      exit(EXIT_FAILURE);
   
   }
   
   /** cria memoria */
   if ((idshm = shmget(key, sizeof(int), IPC_CREAT|0x180)) < 0) {
      
      perror("shmget");
      exit(EXIT_FAILURE);
      
   }
   
   /** cria fila */
   if ((idmsq = msgget(key, IPC_CREAT|0x180)) < 0) {
     
      perror("msgget");
      exit(EXIT_FAILURE);
   
   }
   
   sprintf(chave, "%d", key);
   sprintf(shmid, "%d", idshm);
   
   v_sem(idsem);
   
   /** cria processo */
   if ((executa = fork()) < 0) {
     
      perror("fork");
      exit(EXIT_FAILURE);
   
   }
   
   if (executa == 0) {
      
      /** executa processo */
      if (execl("executa", "executa", chave, shmid, (char *) 0) < 0) {
         
         perror("execl");
         exit(EXIT_FAILURE);
      
      }
      
   }
   
   /** cria processo */
   if ((prompt = fork()) < 0) {
     
      perror("fork");
      exit(EXIT_FAILURE);
   
   }
   
   if (prompt == 0) {
      
      /** executa processo */
      if (execl("prompt", "prompt", chave, shmid, (char *) 0) < 0) {
         
         perror("execl");
         exit(EXIT_FAILURE);
         
      }
      
   }
   
   p_sem(idsem);
   
   /** aguarda prompt */
   wait(&estadoPrompt);
   
   /** finaliza executa */
   kill(executa, SIGKILL);
   
   /** aguarda executa */
   wait(&estadoExecuta);
   
   /** saida prompt */
   printf("\n%d exited, status = %d\n", executa, WEXITSTATUS(estadoExecuta));
   
   /** saida executa */
   printf("%d exited, status = %d\n\n", prompt, WEXITSTATUS(estadoPrompt));
   
   /** remove memoria */
   if ((shmctl(idshm, IPC_RMID, shmbuf)) == -1) {
      perror("shmctl");
      exit(EXIT_FAILURE);
   }
   
   /** remove semaforo */
   if (semctl(idsem, 0, IPC_RMID, arg) == -1) {
      perror("semctl");
      exit(EXIT_FAILURE);
   }
      
   /** remove fila */
   if (msgctl(idmsq, IPC_RMID, msqbuf) == -1) {
      perror("msgctl");
      exit(EXIT_FAILURE);
   }
   
	return 0;
   
}
