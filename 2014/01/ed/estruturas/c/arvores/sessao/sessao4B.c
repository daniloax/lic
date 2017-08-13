/* sessao 4 B 

preencha os dados:
         
Nome:
     
Matrícula

São dadas abaixo as funções para construir e ler uma árvore binária (não de 
pesquisa) contendo em cada nó um caractere, a partir do arquivo na forma
vista em aula.

Faça uma função que percorra uma árvore binária e escreva na tela o número de nós
do maior caminho entre a raiz e uma das folhas. Ou seja, escreva o tamanho do
caminho entre a raiz e a folha mais distante da raiz (em número de nós, incluindo
a raiz e a folha).

Exemplo:
         
Dado:     ab..cd.f..e..
 
Resposta:  4
 
 A função não deve destruir a árvore dada, nem usar outros recursos ou 
 estruturas além dos fornecidos nesta questão. São permitidas variáveis globais.
*/

#include <stdio.h>
#include <stdlib.h>


//-- definição, leitura e escrita de árvores---
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
     
     
