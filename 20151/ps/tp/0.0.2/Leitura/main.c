#include <stdio.h>
#include <stdlib.h>

#include "main.h"

#include "mod_def_atividade.h"
#include "mod_def_lista.h"
#include "mod_def_pessoa.h"
#include "mod_def_discente.h"
#include "mod_def_projeto.h"

int main() {
	
	char discentesMestrado[] = "../Arquivos/discentes_mestrado.txt";
	char discentesDoutorado[] = "../Arquivos/discentes_doutorado.txt";
   char projetos[] = "../Arquivos/projetos.txt";
   
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
