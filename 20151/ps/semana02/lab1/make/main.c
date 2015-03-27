#include <stdio.h>
#include <stdlib.h>

int main () {

  struct lista_disc *pinicio;

  ConstroiMalha (&pinicio);
  PercorreMalha (pinicio);
  PercursoLinear (pinicio);
    
  system("pause");
}
