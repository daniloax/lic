int Verifica(arvore *a1, char chave) {
  int achou;
  
  achou = 0;
  if (a1 != NULL) {
    if (a1->dado == chave) 
      achou = 1;
    if (!achou) 
      achou = Verifica (a1->esq, chave);
    if (!achou)
      achou = Verifica (a1->dir, chave);
  } 
  return achou;   
}

//-------------------------------------------
void ProcuraDuasArvores(arvore *ainicio1, arvore *ainicio2) {
  if ((ainicio1 != NULL) && (ainicio2 != NULL)) {
    if (Verifica (ainicio2, ainicio1->dado))
      printf("achou: %3c \n", ainicio1->dado);
    ProcuraDuasArvores (ainicio1->esq, ainicio2);
    ProcuraDuasArvores (ainicio1->dir, ainicio2);  
  }
}
