void AvaliaExpressaoParentetizada () {
  pilhachar *p1, *p2;
  char car;
  int i;
  FILE *arq;

//------------
void ResolveOperacao () {

  char op, c1, c2, caux;
  int x,y;

  if (PilhaVazia (p2)) {
	if (PilhaVazia (p1)) {
	  caux = 0+'0';              
	  InserePilha (&p1,0+'0');
	}
  }
  else {
	op = RetiraPilha (&p2);
	c1 = RetiraPilha (&p1);
	x = c1 - '0';
	c2 = RetiraPilha (&p1);
	y = c2 - '0';
	switch (op) {
	  case '+' : InserePilha (&p1, y+x+'0'); break;
	  case '-' : InserePilha (&p1, y-x+'0'); break;
	  case '*' : InserePilha (&p1, y*x+'0'); break;
	  case '/' : InserePilha (&p1, y%x+'0'); break;  
	}     
  }    
}
//------------

  InicializaPilha (&p1);
  InicializaPilha (&p2);
  arq = fopen ("AvaliaExpressaoParentizada.txt", "r");
  while ((car = getc (arq)) != EOF) 
    if (car != '\n'){
	  if ((car>='0')&&(car<='9'))
		InserePilha (&p1, car);
	  else
		if (car == ')')
		  ResolveOperacao ();
		else
		  if (car != '(')
			InserePilha (&p2, car);
	}
  fclose (arq);
  printf("%d \n", RetiraPilha (&p1)-'0');
}         
