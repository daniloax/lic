void RemoveSub(arvore **eainicio, char chave) {
  arvore *a1, *aant;
  aant = NULL;
  a1 = ProcuraComAnt (*eainicio, chave, &aant);
  if (a1 == *eainicio)
    *eainicio = NULL;
  else 
    if (a1 != NULL)
      if (a1 == aant->esq)
        aant->esq = NULL;
      else  //       if (a1 == aant->dir)
        aant->dir = NULL;
  Remove (&a1);
}
