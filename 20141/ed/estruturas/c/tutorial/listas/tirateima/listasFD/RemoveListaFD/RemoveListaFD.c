void RemoveListaFD(listaD **epinicio, char chave){
listaD *p1, *p2;
         
if (*epinicio == NULL)
  printf("lista vazia \n");
else {
  while ((*epinicio != NULL) && ((*epinicio)->dado == chave)) {
    if ((*epinicio)->prox == *epinicio) {
      free (*epinicio);
      *epinicio = NULL;
    }
    else {
      p1 = *epinicio;    
      *epinicio = (*epinicio)->prox;
      p1->prox->ant = p1->ant;
      p1->ant->prox = p1->prox;
      free (p1);
    }
  }
}  
if ((*epinicio != NULL) && ((*epinicio)->prox != *epinicio)) {
  p1 = (*epinicio)->prox;
  while (p1 != *epinicio){ 
    if (p1->dado == chave) {
      p2 = *epinicio;
      while (p2->prox != p1)
        p2 = p2->prox;
      p2->prox = p1->prox;
      p1->prox->ant = p2;
      free (p1);
      p1 = p2->prox;  
    }  
    else    
      p1 = p1->prox;
  }
 }       
}
