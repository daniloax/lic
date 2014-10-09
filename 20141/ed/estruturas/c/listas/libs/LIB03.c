#include <stdio.h>

typedef struct node {

	char data;
	struct node *node_a;
   struct node *node_b;

} nodetree;

void insert(nodetree **a) {
   
   
}

void initialize(nodetree **a) {

	*a = NULL;

}

void display(nodetree *a) {
   
   
   
}

int main () {   

   FILE *f;
	char c, fileName[10];
	nodetree *tree;
	
	initialize(&tree);
	
	do {
	
		printf("FILENAME: ");
		scanf("%[^\n]s", fileName);
		getchar();
		
		f = fopen(fileName, "r");
		
		if (!f)
			printf("'%s' not exist\n", fileName);
	
	} while (!f);
   
   while (((c = getc(f)) != EOF) && (c != '\n'))
		insert(&tree, c);
		
	fclose(f);
	display(tree);

}
