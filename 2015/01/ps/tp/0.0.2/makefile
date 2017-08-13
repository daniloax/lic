ARCH = i386
#ARCH = amd64
LEITURA = ./Leitura

all: prog limpa

prog: main.o mod_impl_discente.o mod_impl_projeto.o
	gcc -g -Wall main.o mod_impl_discente.o mod_impl_projeto.o -o prog
	./prog
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
leitura.o: discente.o projeto.o
	gcc -c -g -Wall discente.o projeto.o
	
mod_impl_discente.o: $(LEITURA)/mod_def_discente.h $(LEITURA)/mod_impl_discente.c
	gcc -c -g -Wall $(LEITURA)/mod_impl_discente.c
	
mod_impl_projeto.o: $(LEITURA)/mod_def_projeto.h $(LEITURA)/mod_impl_projeto.c
	gcc -c -g -Wall $(LEITURA)/mod_impl_projeto.c
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
