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

void teste_DT_VerificaData_FormatoValido(void);
void teste_DT_VerificaData_FormatoInvalido(void);
void teste_DT_VerificaData_DiaMenorQue1(void);
void teste_DT_VerificaData_DiaMaiorQue31(void);
void teste_DT_VerificaData_MesMenorQue1(void);
void teste_DT_VerificaData_MesMaiorQue12(void);
void teste_DT_VerificaData_CaracterInvalido(void);
void teste_DT_VerificaData_TamanhoAnoInvalido(void);
void teste_DT_VerificaData_SeparadorInvalido(void);

void teste_DT_VerificaData_FormatoValido(void) {
   
   char data[] = "09/01/1998";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( resultado );

}

void teste_DT_VerificaData_FormatoInvalido(void) {
   
   char data[] = "1998/01/09";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

void teste_DT_VerificaData_DiaMenorQue1(void) {
   
   char data[] = "00/10/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

void teste_DT_VerificaData_DiaMaiorQue31(void) {
   
   char data[] = "32/10/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

void teste_DT_VerificaData_MesMenorQue1(void) {

   char data[] = "01/00/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
   
}

void teste_DT_VerificaData_MesMesMaiorQue12(void) {
   
   char data[] = "31/13/1960";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}

void teste_DT_VerificaData_CaracterInvalido(void) {
   
   char data[] = "Er/ro/2001";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
   
}
void teste_DT_VerificaData_TamanhoAnoInvalido(void) {
   
   char data[] = "10/10/20100";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );

}
void teste_DT_VerificaData_SeparadorInvalido(void) {
   
   char data[] = "10p05/1906";
   int resultado;
	
   resultado = ChecaData(data);
	CU_ASSERT_TRUE( !resultado );
}

void adicionar_testes_smo_datas(void) {
	
   CU_pSuite suite;
	
	/* Cria uma suite que conterá todos os testes */
	suite = CU_add_suite("Testes da smo_datas",NULL,NULL);
   
   /* Adiciona os testes para a função DT_ChecaData */
	CU_ADD_TEST(suite, teste_DT_VerificaData_FormatoValido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_FormatoInvalido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_DiaMenorQue1);
   CU_ADD_TEST(suite, teste_DT_VerificaData_DiaMaiorQue31);
   CU_ADD_TEST(suite, teste_DT_VerificaData_MesMenorQue1);
   CU_ADD_TEST(suite, teste_DT_VerificaData_MesMesMaiorQue12);
   CU_ADD_TEST(suite, teste_DT_VerificaData_CaracterInvalido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_TamanhoAnoInvalido);
   CU_ADD_TEST(suite, teste_DT_VerificaData_SeparadorInvalido);
   

}

int main(void) {
	/*Inicializa o registro de suítes e testes do CUnit*/	
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();
    
    /*Adiciona os testes ao registro*/ 	
   	adicionar_testes_smo_datas();
	/*Muda o modo do CUnit para o modo VERBOSE
	 O modo VERBOSE mostra algumas informacoes a
	 mais na hora da execucao*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	/*Roda os testes e mostra na tela os resultados*/
	CU_basic_run_tests();
	/*Limpa o registro*/
	CU_cleanup_registry();
	return CU_get_error();
}
