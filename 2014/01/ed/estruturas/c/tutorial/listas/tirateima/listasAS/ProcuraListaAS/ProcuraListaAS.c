void *ProcuraListaAS(listaS *pinicio, char chave) {
  listaS *p1;
   
  p1 = pinicio;     
  while ((p1 != NULL) && (p1->dado != chave))
    p1 = p1->prox;   
  return p1;
}
