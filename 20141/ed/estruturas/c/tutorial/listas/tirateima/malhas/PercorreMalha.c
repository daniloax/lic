void PercorreMalha(central *pacesso) {
  central *pc1;
  fone *pf1;

  if (pacesso == NULL)
    printf ("lista vazia \n");
  else {          
    pc1 = pacesso;     
    while (pc1 != NULL) {
      printf("\n %c", pc1->central);
      pf1 = pc1->pfone;
      while (pf1 != NULL) {
	printf("%5d", pf1->fone);
	pf1 = pf1->proxf;
      }
      pc1 = pc1->proxc;   
    }
  }     
}     
