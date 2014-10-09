void CaminhaPre2(arvore *ainicio) {
  printf("%c", ainicio->dado);
  if (ainicio->esq != NULL)
    CaminhaPre2 (ainicio->esq);
  if (ainicio->dir != NULL)
    CaminhaPre2 (ainicio->dir);  
}
