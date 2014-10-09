// pilhas e filas utilizando char como dado

/*------- funções básicas para uso de pilhas------------

void InicializaPilha (pilhachar **epilha) 
int PilhaVazia (pilhachar *pilha)
char TopoPilha(pilhachar *pilha) 
void InserePilha(pilhachar **epilha, char dadonovo)
char RetiraPilha(pilhachar **epilha) 

----------------------------------------------------------*/

/*------- funções básicas para uso de filas   ------------

void InicializaFila (filachar **efila) 
int FilaVazia (filachar *fila)
char FrenteFila(filachar *fila) 
void InsereFila(filachar **efila, char dadonovo)
char RetiraFila(filachar **efila) 

----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipopilha {
	char dado;
	struct tipopilha *prox;
} pilhachar;

typedef struct tipofila {
	char dado;
	struct tipofila *prox;
} filachar;

//------- funções básicas para uso de pilhas--
//--------------------------------------------

void InicializaPilha (pilhachar **epilha) {
	*epilha = NULL;
}

//--------------------------------------------
int PilhaVazia (pilhachar *pilha) {
	return (pilha == NULL);
}

//--------------------------------------------
char TopoPilha(pilhachar *pilha) {
	return pilha->dado;
}

//--------------------------------------------
void InserePilha(pilhachar **epilha, char dadonovo) {
	pilhachar *p1;
	p1 = malloc (sizeof (pilhachar));
	p1->dado = dadonovo;
	p1->prox = *epilha;
	*epilha = p1;
}

//--------------------------------------------
char RetiraPilha(pilhachar **epilha) {
	pilhachar *p1;
	char car;
	p1 = *epilha;
	*epilha = p1->prox;
	car = p1->dado;
	free (p1);
	return car;
}

//------- funções básicas para uso de filas---
//--------------------------------------------
void InicializaFila (filachar **efila) {

	*efila = NULL;

}

//--------------------------------------------
int FilaVazia (filachar *fila) {
	
	return (fila == NULL);

}

//--------------------------------------------
char FrenteFila(filachar *fila) {
	return fila->dado;
}

//--------------------------------------------
void InsereFila(filachar **efila, char dadonovo) {
	
	filachar *f1, *f2;
	f1 = malloc (sizeof (filachar));
	f1->dado = dadonovo;
	f1->prox = NULL;
	
	if (*efila == NULL)
		*efila = f1;
	else {
		f2 = *efila;
	
	while (f2->prox != NULL)
	f2 = f2->prox;
	f2->prox = f1;

	}

}

//--------------------------------------------
char RetiraFila(filachar **efila) {
	
	filachar *f1;
	char car;
	f1 = *efila;
	*efila = f1->prox;
	car = f1->dado;
	free (f1);
	return car;

}

//---APLICAÇÕES: funções que utilizam as pilhas e filas---

//---------------------------------------------
void EscreveElementosPilha (pilhachar **epilha) {

	pilhachar *pilhaaux;
	char x;

	if (PilhaVazia (*epilha)) 
		printf ("pilha vazia");

	else {
		
		InicializaPilha(&pilhaaux);

		while (!PilhaVazia (*epilha)) {

			printf ("elemento da pilha: %c \n", TopoPilha(*epilha));
			InserePilha (&pilhaaux, RetiraPilha (epilha));

		}  

		while (!PilhaVazia (pilhaaux)) 
			InserePilha (epilha, RetiraPilha (&pilhaaux));

	}

}

//---------------------------------------------
void EscreveElementosFila (filachar **efila) {

	filachar *faux1;

	if (FilaVazia (*efila)) 
		printf ("fila vazia");

	else {
	
		InicializaFila(&faux1);
	
		while (!FilaVazia (*efila)) {

			printf ("elemento da fila: %c \n", FrenteFila(*efila));
			InsereFila (&faux1, RetiraFila (efila));

		}

		while (!FilaVazia (faux1)) 
			InsereFila (efila, RetiraFila (&faux1));

	}

}

//---------------------------------------------
void ManipulaCaracteres () {

	filachar *f1;
	pilhachar *p1;
	char x;
	FILE *arq;

	InicializaFila (&f1);
	InicializaPilha (&p1);
	arq = fopen ("t2.txt", "r");

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

//---------------------------------------------
void AvaliaExpressaoParentetizada () {
	
	pilhachar *p1, *p2;
	char car;
	int i;
	FILE *arq;

	//------------
	void ResolveOperacao () {

		char op, c1, c2, caux;
		int x,y;

		if (PilhaVazia (p2)) {
			
			if (PilhaVazia (p1)) {
				
				caux = 0+'0';              
				InserePilha (&p1,0+'0');
			
			}
		
		} else {
		
			op = RetiraPilha (&p2);
			c1 = RetiraPilha (&p1);
			x = c1 - '0';
			c2 = RetiraPilha (&p1);
			y = c2 - '0';
		
			switch (op) {

				case '+' : InserePilha (&p1, y+x+'0'); break;
				case '-' : InserePilha (&p1, y-x+'0'); break;
				case '*' : InserePilha (&p1, y*x+'0'); break;
				case '/' : InserePilha (&p1, y%x+'0'); break;  
			
			}

		}

	}

	//------------
	InicializaPilha (&p1);
	InicializaPilha (&p2);
	arq = fopen ("t3.txt", "r");

	while ((car = getc (arq)) != EOF) {
	
		if (car != '\n')
			
			if ((car>='0')&&(car<='9'))
				InserePilha (&p1, car);
			
			else
				
				if (car == ')')
					ResolveOperacao ();
				
				else
					if (car != '(')
						InserePilha (&p2, car);

	}
	
	fclose (arq);
	printf("%d \n", RetiraPilha (&p1)-'0');

}         

//---------------------------------------------
void AvaliaExpressaoPosFixada () {
	
	pilhachar *p1;
	char c, c1, c2;
	FILE *arq;
	int w;

	//------------
	int ResolveOperacao (char c1, char c, char c2) {

		int x, y, z;

		x = c1 - '0';
		y = c2 - '0';
		
		switch (c) {
		
			case '+' : z = x+y; break;
			case '-' : z = x-y; break;
			case '*' : z = x*y; break;
			case '/' : z = x/y; break;  
		
		} 

		return z;    

	}

	//------------  

	InicializaPilha (&p1);
	arq = fopen ("t6.txt", "r");

	while ((c = getc (arq)) != EOF) {
		
		if (c != '\n') {
		
			if ((c!='+')&&(c!='-')&&(c!='*')&&(c!='/'))
				InserePilha (&p1, c);
			
			else {
			
				c2 = RetiraPilha (&p1);
				c1 = RetiraPilha (&p1); 
				w = ResolveOperacao (c1, c, c2);
				InserePilha (&p1, w+'0');
				
			}
			
		}
		
	}
	
	printf ("resultado: %d \n", RetiraPilha (&p1)-'0');
	fclose (arq);

}

//---------------------------------------------
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
	arq = fopen ("t8.txt", "r");
	
	while ((c = getc (arq)) != EOF) {
	
		if (c != '\n') {
			
			if ((c!='^')&&(c!='+')&&(c!='-')&&(c!='*')&&(c!='/')&&(c!='(')&&(c!=')'))
				InsereFila (&f1, c);
				
			else 
			
				if (c==')') {
				
					while (TopoPilha(p1) != '(')
						InsereFila (&f1, RetiraPilha (&p1));

					aux = RetiraPilha (&p1);
					
				} else {
				
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

//--------------------------------------------
int Fibonacci (int n) {

	pilhachar *p1;
	int fib, x;

	InicializaPilha (&p1);
	InserePilha (&p1, n);
	fib = 0;
	
	while (!PilhaVazia (p1)) {
		
		x = RetiraPilha (&p1);
		
		if ((x == 0) || (x == 1))
			fib = fib + 1;

		else {

			InserePilha (&p1, x-1);
			InserePilha (&p1, x-2);

		}

	}
	
	return fib;

}


//--------------------------------------------
main (){

	FILE *arq;
	char c;   

	/* pilhachar *pilha1, *pilha2;  
	InicializaPilha (&pilha1);
	arq = fopen ("t1.txt", "r");
	
	while ((c = getc (arq)) != EOF) {
	
		if (c != '\n')
			InserePilha (&pilha1, c);
	
	}
	
	fclose (arq);
	
	printf("%c \n", TopoPilha(pilha1));
	EscreveElementosPilha (&pilha1); */

	/* filachar *fila1, *fila2;  
	InicializaFila (&fila1);
	arq = fopen ("t1.txt", "r");
	
	while (!feof(arq)){
		
		c = getc(arq);
		
		if ((c!='\n')&& (c!=EOF)) 
			InsereFila (&fila1, c);

	}
	
	fclose (arq);
	printf("%c \n", FrenteFila(fila1));
	EscreveElementosFila (&fila1); */

	// ManipulaCaracteres ();
	// AvaliaExpressaoParentetizada ();
	// AvaliaExpressaoPosFixada ();

	ConversaoParaPosFixada ();

	/*  int i;
	for (i=0; i !=7; i++) 
	printf ("%d %d \n", i, Fibonacci (i)); */

	printf("\n");
	system("pause");

}
