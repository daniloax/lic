void CaminhaGrafoProfundidade(no **eginicio) {
arco *pa1;
  
if (*eginicio != NULL) {
  printf ("visita no: %c \n", (*eginicio)->dado);  
  (*eginicio)->usado = 1;
  pa1 = (*eginicio)->pacessoarco;
  while (pa1 != NULL) {
    if (!pa1->padj->usado)
      PercorreGrafoProfundidade (&(pa1->padj));
    pa1 = pa1->proxarco;        
  }
}
}
