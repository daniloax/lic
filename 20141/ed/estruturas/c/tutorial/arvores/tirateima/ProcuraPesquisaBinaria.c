arvore *ProcuraPesquisaBinaria(arvore *ainicio, char chave) {
  arvore *a1;

  a1 = ainicio;
  while ((a1 != NULL) && (a1->dado != chave)){
    if (a1->dado != chave)
      if (chave < a1->dado)
        a1 = a1->esq;
      else
        a1 = a1->dir;
  }
  return a1;
}
