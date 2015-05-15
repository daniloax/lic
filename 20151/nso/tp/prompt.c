#include "prompt.h"

int main() {
   
   struct shmid_ds *buf;
   
   char *args[3], *argv, chave[10], input[64], *pshm;
   int argc, idsem, idshm, key = 0x68f60b1, pid, status;
   
   /* printf("sou o programa %s\nparametro 1: %s\nparametro 2: %s\nparametro 3: %s\n", argv[0], argv[1], argv[2], argv[3]);
   sleep(1);
   
   if (execl(argv[1], argv[1], argv[2], argv[3], (char *) 0) < 0)
      printf("erro no execl = %d\n", errno); */
      
   sprintf(chave, "%d", key);
    
   /** cria semaforo */
   if ((idsem = semget(key, 1, IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   }
   
   /** cria memoria */
   if ((idshm = shmget(key, sizeof(int), IPC_CREAT|0x1ff)) < 0) {
      
      printf("erro na criacao da memoria\n");
      exit(1);
      
   }
   
   /** obtem semaforo */
   /* if ((idsem = semget(key, 1, 0)) < 0) {
      printf("erro ao obter semaforo\n");
      exit(1);
   } */
   
   /** cria processo filho */
   pid = fork();
   
   if (pid == 0) {
         
      // if (execl("executa", "executa", chave, (char *) 0) < 0)
      //   printf("erro no execl = %d\n", errno);
      
      while (1) {
      
         /** obtem semaforo */
         
         v_sem(idsem);
         
         /** attach */
         pshm = shmat(idshm, (char *) 0, 0);
         
         printf("filho - obtive o semaforo, vou dormir\n");
         sleep(1);
         printf("filho - dormi\n");
         sleep(1);
         printf("filho - valor lido = %s\n", pshm);
         
         p_sem(idsem);
         
      }
      
      /** detach */
      if (shmdt(pshm) == -1)
         printf("The shmdt call failed!, error number = %d\n", errno);

      else
         printf("The shmdt call succeeded!\n");
      
      exit(0);
      
      // if (execl("executa", "executa", chave, (char *) 0) < 0)
      //   printf("erro no execl = %d\n", errno);
      
   }
   
   /* v_sem(idsem);
   
   printf("pai - obtive o semaforo, vou dormir\n");
   sleep(1);
   printf("pai - dormi\n");
   
   p_sem(idsem); */
   
   /** codigo do pai */
   
   /** attach */
   pshm = shmat(idshm, (char *) 0, 0);
   
   if (*pshm == -1) {
      
      printf("erro no attach\n");
      exit(1);
   
   }
   
   while (strcmp(input, "termina") != 0) {
      
      v_sem(idsem);
      
      printf("pai - obtive o semaforo, vou dormir\n");
      sleep(1);
      printf("pai - dormi\n");
      sleep(1);
      printf("pai - vou escrever\n");
      sleep(1);
      
      input[0] = "\0";

      printf("\n> ");
      scanf("%[^\n]s", input);
      getchar();
      // printf("%s\n", input);

      argv = strtok(input, " ");
      argc = 0;

      while (argv != NULL) {
         
         args[argc] = argv;
         
         // printf("argv[%d]: ", argc);
         // printf("%s\n", argv);
         
         argv = strtok(NULL, " ");
         argc++;
      
      }
      
      *pshm = calloc(strlen(input), sizeof(char));
      strcpy(pshm, input);
      
      printf("\npai - escrevi\n");
      sleep(1);
      
      // if (execl(args[0], args[0], args[1], args[2], (char *) 0) < 0)
      //   printf("erro no execl = %d\n", errno);
      
      p_sem(idsem);
         
   }
   
   wait(&status);
   
   /** desvincula memoria compartilhada */
	if (shmdt(pshm) == -1)
		printf("\nThe shmdt call failed!, error number = %d\n", errno);

	else
		printf("The shmdt call succeeded!\n");
   
   /** remove semaforo */
   if (semctl(idsem, 0, IPC_RMID, arg) == -1)
      printf("The semctl call failed!, error number = %d\n", errno);
   
   else
      printf("The semctl call succeeded!\n");
      
   /** remove memoria compartilhada */
   if ((shmctl(idshm, IPC_RMID, buf)) == -1)
		printf("The shmctl call failed!, error number = %d\n", errno);
   
   else
      printf("The shmctl call succeeded!\n");
   
   return 0;

}
