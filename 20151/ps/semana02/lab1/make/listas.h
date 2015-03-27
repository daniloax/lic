typedef struct lista_pre {
  struct lista_disc *ppre;
  struct lista_pre *proxp;
} lista2;

typedef struct lista_disc {
  int cursado;
  char disc;
  struct lista_disc *proxd;
  lista2 *pacesso;
} lista1;
