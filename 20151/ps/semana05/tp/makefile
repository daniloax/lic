ARCH = i386
#ARCH = amd64

all: prog limpa

prog: main.o constroi.o
	gcc -g -Wall main.o constroi.o -o prog
	./prog
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
constroi.o: ./leitura/constroi.c
	gcc -c -g -Wall ./leitura/constroi.c
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
