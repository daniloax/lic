#ifndef CADASTRA_H_
#define CADASTRA_H_

#include <errno.h>
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

int main(int argc, char *argv[]);

#endif /* CADASTRA_H_ */
