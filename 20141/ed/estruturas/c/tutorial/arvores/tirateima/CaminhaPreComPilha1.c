void CaminhaPreComPilha1 (arvore *ainicio) {
  arvore *a1;
  pilhageral *p1;
  
  a1 = ainicio;
  InicializaPilha (&p1);
  InserePilha (&p1, a1);
  while (!PilhaVazia (p1)) {
    a1 = RetiraPilha (&p1);  
    if (a1 != NULL) {
      printf ("%c", a1->dado);
      InserePilha (&p1, a1->dir);
      InserePilha (&p1, a1->esq);
    }
  }
}