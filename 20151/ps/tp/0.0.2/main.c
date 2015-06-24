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
   
   setListaDiscente(&pInicioDiscentes, discentesMestrado);
   setListaDiscente(&pInicioDiscentes, discentesDoutorado);
   setListaProjeto(&pInicioProjetos, projetos);
   
   // OrdenaListaDiscente(&pInicioDiscentes);
   // PercorreListaDiscente(pInicioDiscentes);
   
   getListaProjeto(pInicioProjetos);
   
   return 0;
   
}
