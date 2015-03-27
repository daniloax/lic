void PercursoLinear(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;
  int ok;

  pd1 = pini;
  while (pd1 != NULL) {  
    if (pd1->cursado)
      ok = 0;
    else {
      ok = 1;
      pp1 = pd1->pacesso;
      while (pp1 != NULL) {  
        if (!pp1->ppre->cursado)
          ok = 0;
        pp1 = pp1->proxp;
      }
    }
    if (ok) {  
      pd1->cursado = 1;
      printf("%c\n", pd1->disc);
      pd1 = pini;
    }
    else pd1 = pd1->proxd;
  }
}
