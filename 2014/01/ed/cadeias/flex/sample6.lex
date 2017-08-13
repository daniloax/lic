%{
#include <stdio.h>
%}
%%
[a-zA-Z][a-zA-Z0-9]*\n		{printf("Identificador. Mais um token?\n");}
("+"|"-")?[0-9]+(".")?[0-9]*\n	{printf("Numero. Mais um token?\n");}
.*\n				{printf("Token não reconhecido!\n");}
%%
int yywrap() {
 return 1;
}

/* programa principal */
main() {
  printf("Informe um token:\n");
  yylex(); /* scanner gerado por Flex */
}
