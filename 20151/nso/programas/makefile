all: prog

prog: prog1
	./prog1

prog1: prog1.c pai filho
	gcc -g -Wall prog1.c -o prog1
	
pai: pai.c
	gcc -g -Wall pai.c -o pai
	
filho: filho.c
	gcc -g -Wall filho.c -o filho
	
limpa:
	rm *.o
