%{
#include <stdio.h>
%}
%%
[ab]*\n     {printf("Palavra do alfabeto {a,b}. Mais um token?\n");}
(GU|BA|CA)*\n  {printf("Palavra do alfabeto {GU,BA,CA}. Mais um token?\n");}
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
