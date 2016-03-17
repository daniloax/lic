#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define RANGE 10

void constroiVetor(int vetor[RANGE]){

    	int i;
	for(i = 0; i<10; i++){
		vetor[i] = rand() % i;
	}//for
}

void ordenaVetor(int vetor[RANGE]){

    int troca =1;
    int aux;
    int i;

	while ( troca ){
		troca=0;
		for (i =0; i<10; i++){
			troca= 1;
			if( vetor[i] > vetor[i + 1]){
				aux = vetor[i+1];
				vetor[i+1] = vetor[i];
				vetor[i] = aux;
			}//if
		}//for
	}//while
}

void mostraVetor(int vetor[RANGE]){

    int i;
	printf("\n");
	for (i=0;i<9;i++){
		printf("%d",vetor[i]);
	}//for
	printf("\n");
}

int main(){
	int vetor[RANGE];
	constroiVetor(vetor);
	ordenaVetor(vetor);
	mostraVetor(vetor);
}

