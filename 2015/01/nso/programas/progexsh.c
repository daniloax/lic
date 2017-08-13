#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

   int estado, idshm, pid, *pshm;
   struct shmid_ds buf;

   /* cria memoria */
   if ((idshm = shmget(0x68f60b1, sizeof(int), IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao da fila\n");
      exit(1);
      
   }

   /* cria processo filho */
   pid = fork();
   
   if (pid == 0) {
      
      /* codigo do filho */
      pshm = (int *) shmat(idshm, (char *) 0, 0);
      
      if (pshm == (int *) - 1) {
         
         printf("erro no attach\n");
         exit(1);
   
      }

      printf("vou escrever\n");
      *pshm = 334;
      exit(0);
   
   }

   /* codigo do pai */
   pshm = (int *) shmat(idshm, (char *) 0, 0);
   
   if (*pshm == -1) {
      
      printf("erro no attach\n");
      exit(1);
   
   }

   sleep(1);
   printf("pai - numero lido = %d\n", *pshm);

   wait(&estado);
   exit (0);

}

