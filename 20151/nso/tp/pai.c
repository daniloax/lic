#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   
   printf("./%s\nsou o programa %s\nprograma: %s\nparametro: %s\n", argv[0], argv[0], argv[1], argv[2]);
   sleep(1);
   
   return 0;
   
}
