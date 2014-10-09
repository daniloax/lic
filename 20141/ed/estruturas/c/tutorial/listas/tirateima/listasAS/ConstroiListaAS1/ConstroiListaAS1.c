void ConstroiListaAS1(listaS **epinicio) {
  FILE *arq1;
  listaS *p1;
  char c;

  arq1 = fopen ("ConstroiListaAS1.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq1)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaS));
    p1->dado = c;   
    p1->prox = *epinicio;
    *epinicio = p1;
  }
  fclose (arq1);
}
