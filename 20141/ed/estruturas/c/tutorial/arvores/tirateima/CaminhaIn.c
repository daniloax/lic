void CaminhaIn(arvore *ainicio) {
  if (ainicio != NULL) {
    CaminhaIn (ainicio->esq);
    printf("%c", ainicio->dado);
    CaminhaIn (ainicio->dir);  
  }
}