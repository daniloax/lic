arvore *Procura(arvore *ainicio, char chave) {
  arvore *a1;
  a1 = NULL;
  if (ainicio != NULL) {
    if (ainicio->dado == chave) 
      a1 = ainicio;
    if (a1 == NULL) 
      a1 = Procura1 (ainicio->esq, chave);
    if (a1 == NULL)
      a1 = Procura1 (ainicio->dir, chave); 
  }
  return a1;   
}
