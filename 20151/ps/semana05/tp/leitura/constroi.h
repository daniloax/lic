#ifndef CONSTROI_H_
#define CONSTROI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../estrutura/lista.h"
#include "../estrutura/pessoa.h"
#include "../estrutura/string.h"

void ConstroiListaDiscente(ListaDiscente **epinicio, char *arquivo);
void OrdenaListaDiscente(ListaDiscente **epinicio);
void PercorreListaDiscente(ListaDiscente *pinicio);

#endif /* CONSTROI_H_ */
