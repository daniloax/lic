ARCH = i386
#ARCH = amd64

all: prog limpa

prog: main.o mod_impl_discente.o mod_impl_projeto.o
	gcc -g -Wall main.o mod_impl_discente.o mod_impl_projeto.o -o prog
	./prog
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c main.h
	gcc -c -g -Wall main.c
	
mod_impl_discente.o: mod_impl_discente.c mod_def_discente.h 
	gcc -c -g -Wall mod_impl_discente.c
	
mod_impl_projeto.o: mod_impl_projeto.c mod_def_projeto.h
	gcc -c -g -Wall mod_impl_projeto.c
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
