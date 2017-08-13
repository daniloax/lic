void PercorreListaDesc(listaDesc *pdescritor) {
  listaS *p1;

  if (pdescritor->acessoinicio == NULL)
	printf ("lista vazia \n");
  else {          
	p1 = pdescritor->acessoinicio;     
	while (p1 != NULL) {
	  printf("elemento:  %c \n", p1->dado);
	  p1 = p1->prox;   
	}
  }     
}     
