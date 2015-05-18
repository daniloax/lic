#include<stdio.h>
void multiplica ( int x, int *y, int *resultado ){
	int i, produto;	
	while( i < y){
		produto += x;
	}
	return produto;
}
	

int main(){
	int x, *y, resultado;
	x = 4;
	*y = 3;
	multiplica( x, y, &resultado);
	printf ( "%d", resultado );

}
