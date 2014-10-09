void DestroiListaAS(listaS **epinicio){
  listaS *p1;
  
  while (*epinicio != NULL) {
    p1 = *epinicio;
    *epinicio = (*epinicio)->prox;
    free (p1);
  }
}  
