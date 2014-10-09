void InsereListaNoBobo(listaS **epinicio, char dadonovo){
  listaS *p1, *p2;

  p1 = malloc (sizeof (listaS));
  p1->dado = dadonovo;
  p1->prox = NULL;
  if ((*epinicio)->prox == NULL)
	(*epinicio)->prox = p1;
  else  {
	p2 = *epinicio;
	while ((p2->prox != NULL) && (p2->prox->dado < dadonovo))
	  p2 = p2->prox;
	p1->prox = p2->prox;
	p2->prox = p1;
  }  
}
