arvore *ProcuraComAnt2(arvore **eainicio, char chave, arvore **eant) {
  arvore *a1;
       
  *eant = NULL;
  a1 = *eainicio;
  while ((a1 != NULL) && (a1->dado != chave)){
    if (a1->dado != chave)
      if (chave < a1->dado) {
        *eant = a1;
        a1 = a1->esq;
      }
      else {
        *eant = a1;
        a1 = a1->dir;
      }
  }
  return a1;
}
