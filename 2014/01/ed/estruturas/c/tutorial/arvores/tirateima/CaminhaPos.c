void CaminhaPos(arvore *ainicio) {
  if (ainicio != NULL) {
    CaminhaPos (ainicio->esq);
    CaminhaPos (ainicio->dir);  
    printf("%c", ainicio->dado);
  }
}
