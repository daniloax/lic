all: main execute prompt clean
	./main
	
main: main.o
	gcc -g -Wall main.o -o main
	
execute: execute.o
	gcc -g -Wall execute.o -o execute
	
prompt: prompt.o
	gcc -g -Wall prompt.o -o prompt

main.o: main.c
	gcc -c -g -Wall main.c
	
execute.o: execute.c
	gcc -c -g -Wall execute.c
	
prompt.o: prompt.c
	gcc -c -g -Wall prompt.c
	
clean: 
	rm *.o
