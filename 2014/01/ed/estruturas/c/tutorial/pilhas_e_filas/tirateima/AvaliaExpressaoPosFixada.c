void AvaliaExpressaoPosFixada () {
  pilhachar *p1;
  char c, c1, c2;
  FILE *arq;
  int w;

//------------
int ResolveOperacao (char c1, char c, char c2) {

  int x, y, z;

  x = c1 - '0';
  y = c2 - '0';
  switch (c) {
	case '+' : z = x+y; break;
	case '-' : z = x-y; break;
	case '*' : z = x*y; break;
	case '/' : z = x/y; break;  
  } 
  return z;    
}
//------------  

  InicializaPilha (&p1);
  arq = fopen ("AvaliaExpressaoPosFixada.txt", "r");
  while ((c = getc (arq)) != EOF) {
	if (c != '\n'){
	  if ((c!='+')&&(c!='-')&&(c!='*')&&(c!='/'))
		InserePilha (&p1, c);
	  else {
		c2 = RetiraPilha (&p1);
		c1 = RetiraPilha (&p1); 
		w = ResolveOperacao (c1, c, c2);
	    InserePilha (&p1, w+'0');
	  }
	}
  }  
  printf ("resultado: %d \n", RetiraPilha (&p1)-'0');
  fclose (arq);
}
