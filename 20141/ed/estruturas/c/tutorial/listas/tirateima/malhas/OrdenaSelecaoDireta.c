void OrdenaSelecaoDireta(listaS *pinicio) {
  listaS *p1, *p2;
  char aux;

  if (pinicio != NULL)  {
	p1 = pinicio;
	while (p1->prox != NULL) {
	  p2 = p1->prox;
	  while (p2 != NULL) {
		if (p1->dado > p2->dado) {
		  aux = p2->dado;
		  p2->dado = p1->dado;
		  p1->dado = aux;
		}
		p2 = p2->prox;
	  }
	  p1 = p1->prox;
	}
  }
}
