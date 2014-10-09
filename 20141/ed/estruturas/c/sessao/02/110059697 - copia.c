/*
* Universidade de Brasilia
* Departamento de Ciencia da Computacao
* Estrutura de Dados
* Professor: Homero Piccolo
* 
* Aluno: Danilo Alves Xavier
* Matricula: 11/0059697
* Curso: Computacao/Licenciatura
* 
* Programa: Inclusao de Disciplina e Pre-requisitos em Malha de Listas
* 
* */

#include <stdio.h>
#include <stdlib.h>

/*
 * Estrutura de lista de pre-requistos
 * 
 * */
typedef struct lista_pre {
	
	struct lista_disc *ppre;
	struct lista_pre *proxp;

} lista2;

/*
 * Estrutura de lista de disciplinas
 * 
 * */
 typedef struct lista_disc {
	
	int cursado;
	char disc;
	struct lista_disc *proxd;
	lista2 *pacesso;

} lista1;

/*
 * Funcao Contruir Malha
 * Constroi malha
 * Funcao solicita nome de arquivo para construcao de malha
 * 
 * */
void ConstroiMalha(lista1 **epinicio) {
	
	FILE *arq;
	lista1 *pd1, *pd2;
	lista2 *pp1, *pp2;
	char c, nomeArquivo[10];
	int i, n;

	do {
	
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
		
	} while (!arq);

}

/*
 * Funcao Percorrer Malha
 * Percorre lista de disciplinas e pre-requisitos
 * 
 * */
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

/*
 * Funcao Adicionar Disciplina
 * Adiciona disciplina ao final da lista de disciplinas
 * seus respectivos pre-requisitos e inclui nova disciplina
 * como pre-requisito em disciplinas pre-existentes
 * 
 * */
void AdicionaDisciplina(lista1 **epinicio) {

	FILE *arq;
	lista1 *pd1, *pd2;
	lista2 *pp1, *pp2;
	char c, disciplina, nomeArquivo[10];
	
	do {
		
		printf("NOME DO ARQUIVO: ");
		scanf("%[^\n]s", nomeArquivo);
		getchar();
		
		arq = fopen(nomeArquivo, "r");
		
		if (!arq)
			printf("'%s' inexistente\n", nomeArquivo);
			
		else {
		
			pd1 = *epinicio;
	  
			// adiciona disciplina
			while ((c = getc (arq)) != '\n') {
				
				while (pd1 != NULL) {
					
					pd2 = pd1;
					pd1 = pd1->proxd;
					
				}
				
				disciplina = c;
				pd1 = malloc (sizeof (lista1));
				pd1->cursado = 0;
				pd1->disc = c;
				pd1->pacesso = NULL;
				pd1->proxd = NULL;
				pd2->proxd = pd1;
				
			}
			
			// adiciona pre-requisitos
			while ((c = getc (arq)) != '\n') {
				
				pp1 = malloc(sizeof (lista2));
				pp1->ppre = *epinicio;
				
				while (pp1->ppre->disc != c)
					pp1->ppre = pp1->ppre->proxd;
					
				if (pd1->pacesso == NULL)
					pd1->pacesso = pp1;
					
				else
					pp2->proxp = pp1;
					
				pp1->proxp = NULL;
				pp2 = pp1;
				pp1 = pp1->proxp;
				
			}
			
			pd1 = *epinicio;
			
			// inclui nova disciplina como pre-requisito
			while (((c = getc (arq)) != '\n') && (c != EOF)) {
			
				while (pd1 != NULL) {
				
					if (pd1->disc == c) {
				
						if (pd1->pacesso != NULL) {
						
							pp1 = pd1->pacesso;
							
							while (pp1 != NULL) {
				
								pp2 = pp1;
								pp1 = pp1->proxp;
								
							}
								
							pp1 = malloc(sizeof (lista2));
							pp1->ppre = *epinicio;
							
							while (pp1->ppre->disc != disciplina)
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

					}
					
					pd1 = pd1->proxd;

				}
				
				pd1 = *epinicio;
				
			}

			fclose (arq);
			
		}
		
	} while (!arq);
	
}   

/*
 * Funcao principal
 * 
 * */
int main () {

	struct lista_disc *pini;

	ConstroiMalha(&pini);
	PercorreMalha(pini);

	AdicionaDisciplina(&pini);
	PercorreMalha(pini);

	system("pause");
    return 0;

}

