arvore *ConstroiEquivalente(arvore *ainicio) {
  arvore *a1;

  if (ainicio == NULL) 
    return NULL;
  else {
    a1 = malloc (sizeof (arvore));
    a1->dado = ainicio->dado;
    a1->esq = ConstroiEquivalente (ainicio->esq);
    a1->dir = ConstroiEquivalente (ainicio->dir);
    return a1;
  }
}
