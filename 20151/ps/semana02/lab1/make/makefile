all: malha limpa

malha: main.o constroi.o linear.o percorre.o
	gcc -g -Wall main.o constroi.o linear.o percorre.o -o malha

main.o: main.c constroi.c constroi.h linear.c linear.h percorre.c percorre.h listas.h
	gcc -c -g -Wall main.c
	
constroi.o: constroi.c constroi.h listas.h
	gcc -c -g -Wall constroi.c
	
linear.o: linear.c linear.h listas.h
	gcc -c -g -Wall linear.c
	
percorre.o: percorre.c percorre.h listas.h
	gcc -c -g -Wall percorre.c
	
limpa: 
	rm *.o
