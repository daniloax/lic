#include "main.h"

int main() {
	
	char discentesMestrado[] = "io/discentes_mestrado.txt";
	char discentesDoutorado[] = "io/discentes_doutorado.txt";
   char projetos[] = "io/projetos.txt";
   
   struct ListaDiscente *pInicioDiscentes;
   struct ListaDocente *pInicioDocentes;
   struct ListaProjeto *pInicioProjetos;
   
   pInicioDiscentes = NULL;
   pInicioDocentes = NULL;
   pInicioDocentes = NULL;
   
   ConstroiListaDiscente(&pInicioDiscentes, discentesMestrado);
   ConstroiListaDiscente(&pInicioDiscentes, discentesDoutorado);
   
   // OrdenaListaDiscente(&pInicioDiscentes);
   PercorreListaDiscente(pInicioDiscentes);
   
   ConstroiListaProjeto(&pInicioProjetos, projetos);
   
   return 0;
   
}
