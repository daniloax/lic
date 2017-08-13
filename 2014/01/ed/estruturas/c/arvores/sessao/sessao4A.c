/* sessao 4 item a

preencha os dados:

Nome:

Matr�cula

S�o dadas abaixo as fun��es para construir e ler uma �rvore bin�ria (n�o de 
pesquisa) contendo em cada n� um caractere, a partir do arquivo na forma
vista em aula.

S�o dadas tamb�m as fun��es b�sicas para uso de pilhas de caracteres.

Fa�a uma fun��o que percorra uma �rvore bin�ria e escreva na tela todos os
caminhos entre a raiz e cada uma das folhas.

Exemplo:

Dado:     abd..e..c..

Resposta:
abd
abe
ac

A fun��o n�o deve destruir a �rvore dada, nem usar outros recursos ou 
estruturas al�m dos fornecidos nesta quest�o.
*/

#include <stdio.h>
#include <stdlib.h>

//----defini��o e fun��es b�sicas para pilhas de caracteres--
//--------------------------------------------
typedef struct tipopilha {
	char dado;
	struct tipopilha *prox;
} pilhachar;

pilhachar *pilha1, *paux;

//-------------------------------------------
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


//-- defini��o, leitura e escrita de �rvores---
//--------------------------------------------
typedef struct nodo {
	char dado;
	struct nodo *esq, *dir;
} arvore ;

arvore *aini;
FILE *arq;

//-------------------------------------------
void Constroi(arvore **eainicio) {
	char c;

	c = getc (arq);
	if (c == '.')
		*eainicio = NULL;
	else {
		*eainicio = malloc (sizeof (arvore));
		(*eainicio)->dado = c;        
		Constroi (&((*eainicio)->esq));
		Constroi (&((*eainicio)->dir));
	}
}

//-------------------------------------------
void LeArv(arvore *ainicio) {
	if (ainicio == NULL) 
		printf (".");
	else {
		printf ("%c" , ainicio->dado);
		LeArv (ainicio->esq);
		LeArv (ainicio->dir);  
	}
}

//-------------------------------------------
void CaminhoFolhas(arvore *ainicio) {
    
	if (ainicio != NULL) {
		InserePilha(&pilha1, ainicio->dado);
		printf("%c", TopoPilha(pilha1));
		CaminhoFolhas(ainicio->esq);
		CaminhoFolhas(ainicio->dir);
		RetiraPilha(&pilha1);
		while (!PilhaVazia(pilha1))
			InserePilha(&paux, RetiraPilha(&pilha1));
		printf("\n");
	}
	while (!PilhaVazia(paux)) {
		printf("%c", TopoPilha(paux));
		InserePilha(&pilha1, RetiraPilha(&paux));
	}

	/*
	while (!PilhaVazia(pilha1)) {
		c = RetiraPilha(&pilha1);
		printf("%c", c);
		CaminhoFolhas(ainicio->esq);
		CaminhoFolhas(ainicio->dir);
		printf("\n");
	}
	*/

}

//--------------------------------------------
main (){
	arq = fopen("a1.txt", "r");
	Constroi(&aini);
	fclose(arq);
	LeArv(aini);
	printf("\n\n");
	InicializaPilha(&pilha1);
	InicializaPilha(&paux);
	CaminhoFolhas(aini);
	system("pause");
}
