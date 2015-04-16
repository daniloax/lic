all: Exemplo.c Exemplo_teste.c
	gcc -I./CUnit -L./CUnit Exemplo_teste.c -lcunit -o teste
	./teste
	
gcov: Exemplo.c Exemplo_teste.c
	gcc -Wall -ftest-coverage -fprofile-args -I./Cunit -L./CUnit Exemplo_teste.c -lcunit -o teste_gcov
	./teste_gcov
	
limpa: rm *.gcda *.gcno *gcov