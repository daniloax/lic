void ConstroiListaAD(listaD **epinicio) {
  FILE *arq;
  listaD *p1, *p2;
  char c;
  
  arq = fopen ("ConstroiListaAD.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaD));
    p1->dado = c;
    p1->prox = NULL;
    if (*epinicio == NULL) {
      *epinicio = p1;
      p1->ant = NULL;
    }
    else {
      p2->prox = p1;
      p1->ant = p2;
    }
    p2 = p1;
  }
  fclose (arq);
}
