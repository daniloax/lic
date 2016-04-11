all: main execute prompt clean
	./main
	
main: main.o
	gcc -g -Wall main.o -o main
	
execute: execute.o
	gcc -g -Wall execute.o -o execute
	
prompt: prompt.o keypad.o
	gcc -g -Wall prompt.o keypad.o -o prompt

main.o: main.c
	gcc -c -g -Wall main.c
	
execute.o: execute.c
	gcc -c -g -Wall execute.c
	
prompt.o: prompt.c
	gcc -c -g -Wall prompt.c
	
keypad.o: keypad.c
	gcc -c -g -Wall keypad.c
	
clean: 
	rm *.o
