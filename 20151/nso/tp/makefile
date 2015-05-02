#ARCH = i386
#ARCH = amd64

all: main limpa

main: main.o prompt.o cadastra executa
	gcc -g -Wall main.o prompt.o -o main
	./main
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
prompt.o: prompt.c
	gcc -c -g -Wall prompt.c
	
cadastra: cadastra.c
	gcc -g -Wall cadastra.c -o cadastra
	
executa: executa.c
	gcc -g -Wall executa.c -o executa
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
