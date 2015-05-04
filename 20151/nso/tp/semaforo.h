#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

struct semid_ds semid_ds;
struct sembuf operacao[2];

union semun {
   int val;
   struct semid_ds *buf;
   unsigned short *array;
} arg;

static unsigned int idsem;

unsigned int getIdSem();
void setIdSem(unsigned int idsem);

void p_sem(unsigned int idsem);
void v_sem(unsigned int idsem);

#endif /* SEMAFORO_H_ */
