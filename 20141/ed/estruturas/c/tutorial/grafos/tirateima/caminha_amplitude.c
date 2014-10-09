void CaminhaGrafoAmplitude(no *ginicio) {
no *pno1;
arco *pa1;
filageral *fila;
  
if (ginicio == NULL)
  printf ("grafo vazio \n");
else {
  InicializaFila (&fila);          
  pno1 = ginicio;
  InsereFila (&fila, ginicio);     
  ginicio->usado = 1;
  printf ("visita no: %c \n", ginicio->dado);
  while (!FilaVazia(fila)) {
    pno1 = RetiraFila (&fila);  
    pa1 = pno1->pacessoarco;
    while (pa1 != NULL){
      if (!pa1->padj->usado){
        printf ("visita no: %c \n", pa1->padj->dado);
        pa1->padj->usado = 1;
        InsereFila (&fila, pa1->padj);
      }
      pa1 = pa1->proxarco;
    }
  }
}
}      
