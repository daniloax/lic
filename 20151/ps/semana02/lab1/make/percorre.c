void PercorreMalha(lista1 *pini) {
  lista1 *pd1;
  lista2 *pp1;

  if (pini == NULL)
    printf ("lista vazia \n");
  else {          
    pd1 = pini;     
    while (pd1 != NULL) {
      printf("%c", pd1->disc);
      pp1 = pd1->pacesso;
      while (pp1 != NULL) {
        printf("%2c", pp1->ppre->disc);
        pp1 = pp1->proxp;
      }  
      pd1 = pd1->proxd; 
      printf("\n");  
    }
  }
  printf("\n");         
}  
