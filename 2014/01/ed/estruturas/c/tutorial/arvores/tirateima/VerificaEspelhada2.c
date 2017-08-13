int VerificaEspelhadas2(arvore *ainicio1, arvore *ainicio2) {
  int ok;
  
  ok = 0;
  if (((ainicio1 == NULL) && (ainicio2 == NULL)) ||
    ((ainicio1 != NULL) && (ainicio2 != NULL) && 
	(ainicio1->dado == ainicio2->dado) &&  
    (VerificaEspelhadas2 (ainicio1->esq, ainicio2->dir)) &&
    (VerificaEspelhadas2 (ainicio1->dir, ainicio2->esq))))
      ok = 1;  
  return ok;
}
