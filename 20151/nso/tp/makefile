#ARCH = i386
#ARCH = amd64

all: main limpa

main: main.o prompt cadastra executa filho
	gcc -g -Wall main.o -o main
	./main cadastra filho argumento
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
prompt: prompt.c
	gcc -g -Wall prompt.c -o prompt
	
cadastra: cadastra.c
	gcc -g -Wall cadastra.c -o cadastra
	
executa: executa.c
	gcc -g -Wall executa.c -o executa
	
filho: filho.c
	gcc -g -Wall filho.c -o filho
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o 
#	rm *.gcda *.gcno *gcov
