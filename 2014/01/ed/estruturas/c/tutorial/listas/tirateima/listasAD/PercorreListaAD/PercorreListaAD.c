void CaminhaListaAD(listaD *pinicio) {
  listaD *p1;

  if (pinicio == NULL)
    printf ("lista vazia \n");
  else {          
    p1 = pinicio;     
    while (p1 != NULL) {
      printf("elemento:  %c \n", p1->dado);
      p1 = p1->prox;
    } 
    p1 = pinicio;     
    while (p1->prox != NULL)
      p1 = p1->prox; 
    while (p1 != NULL) {
      printf("elemento (para tras):  %c \n", p1->dado);
      p1 = p1->ant;     
    }
  }     
}

