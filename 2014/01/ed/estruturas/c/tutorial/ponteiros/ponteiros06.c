#include <stdio.h>
#include <stdlib.h>

main () {
  int x, *p1;    
  char c, *p2;

  x = 5;
  c = 'a'; 
  p1 = &x;
  printf(" %d\n", *p1);
  p2 = &c;
  printf(" %c\n", *p2);

  p1 = NULL;
  printf(" %d\n", *p1);

  p1 = &x;
  *p1 = *p2;
  
  p1 = p2;    
  printf(" %c\n", *p1); 

  system ("pause");     
}
