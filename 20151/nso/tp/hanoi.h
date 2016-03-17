#ifndef HANOI_H_
#define HANOI_H_

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

struct reghanoi {
   char o;
   char d;
   char a;
   int k;
};

typedef struct tipopilhageral {
   void *dado;
   struct tipopilhageral *prox;
} pilhageral;

void InicializaPilha(pilhageral **epilha);
int PilhaVazia (pilhageral *pilha);
void *TopoPilha(pilhageral *pilha);
void InserePilha(pilhageral **epilha, void *dadonovo);
void *RetiraPilha(pilhageral **epilha);
void WriteFormatted (FILE * stream, const char * format, ...);
void EmpilhaHanoi(pilhageral **epilha, char origem, char destino, char auxiliar, int n);
void DesempilhaHanoi(pilhageral **epilha, char *origem, char *destino, char *auxiliar, int *n);
int main(int argc, char *argv[]);

#endif /* HANOI_H_ */
