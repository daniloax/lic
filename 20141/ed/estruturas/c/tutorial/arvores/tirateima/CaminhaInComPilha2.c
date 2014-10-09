void CaminhaInComPilha2 (arvore *ainicio) {  
  pilhageral *pilha;
  struct reg {
    arvore *arv;
    int pri;
  };
  struct reg *paux;  
  arvore *a1;
	
  a1 = ainicio;
  InicializaPilha(&pilha);
  if (a1 != NULL) 
    Empilha(a1, 1);
  while (!PilhaVazia (pilha)) {
    paux = RetiraPilha (&pilha);
    a1 = paux->arv;
    if (!paux->pri) 
      printf ("%c", paux->arv->dado);   
    else {  
      if (a1->dir != NULL) 
        Empilha (a1->dir, 1);
      Empilha (a1, 0);
      if (a1->esq != NULL) 
	Empilha (a1->esq, 1);
    }
    free (paux);
  }
}