all: build

build: main.o mod_calculo.o mod_apresentacao.o
	gcc main.o mod_calculo.o mod_apresentacao.o -o exe

main.o: main.c
	gcc -c main.c

mod_apresentacao.o: interface_apresentacao.h mod_apresentacao.c
	gcc -c mod_apresentacao.c

mod_calculo.o: mod_calculo.c interface_calculo.h
	gcc -c  mod_calculo.c

clean: 
	rm *.o
