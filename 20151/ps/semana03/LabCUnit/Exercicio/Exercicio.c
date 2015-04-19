#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Verifica datas */
 
int ChecaData(char *data) {
	
   char dia[3], mes[3], ano[5];
	int anoInt, mesInt, diaInt, tamanho, i;
   
	tamanho = strlen(data);
	
   if (tamanho != 10)
      return 0;
      
	if (data[2] != '/' || data[5] != '/')
      return 0;
      
	for (i = 0; i < 10; i++) {
		
      if (i != 2 && i != 5) {
			
         if (data[i] != '0' && data[i] != '1' && data[i] != '2' && data[i] != '3' && data[i] != '4' && data[i] != '5' && data[i] != '6' && data[i] != '7' && data[i] != '8' && data[i] != '9') {
				
            return 0;
			
         }
		
      }
		
      if (i < 4) {
			
         ano[i] = data[i+6];
			
         if (i < 2) {
				
            dia[i] = data[i];
				mes[i] = data[i+3];
			
         }
		
      }
	
   }
	
   ano[4] = '\0';
	dia[2] = '\0';
	mes[2] = '\0';
	
   anoInt = atoi(ano);
	diaInt = atoi(dia);
	mesInt = atoi(mes);
	
   if (anoInt < 1900)
      return 0;
	
   if (diaInt > 31)
      return 0;
	
   if (mesInt > 12)
      return 0;
      
   return 1;
      
}

/* Separa palavras */

void Nome(char *nome, char **primeiro, char **segundo) {
   
   int i, flag, tamanho, tamanho1, tamanho2;
   
   tamanho = strlen ( nome );
   tamanho1 = 0; 
   tamanho2 = 0;
   flag = 1;
	
	for (i = 0; i < tamanho; i++) {
      
      if (flag == 1)
         tamanho1++;
		
      else if (flag == 0)
         tamanho2++;
		
      if (nome[i] == ' ')
         flag--;

	}
	
   (*primeiro) = calloc(tamanho1, sizeof(char));
	(*segundo) = calloc(tamanho2, sizeof(char));
	
   flag = 1;
	
   for (i = 0; i < tamanho1; i++)
		(*primeiro)[i] = nome[i];

	(*primeiro)[i] = '\0';
	
   for (i = 0; i< tamanho2; i++)
		(*segundo)[i] = nome[i + tamanho1];
      
	(*segundo)[i] = '\0';
   
}
