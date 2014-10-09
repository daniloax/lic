void ConstroiListaFD(listaD **epinicio) {
  FILE *arq;
  listaD *p1, *p2;
  char c;
  
  arq = fopen ("ConstroiListaFD.txt", "r");
  *epinicio = NULL;
  while (((c = getc (arq)) != EOF) && (c != '\n')) {
    p1 = malloc (sizeof (listaD));
    p1->dado = c;
    if (*epinicio == NULL) { 
      p1->prox = p1;
      p1->ant = p1;
      *epinicio = p1;
    }  
    else {
      p1->prox = *epinicio;
      p1->ant = p2;
      p2->prox = p1;
      (*epinicio)->ant = p1;
    }  
    p2 = p1;
  }
  fclose (arq);
}
