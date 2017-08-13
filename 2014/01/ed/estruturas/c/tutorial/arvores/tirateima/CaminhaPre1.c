void CaminhaPre1(arvore *ainicio) {
  if (ainicio != NULL) {
    printf("%c", ainicio->dado);
    CaminhaPre1 (ainicio->esq);
    CaminhaPre1 (ainicio->dir);  
  }
}