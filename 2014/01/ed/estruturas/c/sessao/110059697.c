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
	 * Programa: Uniao e Interseccao de Listas Abertas de Encadeamento Simples
	 * 
	 * */

	#include <stdio.h>
	#include <stdlib.h>

	/*
	 * Estrutura de lista simples
	 * 
	 * */

	typedef struct elemento {
		char dado;
		struct elemento *prox;
	} listaS;

	/*
	 * Funcao Contruir Lista
	 * Constroi lista aberta de encadeamento simples
	 * Funcao solicita nome de arquivo para construcao de lista
	 * 
	 * */

	void** ConstroiListaAS2(listaS **epinicio) {
		
		FILE *arq;
		listaS *p1, *p2;
		char c, nomeArquivo[20];

		printf("NOME DO ARQUIVO: ");
		scanf("%[^\n]s", nomeArquivo);
		getchar();

		arq = fopen (nomeArquivo, "r");
		*epinicio = NULL;
		
		while (((c = getc (arq)) != EOF) && (c != '\n')) {
			
			p1 = malloc (sizeof (listaS));
			p1->dado = c;
			
			if (*epinicio == NULL)
				*epinicio = p1;
			else
				p2->prox = p1;
			
			p2 = p1;
		
		}
		
		p1->prox = NULL;

		fclose (arq);
	
	}

	/*
	 * Funcao Percorrer Lista
	 * Percorre elementos de lista aberta de encadeamento simples
	 * 
	 * */
	 
	void PercorreListaAS(listaS *pinicio) {
		
		listaS *p1;
		int i = 1;

		if (pinicio == NULL)
			printf ("VAZIA \n");
		
		else {
			
			p1 = pinicio;
			
			while (p1 != NULL) {
				printf("%do ELEMENTO:  %c \n", i, p1->dado);
				p1 = p1->prox;
				i += 1;
			}
		
		}
		
		printf ("\n");
	
	}
	
	/*
	 * Funcao Interseccao 
	 * Intersecta elementos de duas listas abertas de encadeamento simples
	 * 
	 * */	

	void** InterseccaoListaAS(listaS *pinicio1, listaS *pinicio2, listaS **epinicio3) {
		
		listaS *p1, *p2, *p3, *p4;

		p1 = pinicio1;
		p2 = pinicio2;
		*epinicio3 = NULL;
		
		while (p1 != NULL) {
			
			while (p2 != NULL) {

				if (p1->dado == p2->dado) {

					p3 = malloc (sizeof (listaS));
					p3->dado = p1->dado;

					if (*epinicio3 == NULL)
						*epinicio3 = p3;
					
					else
						p4->prox = p3;

					p4 = p3;
					p3->prox = NULL;

				}

				p2 = p2->prox;

			}
			
			p1 = p1->prox;
			p2 = pinicio2;
			
		}

	}

	/*
	 * Funcao Uniao 
	 * Intersecta elementos de duas listas abertas de encadeamento simples
	 * 
	 * */	
	
	void** UniaoListaAS2(listaS *pinicio1, listaS *pinicio2, listaS **epinicio3) {
		
		listaS *p1, *p2, *p3, *p4, *p5;

		p1 = pinicio1;
		p2 = pinicio2;
		*epinicio3 = NULL;
		
		while ((p1 != NULL) || (p2 != NULL)) {
			
			if (p1 != NULL) {
			
				p3 = malloc (sizeof (listaS));
				p3->dado = p1->dado;
			
			}
			
			if (p2 != NULL) {
				
				p4 = malloc (sizeof (listaS));
				p4->dado = p2->dado;
				
			}
			
			if ((p1 != NULL) && (p2 != NULL)) {

				p3->prox = p4;
				p4->prox = NULL;
				
			} else if (p1 != NULL) {
					
				p3->prox = NULL;
				
			} else {
				
				p4->prox = NULL;
				
			}
			
			if (*epinicio3 == NULL)		
				*epinicio3 = p3;
			
			else if (p1 != NULL)
				p5->prox = p3;
				
			else
				p5->prox = p4;
				
			if ((p1 != NULL) && (p2 != NULL)) {

				p5 = p4;
				p1 = p1->prox;
				p2 = p2->prox;
				
			} else if (p1 != NULL) {
					
				p5 = p3;
				p1 = p1->prox;
				
			} else {
				
				p5 = p4;
				p2 = p2->prox;
				
			}
		
		}

	}

	/*
	 * Funcao principal
	 * 
	 * */	

	main () {

		listaS *pinicio1, *pinicio2, *pinterseccao, *puniao;

		printf ("LISTA 1 - ");
		ConstroiListaAS2(&pinicio1);
		printf ("LISTA 2 - ");
		ConstroiListaAS2(&pinicio2);
      
		printf ("\nELEMENTOS LISTA 1:\n");
		PercorreListaAS(pinicio1);
		printf ("ELEMENTOS LISTA 2:\n");
		PercorreListaAS(pinicio2);

		InterseccaoListaAS(pinicio1, pinicio2, &pinterseccao);
		UniaoListaAS2(pinicio1, pinicio2, &puniao);

		printf ("LISTA INTERSECCAO:\n");
		PercorreListaAS(pinterseccao);
		printf ("LISTA UNIAO:\n");
		PercorreListaAS(puniao);

		system("pause");

	}
