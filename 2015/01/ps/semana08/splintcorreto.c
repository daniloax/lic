#include<stdio.h>
#include<stdlib.h>
static void multiplica ( int x, int /*@in@*/ *y, int /*@out@*/ *resultado ){
	int i = 0, produto = 0;	
	while( i < *y){
		produto += x;
		i++;
	}
	*resultado = produto;
}
	

int main(){
	int x, *y, resultado;
	x = 4;
	y = malloc( sizeof (int));
	if ( y != NULL ){
		*y = 3;
		multiplica( x, y, &resultado);
		printf ( "%d", resultado );
	}
	free (y);
	return 0;
}
