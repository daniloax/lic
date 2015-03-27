all: malha

malha: main.o
	gcc main.o listas.o -o malha

main.o: main.c constroi.c constroi.h linear.c linear.h percorre.c percorre.h listas.h
	gcc -c main.c

limpa: 
	rm *.o
