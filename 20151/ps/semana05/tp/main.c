#include "main.h"

int main() {
	
	char discentesMestrado[] = "io/discentes_mestrado.txt";
	char discentesDoutorado[] = "io/discentes_doutorado.txt";
   
   struct ListaDiscente *pInicioDiscentes;
   struct ListaDocente *pInicioDocentes;
   
   pInicioDiscentes = NULL;
   pInicioDocentes = NULL;
   
   ConstroiListaDiscente(&pInicioDiscentes, discentesMestrado);
   ConstroiListaDiscente(&pInicioDiscentes, discentesDoutorado);
   
   OrdenaListaDiscente(&pInicioDiscentes);
   PercorreListaDiscente(pInicioDiscentes);
   
   return 0;
   
}
