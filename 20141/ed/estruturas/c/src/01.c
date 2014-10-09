#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x, y;
    int *p1;
    x = 5;
    p1 = &x;
    y = *p1;
    
    printf("&x: %p\n", &x);
    printf("x: %d\n\n", x);

    printf("&y: %p\n", &y);
    printf("y: %d\n\n", y);
    
    printf("&p1: %p\n", &p1);
    printf("p1: %p\n", p1);
    printf("*p1: %d\n\n", *p1);
    
    system("pause");
    
    return 0;
    
}
