#ifndef CADASTRA_H_
#define CADASTRA_H_

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

int idsem;

int main(int argc, char *argv[]);

#endif /* CADASTRA_H_ */
