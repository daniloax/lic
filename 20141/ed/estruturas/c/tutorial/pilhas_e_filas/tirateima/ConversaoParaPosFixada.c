void ConversaoParaPosFixada () {
  pilhachar *p1;
  filachar *f1;
  char c, aux;
  FILE *arq;

//------------
int Prioridade (char c1) {

  switch (c1) {
    case '^' : return 1; break;
	case '*' : case '/' : return 2; break;
	case '+' : case '-' : return 3; break;
	case '(' : return 4; break;
  }    
}
//------------  

  InicializaPilha (&p1);
  InicializaFila (&f1);
  arq = fopen ("ConversaoParaPosFixada.txt", "r");
  while ((c = getc (arq)) != EOF) {
    if (c != '\n'){
	  if ((c!='^')&&(c!='+')&&(c!='-')&&(c!='*')&&(c!='/')&&(c!='(')&&(c!=')'))
	    InsereFila (&f1, c);
	  else 
	    if (c==')') {
		  while (TopoPilha(p1) != '(')
		    InsereFila (&f1, RetiraPilha (&p1));
		  aux = RetiraPilha (&p1);
	    }
	    else {
		  if ((c!='(') && (!PilhaVazia (p1)))
		    while ((!PilhaVazia (p1)) && (Prioridade(TopoPilha (p1)) <= Prioridade (c)))
			  InsereFila (&f1, RetiraPilha (&p1));          
		  InserePilha (&p1,c);
	    }
	}
  }
  fclose (arq);
  while (!PilhaVazia (p1))
    InsereFila (&f1, RetiraPilha (&p1));
  while (!FilaVazia (f1))
	printf ("%c", RetiraFila (&f1));
}
