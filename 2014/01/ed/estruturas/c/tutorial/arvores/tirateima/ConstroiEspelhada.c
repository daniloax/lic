arvore *ConstroiEspelhada(arvore *ainicio) {
  arvore *a1;

  if (ainicio == NULL) 
    return NULL;
  else {
    a1 = malloc (sizeof (arvore));
    a1->dado = ainicio->dado;
    a1->esq = ConstroiEspelhada (ainicio->dir);
    a1->dir = ConstroiEspelhada (ainicio->esq);
    return a1;
  }
}
