all: prog limpa

prog: main.o constroi.o
	gcc -g -Wall main.o constroi.o -o prog
	./prog

main.o: main.c
	gcc -c -g -Wall main.c
	
constroi.o: ./leitura/constroi.c
	gcc -c -g -Wall ./leitura/constroi.c
	
limpa: 
	rm *.o
