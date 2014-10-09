void CaminhaInComPilha1 (arvore *ainicio) {
  pilhageral *pilha;
  struct reg *paux;  
  arvore *a1;
 
  a1 = ainicio;
  InicializaPilha(&pilha);
  Empilha(a1, 1);
  while (!PilhaVazia (pilha)) {
    paux = RetiraPilha (&pilha);
    a1 = paux->arv;
    if (a1 != NULL) {
      if (!paux->pri) 
        printf ("%c", paux->arv->dado);   
      else {  
	    Empilha (a1->dir, 1);
	    Empilha (a1, 0);
	    Empilha (a1->esq, 1); 
      }
	}
    free (paux);
  }
}
