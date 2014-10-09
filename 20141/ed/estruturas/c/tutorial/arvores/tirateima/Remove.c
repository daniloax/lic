void Remove(arvore **eainicio) {
  if (*eainicio != NULL) {
    Remove (&((*eainicio)->esq));
    Remove (&((*eainicio)->dir));  
    free (*eainicio);
    *eainicio = NULL;
  }
}
