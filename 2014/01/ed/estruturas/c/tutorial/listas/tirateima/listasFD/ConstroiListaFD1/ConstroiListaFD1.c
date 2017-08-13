void ConstroiListaFD1(listaD **epinicio) {
  FILE *arq;
  listaD *p1;
  char c;

  arq = fopen ("ConstroiListaFD1.txt", "r");
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
	  p1->ant = (*epinicio)->ant;
	  (*epinicio)->ant->prox = p1;
	  (*epinicio)->ant = p1;
	  *epinicio = p1;
	}  
  }
  fclose (arq);
}
