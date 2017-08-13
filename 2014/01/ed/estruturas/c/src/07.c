#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *p1, *p2;
    
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    
    *p1 = 10;
    *p2 = 20;
    
    printf("\n&p1: %p\n", &p1);
    printf("&p2: %p\n\n", &p2);

    printf("p1: %p\n", p1);
    printf("p2: %p\n\n", p2);
    
    printf("&*p1: %p\n", &*p1);
    printf("&*p2: %p\n\n", &*p2);     

    printf("*p1: %d\n", *p1);
    printf("*p2: %d\n\n", *p2);
    
    p2 = p1;

    printf("*p1: %d\n", *p1);
    printf("*p2: %d\n\n", *p2);
    
    system("pause");
    
    return 0;
    
}
