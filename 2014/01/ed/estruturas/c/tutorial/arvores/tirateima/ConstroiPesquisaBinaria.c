void ConstroiPesquisaBinaria(arvore **eainicio) {
  char c;

  c = getc (arq);
  if (c == '.')
    *eainicio = NULL;
  else {
    *eainicio = malloc (sizeof (arvore));
    (*eainicio)->dado = c;        
    ConstruirArv (&((*eainicio)->esq));
    ConstruirArv (&((*eainicio)->dir));
  }
}