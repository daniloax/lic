#ARCH = i386
#ARCH = amd64

all: main prompt cadastra executa fibonacci hanoi limpa
	./main
	
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
	
fibonacci: fibonacci.o semaforo.o
	gcc -g -Wall fibonacci.o semaforo.o -o fibonacci	

hanoi: hanoi.o semaforo.o
	gcc -g -Wall hanoi.o semaforo.o -o hanoi

main.o: main.c
	gcc -c -g -Wall main.c
	
prompt.o: prompt.c
	gcc -c -g -Wall prompt.c

cadastra.o: cadastra.c
	gcc -c -Wall cadastra.c
	
executa.o: executa.c
	gcc -c -Wall executa.c
	
fibonacci.o: fibonacci.c
	gcc -c -Wall fibonacci.c

hanoi.o: hanoi.c
	gcc -c -Wall hanoi.c
	
semaforo.o: semaforo.c
	gcc -c -Wall semaforo.c
	
#	gcov: main.c main_test.c
#	gcc -Wall -ftest-coverage -fprofile-args -I ./Cunit -L ./CUnit main_test.c -lcunit_$(ARCH) -o test_gcov
#	./test_gcov
	
limpa: 
	rm *.o
#	ipcrm -S 0x068f60b1
#	rm *.gcda *.gcno *gcov
