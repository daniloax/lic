all: Main.o Input.o Listas.o
	gcc -g Main.o Input.o Listas.o -o prog

Main.o: Main.c Input.h Listas.h
	gcc -c -g Main.c

Input.o: Input.c Input.h
	gcc -c -g Input.c

Listas.o: Listas.c Listas.h
	gcc -c -g Listas.c

