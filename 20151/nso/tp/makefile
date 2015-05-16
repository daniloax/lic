#ARCH = i386
#ARCH = amd64

all: main prompt cadastra executa pai filho limpa
	./main prompt
	
#	./main cadastra filho argumento
	
#	test: main.c main_test.c
#	gcc -I ./CUnit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test
#	./test

main: main.o semaforo.o
	gcc -g -Wall main.o semaforo.o -o main
	
prompt: prompt.o semaforo.o
	gcc -g -Wall prompt.o semaforo.o -o prompt
	
cadastra: cadastra.o semaforo.o
	gcc -g -Wall cadastra.o semaforo.o -o cadastra
	
executa: executa.o semaforo.o
	gcc -g -Wall executa.o semaforo.o -o executa
	
pai: pai.o semaforo.o
	gcc -g -Wall pai.o semaforo.o -o pai	

filho: filho.o semaforo.o
	gcc -g -Wall filho.o semaforo.o -o filho

main.o: main.c
	gcc -c -g -Wall main.c
	
prompt.o: prompt.c
	gcc -c -g -Wall prompt.c

cadastra.o: cadastra.c
	gcc -c -Wall cadastra.c
	
executa.o: executa.c
	gcc -c -Wall executa.c
	
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
#	ipcrm -S 0x068f60b1
#	rm *.gcda *.gcno *gcov
