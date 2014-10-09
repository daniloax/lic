void ConstroiListaFS1(listaS **epinicio) {
  FILE *arq1;
  listaS *p1, *p2;
  char c;

  arq1 = fopen ("ConstroiListaFS1.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq1)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaS));
    p1->dado = c;
    if (*epinicio == NULL) {
      p1->prox = p1;
      *epinicio = p1;
    p2 = p1;
    }
    else {
      p1->prox = *epinicio;
      p2->prox = p1;
      *epinicio = p1;
    }
  }
  fclose (arq1);
}
