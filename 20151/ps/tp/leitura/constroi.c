#include "constroi.h"

void ConstroiListaProjeto(ListaProjeto **epinicio, char *arquivo) {
 
   FILE *pArquivo;
   
   char c;
   
   pArquivo = fopen(arquivo, "r");
   
   if (!pArquivo)
      printf("'%s' not exist\n", arquivo);
      
   else
      while ((c = getc(pArquivo)) != EOF)
         printf("%c", c);
   
}

void ConstroiListaDiscente(ListaDiscente **epinicio, char *arquivo) {

   FILE *pArquivo;
   
   char separador;
   char buffer[78];
   char nome[30];

	int anoMatricula;
	int matricula;
	
	ListaDiscente *pd1;
	ListaDiscente *pd2;
	
   TipoPessoa *discente;

   pArquivo = fopen(arquivo, "r");

   if (!pArquivo)
      printf("'%s' not exist\n", arquivo);

   else {
		
		/** descarta informacoes de cabecalho do arquivo de entrada 
       *  ate encontrar a palavra Matricula */
		while (strcmp("Matricula", nome) != 0) {
				
			fgets(buffer, sizeof(buffer), pArquivo);
			sscanf(buffer,"%s", &nome);
			
		}
		
		/** filtra informacoes e constroi lista de discentes */
		while ((fgets(buffer, sizeof(buffer), pArquivo)) != NULL ) {
			
			if (sscanf(buffer,"%d%c%d %[^\n]s", &anoMatricula, &separador, &matricula, nome) == 4) {
				
				discente = malloc(sizeof(TipoPessoa));
				 
				discente->anoMatricula = anoMatricula;
				discente->matricula = matricula;
				
            discente->nome = calloc(strlen(nome), sizeof(char));
            strcpy(discente->nome, nome);
				
				pd1 = malloc(sizeof(ListaDiscente));
				
				pd1->discente = discente;
				pd1->proximoDiscente = NULL;
				
				if (*epinicio == NULL)
					*epinicio = pd1;
				
				else
					pd2->proximoDiscente = pd1;
					
				pd2 = pd1;
				
				while (getc(pArquivo) != 10);
		
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
