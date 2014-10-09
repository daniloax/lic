void Insere(arvore **eainicio, char dadonovo) {
  arvore *a1, *ant, *aux;
  
  ant = NULL;
  a1 = ProcuraComAnt2 (eainicio, dadonovo, &ant);
  if (a1 != NULL)
    printf ("dado ja existe\n");  
  else {
    aux = malloc (sizeof (arvore));
    aux->dado = dadonovo;
    aux->esq = NULL;
    aux->dir = NULL;
    if (*eainicio == NULL)
      *eainicio = aux;
    else
      if (dadonovo < ant->dado)
        ant->esq = aux;
      else
        ant->dir = aux;
  }
}
