#include "executa.h"

int main(int argc, char *argv[]) {
   
   int idmsq, idsem, key, pid, estado, w, msgrcvreturn;
   
   key = atoi(argv[1]);
   w = 0;
   
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
   
   while (1) {
            
      if ((msgrcv(idmsq, &mensagem_rec, sizeof(mensagem_rec) - sizeof(long), 0, IPC_NOWAIT) < 0) && (w == 0))
         sleep(1);
         
      else {
      
         /** cria processo */
         if ((pid = fork()) < 0) {
           
            perror("fork");
            exit(EXIT_FAILURE);
         
         }

         /** executa comando */
         if (pid == 0) {
            
            // printf("child PID is %ld\n", (long) getpid());

            if (execl(mensagem_rec.executa, mensagem_rec.executa, argv[1], mensagem_rec.parametro, (char *) 0) < 0) {
               
               perror("execl");
               exit(EXIT_FAILURE);
               
            }
            
         } else {
            
            mensagem_env.pid = pid;
            strcpy(mensagem_env.executa, mensagem_rec.executa);
            msgsnd(idmsq, &mensagem_env, sizeof(mensagem_env) - sizeof(long), IPC_NOWAIT);
            
            w = waitpid(pid, &estado, 0);
            
            if (w == -1) {
               perror("waitpid");
               exit(EXIT_FAILURE);
            }
            
            if (WIFEXITED(estado)) {
               // printf("exited, status = %d\n", WEXITSTATUS(estado));
               sleep(1);
            }
            
         }
         
      }
      
   }
   
   return 0;
   
}
