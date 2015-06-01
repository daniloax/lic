#include <stdio.h>
#include <stdlib.h>

typedef struct element {

	char data;
	struct element *next;

} fifolifo;

void initialize(fifolifo **e) {

	*e = NULL;

}

int isEmpty(fifolifo *e) {

	return (e == NULL);

}

void insertFIFO(fifolifo **ef, char newdata) {

	fifolifo *f1, *f2;
	f1 = malloc (sizeof (fifolifo));
	f1->data = newdata;
	f1->next = NULL;
	
	if (*ef == NULL)
		*ef = f1;
	
	else {
		
		f2 = *ef;

		while (f2->next != NULL)
			f2 = f2->next;
		
		f2->next = f1;

	}

}

void insertLIFO(fifolifo **ep, char newdata) {

	fifolifo *p1;
	p1 = malloc (sizeof (fifolifo));
	p1->data = newdata;
	p1->next = *ep;
	*ep = p1;

}

char removeElement(fifolifo **e) {
	
	fifolifo *f1;
	char c;
	f1 = *e;
	*e = f1->next;
	c = f1->data;
	free (f1);
	return c;

}

char displayElement(fifolifo *e) {

	return e->data;

}

void displayElements(fifolifo **e) {

	fifolifo *aux;
	char c;
	
	if (isEmpty(*e))
		printf("empty FIFO");
		
	else {

		initialize(&aux);
		
		while (!isEmpty(*e)) {
		
			printf("ELEMENT: %c\n", displayElement(*e));
			insertFIFO(&aux, removeElement(e));
			
		}
		
		while (!isEmpty(aux))
			insertFIFO(e, removeElement(&aux));

	}

}

int main() {

	FILE *f;
	char c, fileName[10];
	fifolifo *fifo, *lifo;
	
	initialize(&fifo);
	initialize(&lifo);
	
	do {
	
		printf("FILENAME: ");
		scanf("%[^\n]s", fileName);
		getchar();
		
		f = fopen(fileName, "r");
		
		if (!f)
			printf("'%s' not exist\n", fileName);
	
	} while (!f);
	
	while (((c = getc(f)) != EOF) && (c != '\n'))
		insertFIFO(&fifo, c);
		
	fclose(f);
	displayElements(&fifo);
	system("pause");
	return 0;

}
