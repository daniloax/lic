void ConstroiListaAS2(listaS **epinicio) {
  FILE *arq1;
  listaS *p1, *p2;
  char c;
  
  arq1 = fopen ("ConstroiListaAS2.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq1)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaS));
    p1->dado = c;
    if (*epinicio == NULL)
      *epinicio = p1;
    else
      p2->prox = p1;
    p2 = p1;
  }
  p1->prox = NULL;
  fclose (arq1);
}
