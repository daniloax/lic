int VerificaEspelhadas1(arvore *ainicio1, arvore *ainicio2) {
  int ok;
  
  ok = 0;
  if ((ainicio1 == NULL) && (ainicio2 == NULL))
     ok = 1;
  else 
    if ((ainicio1 != NULL) && (ainicio2 != NULL) && 
	   (ainicio1->dado == ainicio2->dado) &&  
       (VerificaEspelhadas1 (ainicio1->esq, ainicio2->dir)) &&
       (VerificaEspelhadas1 (ainicio1->dir, ainicio2->esq)))
      ok = 1;  
  return ok;
}
