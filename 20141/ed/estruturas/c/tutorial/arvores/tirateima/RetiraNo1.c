void RetiraNo1 (arvore **eainicio, char dado) {
  arvore *a1, *a2, *ant;
  char aux;
  
  ant = NULL;
  a1 = ProcuraComAnt2 (eainicio, dado, &ant);
  if (a1 == NULL)
    printf ("no inexistente\n");
  else
    if ((a1->dir == NULL) && (a1->esq == NULL))
      if (ant == NULL){
        free (a1);
        *eainicio = NULL;
      }
      else {
        if (ant->dir == a1)
          ant->dir = NULL;
        else 
          ant->esq = NULL;
        free (a1);
      }
    else 
      if ((a1->dir == NULL) || (a1->esq == NULL)){
        if (a1 == *eainicio)
          if (a1->dir == NULL)
            *eainicio = a1->esq;
          else
            *eainicio = a1->dir;
        else 
          if (a1->dir == NULL)
            if (ant->dir == a1)
              ant->dir = a1->esq;
            else
              ant->esq = a1->esq;
          else
            if (ant->dir == a1)
              ant->dir = a1->dir;
            else
              ant->esq = a1->dir;
        free (a1);
      }
      else {
        a2 = a1->dir;
        while (a2->esq != NULL)
          a2 = a2->esq;
        aux = a2->dado;
        RetiraNo1 (&(a1->dir), a2->dado);
        a1->dado = aux;
      }
} 
