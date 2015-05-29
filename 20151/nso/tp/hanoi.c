#include "hanoi.h"

void InicializaPilha(pilhageral **epilha) {
	
   *epilha = NULL;

}

int PilhaVazia (pilhageral *pilha) {
	
   return (pilha == NULL);

}

void *TopoPilha(pilhageral *pilha) {
	
   return pilha->dado;

}

void InserePilha(pilhageral **epilha, void *dadonovo) {
	
   pilhageral *p1;
	
   p1 = malloc (sizeof (pilhageral));
	p1->dado = dadonovo;
	p1->prox = *epilha;
	*epilha = p1;

}

void *RetiraPilha(pilhageral **epilha) {
	
   pilhageral *p1;
	void *valor;
	
   p1 = *epilha;
   *epilha = p1->prox;
	valor = p1->dado;
	free (p1);
	
   return valor;
   
}
   
void WriteFormatted (FILE * stream, const char * format, ...) {
  
  va_list args;
  va_start (args, format);
  vfprintf (stream, format, args);
  va_end (args);

}

void EmpilhaHanoi(pilhageral **epilha, char origem, char destino, char auxiliar, int n) {
   
   struct reghanoi *paux1;
   void *paux2;
   
   paux1 = malloc(sizeof(struct reghanoi));
   paux1->o = origem;
   paux1->d = destino;
   paux1->a = auxiliar;
   paux1->k = n;
   paux2 = paux1;
   InserePilha (epilha, paux2);

}

void DesempilhaHanoi(pilhageral **epilha, char *origem, char *destino, char *auxiliar, int *n) {

   struct reghanoi *paux1;
   void *paux2;

   paux2 = RetiraPilha (epilha);
   paux1 = paux2;
   *origem = paux1->o;
   *destino = paux1->d;
   *auxiliar = paux1->a;
   *n = paux1->k;
   free (paux2);

}

int main(int argc, char *argv[]) {
   
   FILE *pFile;
   pilhageral *phanoi;
   
   char origem, destino, auxiliar;
   int idsem, key, n;
   
   pFile = fopen("hanoi.txt", "w");
   
   origem = 'a';
   destino = 'b';
   auxiliar = 'c';
   
   key = atoi(argv[1]);
   n = atoi(argv[2]);
   
   /** obtem semaforo */
   if ((idsem = semget(key, 1, 0)) < 0) {
      
      perror("semget");
      exit(EXIT_FAILURE);
   
   }
   
   if (n < 1)
      WriteFormatted (pFile, "nao ha movimentos a serem realizados\n");
   
   else {

      if (n > 10)
         WriteFormatted (pFile, "entre com um valor entre 1 e 10\n");
         
      else {
   
         InicializaPilha(&phanoi);
         EmpilhaHanoi(&phanoi, origem, destino, auxiliar, n);
         
         while (!PilhaVazia (phanoi)) {
            
            DesempilhaHanoi(&phanoi, &origem, &destino, &auxiliar, &n);
            
            if (n == 1)
               WriteFormatted (pFile, "movimento de %c para %c\n", origem, destino);
            
            else {
            
               EmpilhaHanoi(&phanoi, auxiliar, destino, origem, n - 1);
               EmpilhaHanoi(&phanoi, origem, destino, auxiliar, 1);
               EmpilhaHanoi(&phanoi, origem, auxiliar, destino, n - 1);
            
            }
      
         }
         
      }
      
   }
   
   fclose(pFile);
   
   return 0;
   
}
