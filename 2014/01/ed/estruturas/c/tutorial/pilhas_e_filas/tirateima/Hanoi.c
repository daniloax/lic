void Hanoi (char origem, char destino, char auxiliar, int n) {
  pilhageral *phanoi;
  struct reghanoi {
     char o; 
     char d; 
     char a;
     int k; 
  };
     
//---------------------------------------------
void *EmpilhaHanoi (pilhageral **epilha, char origem, char destino, char auxiliar, int n) {
  struct reghanoi *paux1;
  void *paux2;
  paux1 = malloc (sizeof (struct reghanoi));
  paux1->o = origem;
  paux1->d = destino;
  paux1->a = auxiliar;
  paux1->k = n;
  paux2 = paux1;
  InserePilha (epilha, paux2);
}

//---------------------------------------------
void *DesempilhaHanoi (pilhageral **epilha, char *origem, char *destino, char *auxiliar, int *n) {
  struct reghanoi *paux1;
  void *paux2;
  paux2 = RetiraPilha (epilha);
  paux1 = paux2;
  *origem = paux1->o;
  *destino = paux1->d;
  *auxiliar = paux1->a;
  *n = paux1->k;
  free (paux2);
}


//----------------------------------------------     
  InicializaPilha (&phanoi);
  EmpilhaHanoi (&phanoi, origem, destino, auxiliar, n);
  while (!PilhaVazia (phanoi)) {
    DesempilhaHanoi (&phanoi, &origem, &destino, &auxiliar, &n);
    if (n == 1)
      printf ("movimento de %3c para %3c \n", origem, destino);
    else {
      EmpilhaHanoi (&phanoi, auxiliar, destino, origem, n-1);
      EmpilhaHanoi (&phanoi, origem, destino, auxiliar, 1);
      EmpilhaHanoi (&phanoi, origem, auxiliar, destino, n-1);
    }
  }
}	
