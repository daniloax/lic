void DestroiListaAD(listaD **epinicio){
  listaD *p1;
  
  while (*epinicio != NULL) {
    p1 = *epinicio;
    *epinicio = (*epinicio)->prox;
    free (p1);
  }
}  
  
