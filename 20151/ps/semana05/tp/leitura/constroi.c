#include "constroi.h"

void ConstroiListaDiscente(ListaDiscente **epinicio) {

   FILE *pFile;
   
   char c, separador, buffer[72], nome[30], sobreNome[30], nomeArquivo[] = "io/discentes_mestrado.txt";
	int i, ano, matricula, tamanhoBuffer, retornoSScanf;

   pFile = fopen(nomeArquivo, "r");

   if (!pFile)
      printf("'%s' not exist\n", nomeArquivo);

   else {

		while ((fgets(buffer, sizeof(buffer), pFile)) != NULL ) {
		// while ((c = fgetc(pFile)) != EOF) {
		
			retornoSScanf = sscanf(buffer,"%d%c%d%s %s", &ano, &separador, &matricula, nome, sobreNome);
			
			if (retornoSScanf == 5) {
				printf("%d\n", retornoSScanf);
				printf("%02d%c%07d %s %s\n", ano, separador, matricula, nome, sobreNome);
			}
			
			tamanhoBuffer = strlen(buffer);
			// printf("%d\n", tamanhoBuffer);
			
			for (i = 0; i < tamanhoBuffer; i++) {
				printf("%c", buffer[i]);
			}
			
			while ((c = fgetc(pFile)) != 10);
			
		// ReadStuff ( pFile, "%d%c%d    %*s", &ano, &separador, &matricula, nome);
		// printf("%02d%c%07d    %*s\n", ano, separador, matricula, nome);
		}
		
	}
	
	// while ((fgets(buffer, sizeof(buffer), pFile)) != NULL ) {
	// while ((fgetc(pFile)) != EOF) {
	// sscanf(buffer,"%d%c%d", &ano, &separador, &matricula);
	// GetMatches(buffer, "%d%c%d", &ano, &separador, &matricula);
	// ReadStuff ( pFile, "%d%c%d    %*s", &ano, &separador, &matricula);
	// printf("%02d%c%07d    %*s\n", ano, separador, matricula);

	// }

	// printf ("I have read %s, %d and %d", str, ano, matricula);

	fclose (pFile);

	return 0;

}
