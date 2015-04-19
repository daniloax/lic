all: Exercicio.c Exercicio_teste.c
	gcc -I ../CUnit -L ../CUnit Exercicio_teste.c -lcunit -o teste
	./teste
	
gcov: Exercicio.c Exercicio_teste.c
	gcc -Wall -ftest-coverage -fprofile-args -I ../Cunit -L ../CUnit Exercicio_teste.c -lcunit -o teste_gcov
	./teste_gcov
	
limpa: rm *.gcda *.gcno *gcov
