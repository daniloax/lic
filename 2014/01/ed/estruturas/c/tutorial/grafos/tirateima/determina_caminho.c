int DeterminaCaminho (no *p1, no *p2) {
arco *pa1;
int achou;
char c;

InserePilha (&pilha1, p1->dado); 
achou = 0;
p1->usado = 1;
pa1 = p1->pacessoarco; 
while ((!achou) && (pa1 != NULL)) {
  if (pa1->padj == p2) {
    InserePilha (&pilha1, p2->dado);
    achou = 1;
    while (!PilhaVazia (pilha1))
      InserePilha (&paux, RetiraPilha (&pilha1));
    while (!PilhaVazia (paux)) 
      printf ("%2c", RetiraPilha (&paux));
  }
  else 
    if (!pa1->padj->usado) 
      achou = DeterminaCaminho (pa1->padj, p2);
  pa1 = pa1->proxarco;  
}
if (!achou)
  c = RetiraPilha (&pilha1);
return achou;
}
