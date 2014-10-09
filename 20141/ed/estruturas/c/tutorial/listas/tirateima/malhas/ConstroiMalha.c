void ConstroiMalha(central **epacesso) {
  FILE *arq;
  central *pc1, *pc2;
  fone *pf1, *pf2;
  char c;
  int i,n,m;

  arq = fopen ("ConstroiMalha.txt", "r");
  *epacesso = NULL;
  while ((c = getc (arq)) != EOF){ 
	if (c != '\n'){
	  pc1 = malloc (sizeof (central));
	  pc1->central = c;
	  pc1->pfone = NULL;
      pc1->proxc = NULL;
	  if (*epacesso == NULL)
		*epacesso = pc1;
	  else
		pc2->proxc = pc1;
	  pc2 = pc1;
	  fscanf (arq, "%d ", &n); 
	  for (i=1; i !=n+1; i++) {
		fscanf (arq, "%d ", &m);
		pf1 = malloc (sizeof (fone));
		pf1->fone = m;
		pf1->proxf = NULL;
		if (pc1->pfone == NULL)
		  pc1->pfone = pf1;
		else 
		  pf2->proxf = pf1;
		pf2 = pf1;
	  }
	}
  }
  fclose (arq);
}

