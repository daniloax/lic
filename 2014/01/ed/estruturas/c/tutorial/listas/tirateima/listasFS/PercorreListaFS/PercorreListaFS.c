void PercorreListaFS(listaS *pinicio) {
  listaS *p1;

  if (pinicio == NULL)
    printf ("lista vazia \n");
  else {          
    p1 = pinicio;     
    do {
      printf("elemento:  %c \n", p1->dado);
      p1 = p1->prox;   
    }
    while (p1 != pinicio);
  }     
}     

