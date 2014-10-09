void PercorreListaNoBobo(listaS *pinicio) {
  listaS *p1;

  if (pinicio->prox == NULL)
	printf ("lista vazia \n");
  else {          
	p1 = pinicio->prox;     
	while (p1 != NULL) {
	  printf("elemento:  %c \n", p1->dado);
	  p1 = p1->prox;   
	}
  }     
}     
