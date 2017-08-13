void *ProcuraListaFS(listaS *pinicio, char chave) {
  listaS *p1;
   
  if (pinicio == NULL)
    p1 = NULL;
  else {
    p1 = pinicio;     
    do
      p1 = p1->prox;     
    while ((p1 != pinicio) && (p1->dado != chave));
    if ((p1 == pinicio) && (p1->dado != chave))
      p1 = NULL;
  }
  return p1;
}
