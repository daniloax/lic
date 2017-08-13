/* sessao 4 B 

preencha os dados:
         
Nome:
     
Matr�cula

S�o dadas abaixo as fun��es para construir e ler uma �rvore bin�ria (n�o de 
pesquisa) contendo em cada n� um caractere, a partir do arquivo na forma
vista em aula.

Fa�a uma fun��o que percorra uma �rvore bin�ria e escreva na tela o n�mero de n�s
do maior caminho entre a raiz e uma das folhas. Ou seja, escreva o tamanho do
caminho entre a raiz e a folha mais distante da raiz (em n�mero de n�s, incluindo
a raiz e a folha).

Exemplo:
         
Dado:     ab..cd.f..e..
 
Resposta:  4
 
 A fun��o n�o deve destruir a �rvore dada, nem usar outros recursos ou 
 estruturas al�m dos fornecidos nesta quest�o. S�o permitidas vari�veis globais.
*/

#include <stdio.h>
#include <stdlib.h>


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


//--------------------------------------------
main (){


  arq = fopen ("a1.txt", "r");
  Constroi (&aini);
  fclose (arq);
  LeArv(aini); 
  printf("\n\n"); 
  


  system("pause");
}
     
     
