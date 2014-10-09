#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x, y;
    int *p1, *p2;
    
    x = 10;
    y = 01;
    
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    
    *p1 = x;
    *p2 = y;
    
    printf("*p1 = %d\n*p2 = %d\n", *p1, *p2);
    
    *p2 = *p1;
    
    printf("*p2 = %d\n\n", *p2);
    
    system("pause");
    
    return 0;

}
