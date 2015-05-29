#include "constroi.h"

void ConstroiListaDiscente(ListaDiscente **epinicio, char *arquivo) {

   FILE *pArquivo;
   
   char separador; // separador do formato ano/matricula
   char buffer[78]; // buffer temporario
   char nome[30];

	int anoMatricula;
	int matricula;
	
	ListaDiscente *pd1; // ponteiro para a estrutura ListaDiscente
	ListaDiscente *pd2; // ponteiro para a estrutura ListaDiscente
	
	TipoPessoa *discente; // ponteiro para a estrutura TipoPessoa

   /* abre arquivo */
   pArquivo = fopen(arquivo, "r");

   if (!pArquivo)
      printf("'%s' not exist\n", arquivo);

   else {
		
		/** descarta informacoes de cabecalho do arquivo de entrada 
       *  ate encontrar a palavra Matricula */
		while (strcmp("Matricula", nome) != 0) {
				
			fgets(buffer, sizeof(buffer), pArquivo); // grava em buffer os primeiros 77 caracteres da linha do arquivo
			sscanf(buffer,"%s", &nome); // le de buffer um formato string qualquer e grava em nome
			
		}
		
		/** filtra informacoes e constroi lista de discentes */
		while ((fgets(buffer, sizeof(buffer), pArquivo)) != NULL ) { // grava em buffer os primeiros 77 caracteres da linha do arquivo
			
			if (sscanf(buffer,"%d%c%d %[^\n]s", &anoMatricula, &separador, &matricula, nome) == 4) { // le de buffer o formato <ano></><matricula><espaco><nome> e grava respectivamente em ano, separador, matricula e nome
				
				discente = malloc(sizeof(TipoPessoa)); // atribui a discente a alocacao de memoria para a estrutura TipoPessoa
				 
				discente->anoMatricula = anoMatricula; // atribui o ano de matricula ao ano de matricula do discente 
				discente->matricula = matricula; // atribui o numero de matricula do buffer ao ano de matricula do discente
				
            discente->nome = calloc(strlen(nome), sizeof(char)); // atribui ao nome do discente a alocacao de um array de caracteres do tamanho de nome, obtido a partir do buffer
            strcpy(discente->nome, nome); // copia os caracteres de nome para o nome do discente
				
				pd1 = malloc(sizeof(ListaDiscente)); // atribui a pd1 a alocacao de memoria para a estrutura ListaDiscente
				
				pd1->discente = discente; // atribui ao elemento discente da ListaDiscente o discente recem criado
				pd1->proximoDiscente = NULL; // atribui ao elemento proximoDiscente o valor nulo
				
				if (*epinicio == NULL) // se a lista estiver vazia, ou seja, se o valor do ponteiro para a lista de discentes for nulo
					*epinicio = pd1; // atribui o elemento do tipo ListaDiscente recem criado ao ponteiro de inicio da lista
				
				else // senao, se a lista nao estiver vazia
					pd2->proximoDiscente = pd1; // atribui o elemento do tipo ListaDiscente recem criado ao ponteiro de proximo elemento da lista
					
				pd2 = pd1; // atribui o elemento do tipo ListaDiscente recem criado ao ponteiro auxiliar
				
				while (getc(pArquivo) != 10); // enquanto getc nao encontrar caracter de nova linha descarta o caracter lido
		
			}
			
		}
		
	}
	
	fclose (pArquivo);

}

void PercorreListaDiscente(ListaDiscente *pinicio) {
	
	int matricula;
	int anoMatricula;
	
	ListaDiscente *pd1;
	
	TipoPessoa *discente;
	char *nome;
	
	matricula = 0;
	anoMatricula = 0;
	
	pd1 = NULL;
	
	discente = NULL;
	nome = "/0";

	if (pinicio == NULL)
		printf("Lista Vazia!");
		
	else {
		
		pd1 = pinicio;

		while (pd1 != NULL) {
			
			discente = (TipoPessoa *) pd1->discente;
			nome = discente->nome;
			anoMatricula = discente->anoMatricula;
			matricula = discente->matricula;
			printf("%02d/%07d %s\n", anoMatricula, matricula, nome);
			pd1 = pd1->proximoDiscente;
			
		}

	}
	
}

void OrdenaListaDiscente(ListaDiscente **epinicio) {
   
   int comparaNome;
   
   ListaDiscente *p1;
   ListaDiscente *p2;
   ListaDiscente *paux;
   
   TipoPessoa *d1;
   TipoPessoa *d2;

   if (*epinicio != NULL)  {
      
      p1 = *epinicio;
      
      while (p1->proximoDiscente != NULL) {
         
         d1 = p1->discente;
         p2 = p1->proximoDiscente;
      
         while (p2 != NULL) {
            
            d2 = p2->discente;
            comparaNome = strcmp(d1->nome, d2->nome);
         
            if (comparaNome > 0) {
               
               if (p1->proximoDiscente == p2) {
                  
                  p1->proximoDiscente = p2->proximoDiscente;
                  /* p2->ant = p1->ant;
                  
                  if (!(p2->prox == NULL))
                     p2->prox->ant = p1;
                  
                  if (!(p1->ant == NULL))
                     p1->ant->prox = p2; */
                  
                  p2->proximoDiscente = p1;
                  // p1->ant = p2;
                  
                  if (*epinicio == p1)
                     *epinicio = p2;
                  
                  paux = p1;
                  p1 = p2;
                  p2 = paux;
               
               } else {
                  
                  /* p2->ant->prox = p1;
                  p1->prox->ant = p2;
                  
                  if (!(p2->prox == NULL))
                     p2->prox->ant = p1;
                  
                  if (!(p1->ant == NULL))
                     p1->ant->prox = p2;
                  
                  paux = p1->ant;
                  
                  p1->ant = p2->ant;
                  p2->ant = paux; */
                  paux = p1->proximoDiscente;
                  p1->proximoDiscente = p2->proximoDiscente;
                  p2->proximoDiscente = paux;
                  
                  if (*epinicio == p1)
                     *epinicio = p2;
                  
                  paux = p1;
                  p1 = p2;
                  p2 = paux;        
               
               }
            
            }  
            
            p2 = p2->proximoDiscente;  
         
         }
         
         p1 = p1->proximoDiscente;  
      
      }
   
   }

}
