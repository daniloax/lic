void InsereListaAD(listaD **epinicio, char dadonovo){
  listaD *p1, *p2;
       
  p1 = malloc (sizeof (listaD));
  p1->dado = dadonovo;
  if (*epinicio == NULL) {
    *epinicio = p1;
    p1->prox = NULL;
    p1->ant = NULL;
  }
  else
    if ((*epinicio)->dado > dadonovo) {
      p1->prox = *epinicio;
      p1->ant = NULL;
      (*epinicio)->ant = p1;
      *epinicio = p1;
    }
    else {
      p2 = *epinicio;
      while ((p2->prox != NULL) && (p2->prox->dado < dadonovo))
        p2 = p2->prox;
      p1->prox = p2->prox;
      p1->ant = p2;
      if (p2->prox != NULL)
        p2->prox->ant = p1;
      p2->prox = p1;
    }       
}
