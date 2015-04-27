#include "constroi.h"

void ConstroiListaDiscente(ListaDiscente **epinicio) {

   FILE *arquivo;
   char c;
   char nomeArquivo[] = "io/discentes_mestrado.txt";

   arquivo = fopen(nomeArquivo, "r");

   if (!arquivo)
      printf("'%s' not exist\n", nomeArquivo);

   while ((c = getc(arquivo)) != EOF)
      printf("%c", c);

}
