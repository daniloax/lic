int Altura (arvore *ainicio) {
  int adir, aesq;
  
  if (ainicio == NULL) 
    return -1;
  else {
    adir = Altura (ainicio->dir);
    aesq = Altura (ainicio->esq);
    if (adir > aesq)
      return (1 + adir);
    else 
      return (1 + aesq);
  }
}
