OrdenaAlteraPonteiros(listaD **epinicio) {
  listaD *p1, *p2, *p3, *paux;
  
  if (*epinicio != NULL)  {
	p1 = *epinicio;
	while (p1->prox != NULL) {
	  p2 = p1->prox;
	  while (p2 != NULL) {
		if (p1->dado > p2->dado) {
		  if (p1->prox == p2) {
			p1->prox = p2->prox;
			p2->ant = p1->ant;
			if (!(p2->prox == NULL))
			  p2->prox->ant = p1;
			if (!(p1->ant == NULL))
			  p1->ant->prox = p2;
			p2->prox = p1;
			p1->ant = p2;
			if (*epinicio == p1)
			  *epinicio = p2;
			paux = p1;
			p1 = p2;
			p2 = paux;
		  }
		  else {
			p2->ant->prox = p1;
			p1->prox->ant = p2;
			if (!(p2->prox == NULL))
			  p2->prox->ant = p1;
			if (!(p1->ant == NULL))
			  p1->ant->prox = p2;
			paux = p1->ant;
			p1->ant = p2->ant;
			p2->ant = paux;
			paux = p1->prox;
			p1->prox = p2->prox;
			p2->prox = paux;
			if (*epinicio == p1)
			  *epinicio = p2;
			paux = p1;
			p1 = p2;
			p2 = paux;        
		  }
		}  
		p2 = p2->prox;  
	  }
	  p1 = p1->prox;  
	}
  }
}
