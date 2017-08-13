void DestroiListaFS(listaS **epinicio){
  listaS *p1;
  
  if (*epinicio != NULL) {
    p1 = (*epinicio)->prox;
    while (p1 != *epinicio) {
      (*epinicio)->prox = p1->prox;
      free (p1);
      p1 = (*epinicio)->prox;
    }
    free (*epinicio);
    *epinicio = NULL;
  }
}  
