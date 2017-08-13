void CaminhaPreComPilha2 (arvore *ainicio) {
  arvore *a1;
  pilhageral *p1;
  
  a1 = ainicio;
  InicializaPilha (&p1);
  if (a1 != NULL) 
    InserePilha (&p1, a1);
  while (!PilhaVazia (p1)) {
    a1 = RetiraPilha (&p1);  
    printf ("%c", a1->dado);
    if (a1->dir != NULL) 
      InserePilha (&p1, a1->dir);
    if (a1->esq != NULL) 
      InserePilha (&p1, a1->esq);
  }
}