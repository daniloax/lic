void ManipulaCaracteres () {
  filachar *f1;
  pilhachar *p1;
  char x;
  FILE *arq;

  InicializaFila (&f1);
  InicializaPilha (&p1);
  arq = fopen ("ManipulaCaracteres.txt", "r");
  while (!feof(arq)){
	x = getc(arq);
	if ((x!='\n')&& (x!=EOF))       
	  InsereFila (&f1, x);
	x = getc(arq);
	if ((x!='\n')&& (x!=EOF)) 
	  InserePilha (&p1, x);
  }
  fclose (arq);         
  while ((!FilaVazia(f1)) && (!PilhaVazia(p1))) {
	printf ("%c", RetiraFila (&f1));
	printf ("%c", RetiraPilha(&p1));
  }
}
