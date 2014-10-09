void RemoveListaAD(listaD **epinicio, char chave){
  listaD *p1, *p2;
  int achou;
       
  if (*epinicio == NULL)
    printf("lista vazia \n");
  else {
    p1 = *epinicio;
    achou = 0;
    while (p1 != NULL) {
      if (p1->dado == chave) {
        if (*epinicio == p1)
          *epinicio = (*epinicio)->prox;
        p2 = p1->prox;
        if (p1->prox != NULL)
          p1->prox->ant = p1->ant;
        if (p1->ant != NULL)
          p1->ant->prox = p1->prox;
        free (p1);
        p1 = p2;
        achou =1;
      }
      else 
        p1 = p1->prox;
    }
    if (!achou) 
      printf ("elemento nao presente \n");
  }       
}
