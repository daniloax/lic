#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x, y;
    int *p1, *p2, *p3;

    x = 5;
    y = 7;

    p1 = &x;
    p2 = &y;
    
    printf("Endereco da variavel x: %p\n", &x);
    printf("Endereco da variavel y: %p\n\n", &y);

    printf("Conteudo da variavel x: %d\n", x);
    printf("Conteudo da variavel y: %d\n\n", y);
    
    printf("Endereco apontado pelo ponteiro p1: %p\n", p1);
    printf("Endereco apontado pelo ponteiro p2: %p\n\n", p2);
    
    p3 = p1;

    printf("Conteudo do ponteiro p1: %d\n", *p1);
    printf("Conteudo do ponteiro p2: %d\n", *p2);
    printf("Conteudo do ponteiro p3: %d\n\n", *p3);
    
    p2 = p1;
    
    printf("Endereco do ponteiro p1: %p\n", &p1);
    printf("Endereco do ponteiro p2: %p\n", &p2);
    printf("Endereco do ponteiro p3: %p\n\n", &p3);
    
    printf("Endereco apontado pelo ponteiro p1: %p\n", p1);
    printf("Endereco apontado pelo ponteiro p2: %p\n", p2);
    printf("Endereco apontado pelo ponteiro p3: %p\n\n", p3);
        
    system("pause");
    
    return 0;
    
}
