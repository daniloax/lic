#include <stdio.h>
#include <stdlib.h>

int main () {
	
	FILE *arq;
	char c, nomeArquivo[10];
	int i;
	
	printf("NOME DO ARQUIVO: ");
	scanf("%[^\n]s", nomeArquivo);
	getchar();
	
	arq = fopen(nomeArquivo, "r");
	
	if (!arq)
		printf("'%s' inexistente!\n", nomeArquivo);
	
	while (!feof(arq)) {
		
		fscanf(arq, "%d", &i);
		printf("%d\n", i);
		
		if (fscanf(arq, "%c", &c))
			printf("%c\n", c);
			
	}
	
	fclose(arq);
	
	system("pause");
    return 0;
	
}
