all: malha

malha: main.o listas.o
	gcc main.o listas.o -o malha

main.o: main.c main.h
	gcc -c main.c

listas.o: constroi.c constroi.h linear.c linear.h percorre.c percorre.h
	gcc -c auxiliar.c

limpa: 
	rm *.o
