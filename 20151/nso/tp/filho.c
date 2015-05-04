#include "filho.h"

int main(int argc, char *argv[]) {
   
   int chave;
   
   printf("./%s %s %s\n", argv[0], argv[1], argv[2]);
   printf("filho - obtive o semaforo, vou dormir\n");
   sleep(1);
   printf("filho - dormi\n");
   chave = atoi(argv[2]);
   printf("%x\n", chave);
   
   /* obtem semaforo */
   if ((idsem = semget(chave, 1, 0)) < 0) {
      
      printf("erro na criacao do semaforo\n");
      exit(1);
   
   }
   printf("%d\n", idsem);
   v_sem(idsem);
   
   return 0;
   
}
