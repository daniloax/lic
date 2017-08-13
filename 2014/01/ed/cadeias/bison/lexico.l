/* Analisador Lexico */
%{
  #include "sintatico.tab.h"
%}
%%
[ \t]+			{;}
.|\n			{return yytext[0];}
%%
int yywrap() {
  return 1;
}

