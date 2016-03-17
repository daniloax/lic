#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "semaforo.h"

typedef struct tipopilha {
	int dado;
	struct tipopilha *prox;
} pilhaint;

void InicializaPilha(pilhaint **epilha);
int PilhaVazia(pilhaint *pilha);
int TopoPilha(pilhaint *pilha);
void InserePilha(pilhaint **epilha, int dadonovo);
int RetiraPilha(pilhaint **epilha);
void WriteFormatted (FILE * stream, const char * format, ...);
unsigned long long int Fibonacci(unsigned long long int n);
int main(int argc, char *argv[]);

#endif /* FIBONACCI_H_ */
