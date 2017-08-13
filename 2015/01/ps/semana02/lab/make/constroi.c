#include "constroi.h"

void ConstroiMalha(lista1 **epinicio) {
  FILE *arq;
  lista1 *pd1, *pd2;
  lista2 *pp1, *pp2;
  char c, fileName[10];
  int i, n;
  
  do {

    printf("\nEntre com o nome do arquivo: ");
    scanf("%[^\n]s", fileName);
    getchar();

    arq = fopen(fileName, "r");

    if (!arq)
       printf("'%s' not exist\n", fileName);

  } while (!arq);

  *epinicio = NULL;
  
  while ((c = getc (arq)) != EOF) {
    pd1 = malloc (sizeof (lista1));
    pd1->cursado = 0;
    pd1->disc = c;
    pd1->pacesso = NULL;
    pd1->proxd = NULL;
    if (*epinicio == NULL)
      *epinicio = pd1;
    else
      pd2->proxd = pd1;
    pd2 = pd1;
    while ((c = getc (arq)) != '\n');
  }
  fclose (arq);
  arq = fopen (fileName, "r");
  pd1 = *epinicio;
  while ((c = getc (arq)) != EOF) {
    fscanf (arq, "%d ", &n); 
    for (i=1; i !=n+1; i++) {
      c = getc (arq); 
      pp1 = malloc (sizeof (lista2));
      pp1->ppre = *epinicio;
      while (pp1->ppre->disc != c)
        pp1->ppre = pp1->ppre->proxd;
      pp1->proxp = NULL;
      if (pd1->pacesso == NULL)
        pd1->pacesso = pp1;
      else pp2->proxp = pp1;
      pp2 = pp1;
      c = getc (arq);  
    }
    pd1 = pd1->proxd;
  }
}
