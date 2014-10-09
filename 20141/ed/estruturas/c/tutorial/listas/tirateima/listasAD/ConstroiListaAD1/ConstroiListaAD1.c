void ConstroiListaAD1(listaD **epinicio) {
  FILE *arq;
  listaD *p1;
  char c;

  arq = fopen ("ConstroiListaAD1.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaD));
    p1->dado = c;   
    p1->prox = *epinicio;
    if (*epinicio != NULL)
      (*epinicio)->ant = p1;
    p1->ant = NULL;
    *epinicio = p1;
  }
  fclose (arq);
}

