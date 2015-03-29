#include <stdio.h>
#include <stdlib.h>

#include "constroi.h"
#include "linear.h"
#include "percorre.h"

typedef enum {
   CONSTRUIR = 1,
   PERCORRE_MALHA = 2,
   PERCURSO_LINEAR = 3,
   FECHAR_PROGRAMA = 4} OpcaoMenu;

int main () {

   int OpcaoUsuario;
   
   struct lista_disc *pinicio;
   
   pinicio = NULL;
  
   while (1 == 1) {
   
      do {
      
         printf("%s", "\nMenu Principal:\n");
         printf("%s", "\n[1] Construir Malha");
         printf("%s", "\n[2] Percorrer Malha");
         printf("%s", "\n[3] Percurso Linear");
         printf("%s", "\n[4] Fechar Programa");
         printf("%s", "\n\n? ");
         
         scanf("%d", &OpcaoUsuario);
         getchar();
      
      } while(OpcaoUsuario < 1 || OpcaoUsuario > 4);
      
      switch (OpcaoUsuario) {
            
         case CONSTRUIR:
            ConstroiMalha (&pinicio);
            break;
      
         case PERCORRE_MALHA:
            PercorreMalha (pinicio);
            break;
      
         case PERCURSO_LINEAR:
            PercursoLinear (pinicio);
            break;
            
         case FECHAR_PROGRAMA:
            printf("%s","\nEncerrando programa...\n\n");
            exit(EXIT_SUCCESS);            
            
      }
   
   }
   
   return 0;
   
}
