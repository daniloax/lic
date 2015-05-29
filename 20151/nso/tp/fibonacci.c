#include "fibonacci.h"

void InicializaPilha (pilhaint **epilha) {
	*epilha = NULL;
}

int PilhaVazia (pilhaint *pilha) {
	return (pilha == NULL);
}

int TopoPilha(pilhaint *pilha) {
	return pilha->dado;
}

void InserePilha(pilhaint **epilha, int dadonovo) {
	pilhaint *p1;
	p1 = malloc (sizeof(pilhaint));
	p1->dado = dadonovo;
	p1->prox = *epilha;
	*epilha = p1;
}

int RetiraPilha(pilhaint **epilha) {
	pilhaint *p1;
	int valor;
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

unsigned long long int Fibonacci(unsigned long long int n) {
   
   pilhaint *p1;
   unsigned long long int fib, x;

   InicializaPilha(&p1);
   InserePilha(&p1, n);
   fib = 0;
   
   while (!PilhaVazia(p1)) {
      
      x = RetiraPilha (&p1);
      
      if ((x == 0) || (x == 1))
         fib = fib + 1;
   
      else {
         
         InserePilha (&p1, x-1);
         InserePilha (&p1, x-2);
      
      }
   }
   
   return fib;

}

int main(int argc, char *argv[]) {
   
   FILE *pFile;
   
   int c, i, idsem, key, n;
   
   pFile = fopen("fibonacci.txt", "w");
   
   i = 0;
   
   key = atoi(argv[1]);
   n = atoi(argv[2]);
   
   /** obtem semaforo */
   if ((idsem = semget(key, 1, 0)) < 0) {
      
      perror("semget");
      exit(EXIT_FAILURE);
   
   }
   
   if (n < 1) 
      WriteFormatted (pFile, "nao ha elementos a serem calculados\n");
   
   else {

      if (n > 40)
         WriteFormatted (pFile, "entre com um valor entre 1 e 40\n");
      
      else {
         
         for (c = 0; c < n; c++) {
            
            WriteFormatted (pFile, "%u\n", Fibonacci(i));
            i++;
            
         }
      
      }
   
   }
   
   fclose(pFile);
   
   return 0;
   
}
