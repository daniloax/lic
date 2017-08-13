void CaminhoCritico (no *p1, no *p2) {                                
arco *pa1;
char c;
pilhachar *paux;

InserePilha (&pilhaatual, p1->dado);
p1->usado = 1;
pa1 = p1->pacessoarco;
while (pa1 != NULL) {
  if (pa1->padj == p2) {
    InserePilha (&pilhaatual, p2->dado);
    valoratual = valoratual + pa1->valorarco;
    if (valoratual > valormax) {
      valormax = valoratual; 
      while (!PilhaVazia (pilhamax)) 
        c = RetiraPilha (&pilhamax); 
      InicializaPilha (&paux);
      while (!PilhaVazia (pilhaatual))
        InserePilha (&paux, RetiraPilha (&pilhaatual));
      while (!PilhaVazia (paux)) {
        c = RetiraPilha (&paux); 
        InserePilha (&pilhaatual, c);
        InserePilha (&pilhamax, c);
      }
    }
    c = RetiraPilha (&pilhaatual);
    valoratual = valoratual - pa1->valorarco;
  } 
  else 
    if (!pa1->padj->usado) {
      valoratual = valoratual + pa1->valorarco;
      CaminhoCritico (pa1->padj, p2);
      valoratual = valoratual - pa1->valorarco;
    }
  pa1 = pa1->proxarco; 
}
c = RetiraPilha (&pilhaatual);
p1->usado = 0;
}
