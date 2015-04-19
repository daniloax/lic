#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

#include "constroi.h"
#include "linear.h"
#include "percorre.h"

typedef enum {
   CONSTRUIR = 1,
   PERCORRE_MALHA = 2,
   PERCURSO_LINEAR = 3,
   FECHAR_PROGRAMA = 4} OpcaoMenu;

int main();

#endif /* PERCORRE_H_ */
