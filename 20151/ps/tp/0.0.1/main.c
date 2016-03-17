#include "main.h"

int main() {
	
	char discentesMestrado[] = "Arquivos/discentes_mestrado.txt";
	char discentesDoutorado[] = "Arquivos/discentes_doutorado.txt";
   char projetos[] = "Arquivos/projetos.txt";
   
   struct ListaDiscente *pInicioDiscentes;
   struct ListaDocente *pInicioDocentes;
   struct ListaProjeto *pInicioProjetos;
   
   pInicioDiscentes = NULL;
   pInicioDocentes = NULL;
   pInicioProjetos = NULL;
   
   ConstroiListaDiscente(&pInicioDiscentes, discentesMestrado);
   ConstroiListaDiscente(&pInicioDiscentes, discentesDoutorado);
   ConstroiListaProjeto(&pInicioProjetos, projetos);
   
   // OrdenaListaDiscente(&pInicioDiscentes);
   // PercorreListaDiscente(pInicioDiscentes);
   
   PercorreListaProjeto(pInicioProjetos);
   
   return 0;
   
}
