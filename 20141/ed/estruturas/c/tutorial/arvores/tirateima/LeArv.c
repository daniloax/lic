void LeArv(arvore **eainicio) {
  if (*eainicio == NULL) 
    printf (".");
  else {
    printf ("%c" , (*eainicio)->dado);
    LeArv (&((*eainicio)->esq));
    LeArv (&((*eainicio)->dir));  
  }
}