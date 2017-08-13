/* Sessão de Laboratório 2

As disciplinas que um aluno deve cursar são identificadas por letras. Cada uma
delas pode ter pre-requisitos. O arquivo que guarda os dados tem a seguinte 
forma:

a 2 d e
b 0
c 3 b d e
d 2 b e
e 1 b

significando que a disciplina a só pode ser cursada depois de cursadas as 
disciplinas d e e; a disciplina b pode ser cursada imediatamente; a disciplina c
só pode ser cursada depois da b, d, e; e assim por diante.

Abaixo estão disponíveis as funções para constuir a estrutura de dados a partir
do arquivo e para percorrer a estrutura, escrevendo-a na tela. O arquivo a1.txt
é apenas um exemplo para teste. Suponha que os arquivos estão sempre corretamente construídos.

O ARQUIVO a2.txt É COMPOSTO POR 3 LINHAS: A PRIMEIRA LINHA É
UM NOVO ELEMENTO A SER INSERIDO NA LISTA PRINCIPAL; A SEGUNDA LINHA SÃO OS
ELEMENTOS QUE SÃO PRÉ-REQUISITOS DO ELEMENTO NOVO; A TERCEIRA LINHA SÃO OS
ELEMENTOS QUE TÊM O NOVO ELEMENTO COMO PRÉ-REQUISITO.

FAÇA UMA FUNÇÃO QUE LEIA UM ARQUIVO NO PADRÃO DE a2.txt E REMODELE A ESTRUTURA
DE DADOS. NÃO SE PREOCUPE COM A CONSISTÊNCIA DOS DADOS DOS ARQUIVOS.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_pre {
	
	struct lista_disc *ppre;
	struct lista_pre *proxp;

} lista2;

typedef struct lista_disc {
	
	int cursado;
	char disc;
	struct lista_disc *proxd;
	lista2 *pacesso;

} lista1;

//----------------------------------------
void ConstroiMalha(lista1 **epinicio) {
	
	FILE *arq;
	lista1 *pd1, *pd2;
	lista2 *pp1, *pp2;
	char c, nomeArquivo[10];
	int i, n;

	printf("NOME DO ARQUIVO: ");
	scanf("%s", nomeArquivo);
	getchar();
	
	arq = fopen (nomeArquivo, "r");
	
	if (!arq)
		printf("'%s' inexistente\n", nomeArquivo);
		
	else {
	
		*epinicio = NULL;

		while ((c = getc (arq)) != EOF) {

			pd1 = malloc (sizeof (lista1));
			pd1->cursado = 0;
			pd1->disc = c;
			pd1->pacesso = NULL;
			pd1->proxd = NULL;
			
			if (*epinicio == NULL)
				*epinicio = pd1;
			else
				pd2->proxd = pd1;

			pd2 = pd1;

			while ((c = getc (arq)) != '\n');

		}

		fclose (arq);

		arq = fopen (nomeArquivo, "r");
		pd1 = *epinicio;

		while ((c = getc (arq)) != EOF) {

			fscanf (arq, "%d ", &n); 
			
			for (i = 1; i != n + 1; i++) {
				
				c = getc (arq); 
				pp1 = malloc (sizeof (lista2));
				pp1->ppre = *epinicio;

				while (pp1->ppre->disc != c)
					pp1->ppre = pp1->ppre->proxd;

				pp1->proxp = NULL;

				if (pd1->pacesso == NULL)
					pd1->pacesso = pp1;
		
				else pp2->proxp = pp1;
					pp2 = pp1;
			
				c = getc (arq);  

			}

			pd1 = pd1->proxd;

		}
	
	}

}

//--------------------------------------------
void PercorreMalha(lista1 *pinicio) {

	lista1 *pd1;
	lista2 *pp1;

	if (pinicio == NULL)
		printf ("lista vazia \n");

	else {

		pd1 = pinicio;

		while (pd1 != NULL) {

			printf("%c", pd1->disc);
			pp1 = pd1->pacesso;

			while (pp1 != NULL) {

				printf("%2c", pp1->ppre->disc);
				pp1 = pp1->proxp;
	
			}  

			pd1 = pd1->proxd; 
			printf("\n");  
	
		}

	}

	printf("\n");         

}

//--------------------------------------------
void AdicionaDisciplina(lista1 **epinicio) {

	FILE *arq;
	lista1 *pd1, *pd2;
	lista2 *pp1, *pp2;
	char c, nomeArquivo[10];
	
	printf("NOME DO ARQUIVO: ");
	scanf("%[^\n]s", nomeArquivo);
	getchar();
	
	arq = fopen(nomeArquivo, "r");
	
	if (!arq)
		printf("'%s' inexistente\n", nomeArquivo);
		
	else {
	
		pd1 = *epinicio;
  
		while (pd1 != NULL) {
			
			pd2 = pd1;
			pd1 = pd1->proxd;
			
		}
		
		c = getc (arq);
		pd1 = malloc (sizeof (lista1));
		pd1->cursado = 0;
		pd1->disc = c;
		pd1->pacesso = NULL;
		pd1->proxd = NULL;
		pd2->proxd = pd1;
		
		pd1 = *epinicio;
		
		while (pd1 != NULL) {
		
			if (pd1->pacesso != NULL) {
			
				pp1 = pd1->pacesso;
				
				while (pp1 != NULL) {
    
					pp2 = pp1;
					pp1 = pp1->proxp;
					
				}
					
				pp1 = malloc(sizeof (lista2));
				pp1->ppre = *epinicio;
				
				while (pp1->ppre->disc != c)
					pp1->ppre = pp1->ppre->proxd;
					
				pp2->proxp = pp1;
				pp1->proxp = NULL;
				
			} else {
			
				pp1 = malloc(sizeof (lista2));
				pp1->ppre = *epinicio;
				
				while (pp1->ppre->disc != c)
					pp1->ppre = pp1->ppre->proxd;
					
				pd1->pacesso = pp1;
				pp1->proxp = NULL;
				
			}                
			
			pd1 = pd1->proxd;
			
		}

		fclose (arq);
		
	}
		
}   

//--------------------------------------------
int main () {

	struct lista_disc *pini;

	ConstroiMalha(&pini);
	PercorreMalha(pini);

	AdicionaDisciplina(&pini);
	PercorreMalha(pini);

	system("pause");
    return 0;

}

