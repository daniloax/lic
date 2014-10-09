void ConstroiMalha(lista1 **epinicio) {
  FILE *arq;
  lista1 *pd1, *pd2;
  lista2 *pp1, *pp2;
  char lixo1, c;
  int i, n, ok = 0;

  *epinicio = NULL;
  arq = fopen ("ConstroiMalha2.txt", "r");
  while (!ok){
    c = getc (arq);
	pd1 = malloc (sizeof (lista1));
	pd1->disc = c;
	pd1->cursado = 0;
	pd1->pacesso = NULL;
	pd1->proxd = NULL;
	if (*epinicio == NULL)
	  *epinicio = pd1;
	else
	  pd2->proxd = pd1;
	pd2 = pd1;
	lixo1 = getc(arq);
	if (lixo1 == '\n') 
	  ok = 1;
  }
  pd1 = *epinicio;
  while ((lixo1 = getc(arq)) != EOF){
	if (lixo1 != '\n'){
	  fscanf (arq,"%d", &n);  
	  for (i=1; i !=n+1; i++) {
		lixo1 = getc(arq);
		c = getc (arq);       
		pp1 = malloc (sizeof (lista2));
		pp1->ppre = *epinicio;
		while (pp1->ppre->disc != c)
		  pp1->ppre = pp1->ppre->proxd;
		pp1->proxp = NULL;
		if (pd1->pacesso == NULL)
		  pd1->pacesso = pp1;
		else 
		  pp2->proxp = pp1;
		pp2 = pp1;
	  }
	  pd1 = pd1->proxd;
	}
  }
  fclose (arq);
}
