void DeterminaTodosCaminhos (no *p1, no *p2) {
arco *pa1;
char c;

InserePilha (&pilha1, p1->dado);
p1->usado = 1;
pa1 = p1->pacessoarco; 
while (pa1 != NULL) {
  if (pa1->padj == p2) {
    InserePilha (&pilha1, p2->dado);
    while (!PilhaVazia (pilha1))
      InserePilha (&paux, RetiraPilha (&pilha1));
    while (!PilhaVazia (paux)) {
      printf ("%2c", TopoPilha (paux));
      InserePilha (&pilha1, RetiraPilha (&paux));
    }
    printf("\n");
    c = RetiraPilha (&pilha1);
  }
  else 
    if (!pa1->padj->usado) 
      DeterminaTodosCaminhos (pa1->padj, p2);
  pa1 = pa1->proxarco; 
}
c = RetiraPilha (&pilha1);
p1->usado = 0;
}
