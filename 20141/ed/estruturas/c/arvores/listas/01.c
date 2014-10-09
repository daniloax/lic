/* arvores binárias - algoritmos básicos: construção, gravação em arquivo
leitura, caminhamento(4), procura(2), procura com nó pai, remoção total, 
remoção de sub-árvore
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
  char dado;
  struct nodo *esq, *dir;
} arvore ;

arvore *aini;
FILE *arq, *arqsai;

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
void EscreveArquivo(arvore *ainicio) {
  if (ainicio == NULL) 
    putc ('.', arqsai);
  else {
    putc (ainicio->dado, arqsai);
    EscreveArquivo (ainicio->esq);
    EscreveArquivo (ainicio->dir);  
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
void CaminhaPre1(arvore *ainicio) {
  if (ainicio != NULL) {
    printf("%c", ainicio->dado);
    CaminhaPre1 (ainicio->esq);
    CaminhaPre1 (ainicio->dir);  
  }
}

//-------------------------------------------
void CaminhaPre2(arvore *ainicio) {
  printf("%c", ainicio->dado);
  if (ainicio->esq != NULL)
    CaminhaPre2 (ainicio->esq);
  if (ainicio->dir != NULL)
    CaminhaPre2 (ainicio->dir);  
}

//-------------------------------------------
void CaminhaIn(arvore *ainicio) {
  if (ainicio != NULL) {
    CaminhaIn (ainicio->esq);
    printf("%c", ainicio->dado);
    CaminhaIn (ainicio->dir);  
  }
}

//-------------------------------------------
void CaminhaPos(arvore *ainicio) {
  if (ainicio != NULL) {
    CaminhaPos (ainicio->esq);
    CaminhaPos (ainicio->dir);  
    printf("%c", ainicio->dado);
  }
}

//-------------------------------------------
void Remove(arvore **eainicio) {
  if (*eainicio != NULL) {
    Remove (&((*eainicio)->esq));
    Remove (&((*eainicio)->dir));  
    free (*eainicio);
    *eainicio = NULL;
  }
}

//-------------------------------------------
arvore *Procura1(arvore *ainicio, char chave) {
  arvore *a1;
  a1 = NULL;
  if (ainicio != NULL) {
    if (ainicio->dado == chave) 
      a1 = ainicio;
    if (a1 == NULL) 
      a1 = Procura1 (ainicio->esq, chave);
    if (a1 == NULL)
      a1 = Procura1 (ainicio->dir, chave); 
  }
  return a1;   
}

//-------------------------------------------
arvore *Procura2(arvore *ainicio, char chave) {
  arvore *a1;
  if (ainicio == NULL) 
    return NULL;
    else {
      a1 = ainicio;
      if (a1->dado != chave) {
        a1 = Procura2 (ainicio->esq, chave);
        if (a1 == NULL)
          a1 = Procura2 (ainicio->dir, chave); 
      }
  return a1;   
  }
}

//-------------------------------------------
arvore *ProcuraComAnt(arvore *ainicio, char chave, arvore **epai) {
  arvore *a1;
  a1 = NULL;
  if (ainicio != NULL) {
    if (ainicio->dado == chave)                             
      a1 = ainicio;
    if (a1 == NULL) {
      *epai = ainicio;
      a1 = ProcuraComAnt (ainicio->esq, chave, epai);
    }  
    if (a1 == NULL){
      *epai = ainicio;           
      a1 = ProcuraComAnt (ainicio->dir, chave, epai);
    }        
  } 
  if (a1 == NULL)
    *epai = NULL;
  return a1;  
}

//-------------------------------------------
void RemoveSub(arvore **eainicio, char chave) {
  arvore *a1, *aant;
  aant = NULL;
  a1 = ProcuraComAnt (*eainicio, chave, &aant);
  if (a1 == *eainicio)
    *eainicio = NULL;
  else 
    if (a1 != NULL)
      if (a1 == aant->esq)
        aant->esq = NULL;
      else
        if (a1 == aant->dir)
          aant->dir = NULL;
  Remove (&a1);
}

//--------------------------------------------
main ()
{
  arvore *aux, *auxant;
  char c;

  arq = fopen ("t11.txt", "r");
  Constroi (&aini);
  fclose (arq);
  LeArv(aini);
  printf("\n\n");
  CaminhaPre1 (aini);
  printf("\n\n");
  if (aini != NULL)
    CaminhaPre2 (aini);
  
/*  printf ("entre com dado da sub-arvore a ser removida \n");
  fflush(stdin);
  scanf ("%c" , &c);
  RemoveSub (&aini, c);
  LeArv(aini); */


/*  printf("\n\n");
  printf ("entre com dado a ser procurado \n");
  fflush(stdin);
  scanf ("%c" , &c); */

/*
  aux = Procura1 (aini, c);
  if (aux == NULL)
    printf ("ausente");
  else
    printf ("achou %c", aux->dado);  
*/

/*  auxant = NULL;
  aux = ProcuraComAnt (aini, c, &auxpai);
  if (aux == NULL){
    printf ("ausente");
    if (auxpai == NULL)
      printf ("  pai null \n");
  }
  else {
    printf ("achou %c", aux->dado);
    if (auxpai == NULL)
      printf ("  pai null \n");  
      else printf ("   pai %c", auxpai->dado);
  } */
  
/*  printf("\n\n");
  Remove(&aini);
  LeArv(aini);
  printf("\n\n");  */
  
/*  char nomearq[10];
  printf ("Entre com o nome do arquivo: \n");
  scanf ("%s", nomearq);
  arqsai = fopen (nomearq, "w");
  EscreveArquivo (aini);
  fclose(arqsai);   */
  
/*  printf("\n\n");
  CaminhaPre1 (aini);
  printf("\n\n");
  CaminhaIn (aini);
  printf("\n\n");
  CaminhaPos (aini);
  printf("\n\n"); */


  printf("\n\n");
  system("pause");
}