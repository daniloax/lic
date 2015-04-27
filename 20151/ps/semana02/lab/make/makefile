all: malha limpa

malha: main.o constroi.o linear.o percorre.o
	gcc -g -Wall main.o constroi.o linear.o percorre.o -o malha

main.o: main.c
	gcc -c -g -Wall main.c
	
constroi.o: constroi.c
	gcc -c -g -Wall constroi.c
	
linear.o: linear.c
	gcc -c -g -Wall linear.c
	
percorre.o: percorre.c
	gcc -c -g -Wall percorre.c
	
limpa: 
	rm *.o
