#include <stdio.h>
#include <stdlib.h>

typedef struct element {

	char name;
	float value;
	struct element *next;

} fifolifo;

void initialize(fifolifo **afl) {

	*afl = NULL;

}

int isEmpty(fifolifo *afl) {

	return (afl == NULL);

}

void insertFIFO(fifolifo **af, char name, float value) {

	fifolifo *f1, *f2;
	f1 = malloc (sizeof (fifolifo));
	f1->name = name;
	f1->value = value;
	f1->next = NULL;
	
	if (*af == NULL)
		*af = f1;
	
	else {
		
		f2 = *af;

		while (f2->next != NULL)
			f2 = f2->next;
		
		f2->next = f1;

	}

}

void insertLIFO(fifolifo **al, char name, float value) {

	fifolifo *l1;
	l1 = malloc (sizeof (fifolifo));
	l1->name = name;
	l1->value = value;
	l1->next = *al;
	*al = l1;

}

void insertValue(fifolifo **afl, float f) {

	fifolifo *fl;
	fl = *afl;
	fl->value = f;
	printf("%c: %.2f\n", fl->name, fl->value);

}

char removeElement(fifolifo **afl) {
	
	fifolifo *f1;
	char c;
	f1 = *afl;
	*afl = f1->next;
	c = f1->name;
	free (f1);
	return c;

}

char displayElement(fifolifo *afl) {

	return afl->name;

}

float displayValue(fifolifo *afl) {

	return afl->value;

}

void displayElements(fifolifo **afl) {

	fifolifo *aux;
	char c;
	
	if (isEmpty(*afl))
		printf("empty FIFO\n");
		
	else {

		initialize(&aux);
		
		while (!isEmpty(*afl)) {
		
			printf("ELEMENT: %c\n", displayElement(*afl));
			insertFIFO(&aux, removeElement(afl), 0.0);
			
		}
		
		while (!isEmpty(aux))
			insertFIFO(afl, removeElement(&aux), 0.0);

	}

}

void update(fifolifo **afl, char c, float f) {
	
	fifolifo *aux;
	char d;

	if (isEmpty(*afl))
		printf("empty FIFO\n");
		
	else {
	
		initialize(&aux);
		
		while (!isEmpty(*afl))
			insertFIFO(&aux, removeElement(afl), 0.0);
		
		while (!isEmpty(aux)) {
			
			d = removeElement(&aux);
			insertLIFO(afl, d, 0.0);
			
			if (d == c) {
			
				insertValue(afl, f);
				printf("ELEMENT = %c\tVALUE = %.2f\n", displayElement(*afl), displayValue(*afl));
				
			}

		}

	}

}

float searchValue(fifolifo **afl, char c) {

	fifolifo *aux;
	char d;
	float f;

	if (isEmpty(*afl))
		printf("empty FIFO\n");
		
	else {
	
		initialize(&aux);
		
		while (!isEmpty(*afl))
			insertFIFO(&aux, removeElement(afl), 0.0);
		
		while (!isEmpty(aux)) {
			
			d = removeElement(&aux);
			insertLIFO(afl, d, 0.0);
			
			if (d == c)
				f = displayValue(*afl);

		}

	}
	
	return f;

}
	
void calculate(fifolifo **al1, fifolifo **al2, fifolifo **al3) {

	char a, b, op;
	float x, y;

	if (isEmpty(*al1))
		insertLIFO(al1, ' ', 0.0);

	else {
		
		op = removeElement(al2);
		
		a = removeElement(al1);
		x = searchValue(al3, a);
		
		b = removeElement(al1);
		y = searchValue(al3, b);
		
		switch (op) {

			case '+' : insertFIFO(al1, ' ', y + x); break;
			case '-' : insertFIFO(al1, ' ', y - x); break;
			case '*' : insertFIFO(al1, ' ', y * x); break;
			case '/' : insertFIFO(al1, ' ', y / x); break;

		}

	}

}

void evaluate(fifolifo **al1, fifolifo **al2) {

	FILE *f;
	fifolifo *list, *l1;
	char c, d, fileName[10];
	int i, j;
	float k;

	initialize(&list);
	
	do {
	
		printf("FILENAME: ");
		scanf("%[^\n]s", fileName);
		getchar();
		
		f = fopen(fileName, "r");
		
		if (!f)
			printf("'%s' not exist\n", fileName);
	
	} while (!f);
	
	while (((c = getc(f)) != EOF) && (c != '\n')) {
	
		printf("%c", c);
		
		if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
			insertFIFO(&list, c, 0.0);
			
	}

	printf("\n");

	while (!feof(f)) {
	
		if (fscanf(f, "%d", &i)) {
			
			if (c == '.') {
				
				k = i * 0.1;
				
				if (j < 0) {
					
					k -= j;
					k *= -1.0;
				
				} else
					k += j;
					
				update(&list, d, k);
				
			} else
				j = i;
		
		} else {

			fscanf(f, "%c", &c);
			
			if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
				d = c;
			
		}
		
	}
	
	printf("\n");
	rewind(f);

	while (((c = getc(f)) != EOF) && (c != '\n')) {

		if (c != ' ')
			if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
				insertFIFO(al1, c, 0.0);
		
			else
				if (c == ')')
					calculate(al1, al2, &list);
		
				else
					if (c != '(')
						insertLIFO (al2, c, 0.0);

	}
	
	fclose (f);

}

int main() {

	fifolifo *lifo1, *lifo2;
	
	initialize(&lifo1);
	initialize(&lifo2);
	evaluate(&lifo1, &lifo2);
	printf("%d\n", removeElement(&lifo1) - '0');
	system("pause");
	
	return 0;

}
