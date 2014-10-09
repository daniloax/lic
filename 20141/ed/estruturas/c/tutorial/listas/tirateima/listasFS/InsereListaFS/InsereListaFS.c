void InsereListaFS(listaS **epinicio, char dadonovo){
  listaS *p1, *p2;
       
  p1 = malloc (sizeof (listaS));
  p1->dado = dadonovo;
  if (*epinicio == NULL) {
    p1->prox = p1;
    *epinicio = p1;
    }
  else 
    if ((*epinicio)->dado > dadonovo) {
      p1->prox = *epinicio;
      p2 = *epinicio;
      while (p2->prox != *epinicio)
        p2 = p2->prox;
      p2->prox = p1;
      *epinicio = p1;
    }
    else {
      p2 = *epinicio;     
      while ((p2->prox != *epinicio) && (p2->prox->dado < dadonovo))
        p2 = p2->prox; 
      p1->prox = p2->prox;
      p2->prox = p1;
    }    
}
