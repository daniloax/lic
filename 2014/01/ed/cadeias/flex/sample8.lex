%{
#include <stdio.h>
int	nOcorrencias=0;
%}
%%
alo		{nOcorrencias++;}
.		{;}
%%
int yywrap() {
 return 1;
}

/* programa principal */
main(argc, argv)
int argc;
char **argv;
{
	extern FILE *yyin;
	extern FILE *yyout;

	++argv; --argc; 	    /* abre arquivo de entrada se houver */
	if(argc > 0)
		yyin = fopen(argv[0],"rt");
	else
		yyin = stdin;    /* cria arquivo de saida se especificado */
	if(argc > 1)
		yyout = fopen(argv[1],"wt");
	else
		yyout = stdout;

	yylex (); /* scanner gerado por Flex */

	printf("\n Achei %d ocorrencia(s) do padrao especificado!\n",nOcorrencias);

	fclose(yyin);
	fclose(yyout);
}
