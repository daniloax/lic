void ConstroiListaDesc (listaDesc **epdescritor) {
 FILE *arq;
  listaS *p1, *p2;
  char c;
  
  *epdescritor = malloc (sizeof (listaDesc));
  (*epdescritor)->acessoinicio = NULL;
  (*epdescritor)->acessofim = NULL;
  arq = fopen ("ConstroiListaDesc.txt", "r");
  while ((c = getc (arq)) != EOF) {
    if (c != '\n'){
	  p1 = malloc (sizeof (listaS));
	  p1->dado = c;
	  if ((*epdescritor)->acessoinicio == NULL)
		(*epdescritor)->acessoinicio = p1;
	  else
		p2->prox = p1;
	  p2 = p1;
	}
  }
  if ((*epdescritor)->acessoinicio != NULL) {
	p1->prox = NULL;
	(*epdescritor)->acessofim = p1;
  }
  fclose (arq);
}