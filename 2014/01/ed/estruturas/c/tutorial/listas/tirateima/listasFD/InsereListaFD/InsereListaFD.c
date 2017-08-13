void InsereListaFD(listaD **epinicio, char dadonovo){
  listaD *p1, *p2;
       
  p1 = malloc (sizeof (listaD));
  p1->dado = dadonovo;
  if (*epinicio == NULL) {
    p1->prox = p1;
    p1->ant = p1;
    *epinicio = p1;
  }
  else
    if ((*epinicio)->dado > dadonovo) {
      p1->prox = *epinicio;
      p1->ant = (*epinicio)->ant;
      (*epinicio)->ant->prox = p1;
      (*epinicio)->ant = p1;
      *epinicio = p1;
    }
    else {
      p2 = *epinicio;     
      while ((p2->prox != *epinicio) && (p2->prox->dado < dadonovo))
        p2 = p2->prox; 
      p1->prox = p2->prox;
      p1->ant = p2;
      p2->prox->ant = p1;      
      p2->prox = p1;   
    }       
}
