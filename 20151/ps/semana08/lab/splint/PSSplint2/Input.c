#include "Input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int count = 0;

char * Get_C(int /*@out@*/ **tamanho){
	
   char *c;
	c = calloc(50, sizeof(char));
	
   if (c != NULL) {
		
      scanf("%s", c);
      *tamanho = (int *) strlen(c);
		(void)getchar();
      
      return c;
	
   }

}

int Tem_Input(int maximo) {
	
   if (count < maximo) {

		count++;
		return 1;
	
   } else
      return 0;

}
