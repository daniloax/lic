void RemoveListaAS(listaS **epinicio, char chave){
  listaS *p1, *p2;
  int achou;
       
  if (*epinicio == NULL)
    printf("lista vazia \n");
  else {
    p1 = *epinicio;
    achou = 0;
    while (p1 != NULL) {
      if (p1->dado == chave) {
        achou =1;
        if (*epinicio == p1){
          *epinicio = (*epinicio)->prox;
          free (p1);
          p1 = *epinicio;
        }
        else {
          p2->prox = p1->prox;
          free (p1);
          p1 = p2->prox;
        }
      }
      else {
        p2 = p1;
        p1 = p1->prox;
      }
    }
    if (!achou) 
      printf ("elemento nao presente \n");
  }       
}
