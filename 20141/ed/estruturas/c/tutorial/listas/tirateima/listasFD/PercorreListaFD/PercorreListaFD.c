void PercorreListaFD(listaD *pinicio) {
  listaD *p1;

  if (pinicio == NULL)
    printf ("lista vazia \n");
  else {          
    p1 = pinicio;     
    do {
      printf("elemento:  %c \n", p1->dado);
      p1 = p1->prox;   
    }
    while (p1 != pinicio);
    do {
      p1 = p1->ant; 
      printf("elemento (para tras):  %c \n", p1->dado);
    }
    while (p1 != pinicio);
  }     
}
    
