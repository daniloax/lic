int Ocorrencias (arvore *ainicio, int chave) {
  int ocdir, ocesq;
  
  if (ainicio == NULL) 
    return 0;
  else {
    ocdir = Ocorrencias (ainicio->dir, chave);
    ocesq = Ocorrencias (ainicio->esq, chave);
    if (ainicio->dado == chave)
      return (1  + ocdir + ocesq);
    else 
      return (ocdir + ocesq);
  }
}
