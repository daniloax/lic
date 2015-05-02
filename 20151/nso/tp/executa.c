#include "executa.h"

int main(int argc, char *argv[]) {
   
   printf("./%s %s %s\n", argv[0], argv[1], argv[2]);
   sleep(1);
   
   if (execl(argv[1], argv[1], argv[2], (char *) 0) < 0)
      printf("erro no execl = %d\n", errno);

   
   return 0;
   
}
