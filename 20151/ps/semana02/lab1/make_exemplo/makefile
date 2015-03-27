all: programa

programa: main.o auxiliar.o
	gcc main.o auxiliar.o -o programa

main.o: main.c auxiliar.c auxiliar.h
	gcc -c main.c

auxiliar.o: auxiliar.c auxiliar.h
	gcc -c auxiliar.c

limpa: 
	rm *.o
