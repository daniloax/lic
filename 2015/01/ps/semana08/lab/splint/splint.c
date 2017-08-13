#include <stdio.h>
#include <stdlib.h>

void multiplica (int x, int y, /*@out@*/ int **resultado) {
	
   int i, produto;
   
   i = 0;
   produto = 0;
	
   while (i < y) {
		
      produto += x;
      i++;
      
   }
      
   *resultado = malloc(sizeof(int));
   **resultado = produto;

}
	
int main() {
	
   int x, y, *resultado;
   
   resultado = NULL;
	
   x = 4;
	y = 10;
	
   multiplica(x, y, &resultado);
	printf ( "%d\n", *resultado);
   
   return 0;

}
