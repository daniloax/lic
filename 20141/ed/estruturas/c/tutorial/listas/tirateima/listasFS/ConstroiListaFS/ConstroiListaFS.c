void ConstroiListaFS(listaS **epinicio) {
  FILE *arq;
  listaS *p1, *p2;
  char c;
  
  arq = fopen ("ConstroiListaFS.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaS));
    p1->dado = c;
    if (*epinicio == NULL) 
      *epinicio = p1;
    else 
      p2->prox = p1;
    p2 = p1;
    p1->prox = *epinicio;
  }
  fclose (arq);
}
