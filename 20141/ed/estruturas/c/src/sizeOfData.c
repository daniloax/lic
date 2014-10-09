#include <stdio.h>
#include <stdlib.h>

typedef struct {
  
  int dia, mes, ano; 

} data;

int main (void) {
  
  printf ("sizeof (data) = %d\n", sizeof (data));
  printf ("sizeof (data *) = %d\n", sizeof (data *));
  
  system("pause");
  
  return 0;

}
