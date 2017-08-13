#include "Input.h"
#include "Listas.h"

int main(){
	
   Lista *inicio;
	char *c;
	int *tamanho;
	
   Inicia(&inicio);
	
   while ( Tem_Input(3) ){
		c = Get_C( &tamanho );
		Insere(&inicio, c, tamanho);
	}
	
   Mostra(inicio);
	
   return 0;
}
