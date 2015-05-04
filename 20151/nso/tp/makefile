#ARCH = i386
#ARCH = amd64

all: main limpa

main: main.o prompt cadastra executa pai filho
	gcc -g -Wall main.o -o main
	./main cadastra filho argumento
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main.o: main.c
	gcc -c -g -Wall main.c
	
prompt: prompt.c
	gcc -g -Wall prompt.c -o prompt
	
cadastra: cadastra.o semaforo.o
	gcc -g -Wall cadastra.o semaforo.o -o cadastra
	
executa: executa.o
	gcc -g -Wall executa.o -o executa
	
cadastra.o: cadastra.c
	gcc -c -Wall cadastra.c
	
executa.o: executa.c
	gcc -c -Wall executa.c

pai: pai.o semaforo.o
	gcc -g -Wall pai.o semaforo.o -o pai	

filho: filho.o semaforo.o
	gcc -g -Wall filho.o semaforo.o -o filho
	
pai.o: pai.c
	gcc -c -Wall pai.c

filho.o: filho.c
	gcc -c -Wall filho.c
	
semaforo.o: semaforo.c
	gcc -c -Wall semaforo.c
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o
	ipcrm -S 0x068f60b1
#	rm *.gcda *.gcno *gcov
