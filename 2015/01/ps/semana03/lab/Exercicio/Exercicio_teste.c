#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../CUnit/CUnit.h"
#include "../CUnit/Basic.h" 
#include "Exercicio.c"

/*
 * Função que adiciona ao registro do CUnit os testes para todas as funções 
 * presentes no arquivo testes.c
 */
void adicionar_testes_smo_datas(void);

/* Abaixo estão as funções que efetuam os testes para a função ChecaData */
void teste_DT_VerificaData_AnoMaiorQue9999(void);
void teste_DT_VerificaData_AnoMenorQue1900(void);
void teste_DT_VerificaData_CaracterInvalido(void);
void teste_DT_VerificaData_DiaMaiorQue31(void);
void teste_DT_VerificaData_DiaMenorQue1(void);
void teste_DT_VerificaData_FormatoAnoMesDia(void);
void teste_DT_VerificaData_FormatoDiaMesAno(void);
void teste_DT_VerificaData_MesMaiorQue12(void);
void teste_DT_VerificaData_MesMenorQue1(void);
void teste_DT_VerificaData_SeparadorInvalido(void);
void teste_DT_VerificaData_UmDigitoDia(void);

/* Abaixo estão as funções que efetuam os testes para a função Nome */
void teste_DT_SeparaNome_ComparaPrimeiroNome(void);
void teste_DT_SeparaNome_ComparaSegundoNome(void);
void teste_DT_SeparaNome_SeparadorInvalido(void);
void teste_DT_SeparaNome_EspacoInicial(void);
void teste_DT_SeparaNome_CaracterInvalido(void);
void teste_DT_SeparaNome_TamanhoPrimeiroNome(void);
void teste_DT_SeparaNome_TamanhoSegundoNome(void);


/* Teste ano maior que 9999 */
void teste_DT_VerificaData_AnoMaiorQue9999(void) {
   
   char data[] = "10/10/20100";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
}

/* Teste ano menor que 1900 */
void teste_DT_VerificaData_AnoMenorQue1900(void) {
   
   char data[] = "31/12/1899";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );   

}

/* Teste caracter inválido campos dia e mes */
void teste_DT_VerificaData_CaracterInvalido(void) {
   
   char data[] = "Er/ro/2001";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
   
}

/* Teste dia maior que 31 */
void teste_DT_VerificaData_DiaMaiorQue31(void) {
   
   char data[] = "32/10/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

/* Teste dia menor que 1 */
void teste_DT_VerificaData_DiaMenorQue1(void) {
   
   char data[] = "00/10/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

/* Teste formato AAAA/MM/DD */
void teste_DT_VerificaData_FormatoAnoMesDia(void) {
   
   char data[] = "1998/01/09";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

/* Teste formato DD/MM/AAAA */
void teste_DT_VerificaData_FormatoDiaMesAno(void) {
   
   char data[] = "09/01/1998";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE(resultado);

}

/* Teste mes maior que 12 */
void teste_DT_VerificaData_MesMaiorQue12(void) {
   
   char data[] = "31/13/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

/* Teste mes menor que 12 */
void teste_DT_VerificaData_MesMenorQue1(void) {

   char data[] = "01/00/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
   
}

/* Teste separador inválido */
void teste_DT_VerificaData_SeparadorInvalido(void) {
   
   char data[] = "10p05/1906";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
}

/* Teste um digito dia */
void teste_DT_VerificaData_UmDigitoDia(void) {
   
   char data[] = "1/01/1900";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

/* Teste compara primeira palavra */
void teste_DT_SeparaNome_ComparaPrimeiroNome(void) {
	
	char nome[] = "Carlos Henrique";
	char *primeiro, *segundo;
	int resultado;

	Nome(nome, &primeiro, &segundo);
	resultado = strcmp("Carlos", primeiro);

	CU_ASSERT_TRUE(resultado == 0);
	
}

/* Teste compara segunda palavra */
void teste_DT_SeparaNome_ComparaSegundoNome(void) {
	
	char nome[] = "Rodrigo Freitas Santos";
	char *primeiro, *segundo;
	int resultado;

	Nome(nome, &primeiro, &segundo);
	resultado = strcmp("Freitas", segundo);

	CU_ASSERT_TRUE(resultado == 0);
	
}

/* Teste separador com dois espaços */
void teste_DT_SeparaNome_SeparadorComDoisEspacos(void) {
	
	char nome[] = "Carlos  Henrique";
	char *primeiro, *segundo;
	int resultado;

	Nome(nome, &primeiro, &segundo);
	resultado = strcmp("Carlos", primeiro);

	CU_ASSERT_TRUE(resultado == 0);
}

/* Teste espaço inicial */
void teste_DT_SeparaNome_EspacoInicial(void) {
	
	char nome[] = " Rodrigo Freitas Santos";
	char *primeiro, *segundo;
	int resultado;

	Nome(nome, &primeiro, &segundo);
	resultado = strcmp("Rodrigo ", primeiro);

	CU_ASSERT_TRUE(resultado == 0);
	
}

/* Teste caracter inválido */
void teste_DT_SeparaNome_CaracterInvalido(void) {
	
	char nome[] = "R0dr1g0 Fr31t4s S4nt0s";
	char *primeiro, *segundo;
	int resultado;

	Nome(nome, &primeiro, &segundo);
	resultado = strcmp("R0dr1g0", primeiro);

	CU_ASSERT_TRUE(resultado == 0);
	
}

/* Teste tamanho primeiro nome */
void teste_DT_SeparaNome_TamanhoPrimeiroNome(void) {
	
	char nome[] = "Rodrigo Freitas Santos";
	char *primeiro, *segundo;

	Nome(nome, &primeiro, &segundo);
	
	CU_ASSERT_TRUE(strlen("Rodrigo") == strlen(primeiro));
	
}

/* Teste tamanho segundo nome */
void teste_DT_SeparaNome_TamanhoSegundoNome(void) {
	
	char nome[] = "Rodrigo Freitas Santos";
	char *primeiro, *segundo;

	Nome(nome, &primeiro, &segundo);
	
	CU_ASSERT_TRUE(strlen("Freitas") == strlen(segundo));
	
}

void adicionar_testes_smo_datas(void) {
	
   CU_pSuite suite;
	
	/* Cria uma suite que conterá todos os testes */
	suite = CU_add_suite("Testes da smo_datas",NULL,NULL);
   
   /* Adiciona os testes para a função DT_ChecaData */
   
   CU_ADD_TEST(suite, teste_DT_VerificaData_AnoMaiorQue9999);
   CU_ADD_TEST(suite, teste_DT_VerificaData_AnoMenorQue1900);
   CU_ADD_TEST(suite, teste_DT_VerificaData_CaracterInvalido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_DiaMaiorQue31);
   CU_ADD_TEST(suite, teste_DT_VerificaData_DiaMenorQue1);
   CU_ADD_TEST(suite, teste_DT_VerificaData_FormatoAnoMesDia);
   CU_ADD_TEST(suite, teste_DT_VerificaData_FormatoDiaMesAno);
   CU_ADD_TEST(suite, teste_DT_VerificaData_MesMenorQue1);
   CU_ADD_TEST(suite, teste_DT_VerificaData_MesMaiorQue12);
   CU_ADD_TEST(suite, teste_DT_VerificaData_SeparadorInvalido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_UmDigitoDia);
   
   /* Adiciona os testes para a função DT_Nome */
   
   CU_ADD_TEST(suite, teste_DT_SeparaNome_ComparaPrimeiroNome);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_ComparaSegundoNome);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_SeparadorComDoisEspacos);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_EspacoInicial);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_CaracterInvalido);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_TamanhoPrimeiroNome);
   CU_ADD_TEST(suite, teste_DT_SeparaNome_TamanhoSegundoNome);

}

int main(void) {
	
	/* Inicializa o registro de suites e testes do CUnit */	
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();
    
   /* Adiciona os testes ao registro */ 	
   adicionar_testes_smo_datas();
	
	/* Muda o modo do CUnit para o modo VERBOSE
	 * O modo VERBOSE mostra algumas informacoes a
	 * mais na hora da execucao */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	
	/* Roda os testes e mostra na tela os resultados */
	CU_basic_run_tests();
	
	/* Limpa o registro */
	CU_cleanup_registry();
	
	return CU_get_error();
	
}
