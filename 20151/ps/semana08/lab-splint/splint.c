#include<stdio.h>

int multiplica ( int x, int *y, /*@out@*/ int *resultado) {
   
   int i, produto;
   
   while(i < y) {
      produto += x;
   }
   
   return produto;

}


int main(){

   int x, *y, resultado;
   
   x = 4;
   *y = 3;
   multiplica(x, y, &resultado);
   printf ( "%d", resultado );
   
   return 0;

}
