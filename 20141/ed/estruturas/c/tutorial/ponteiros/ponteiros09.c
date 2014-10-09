main () {

typedef struct reg {
  int x;
  float y;
} registro;

  registro *p1, *p2;

  p1 = malloc (sizeof (registro));
  p2 = malloc (sizeof (registro));    
  (*p1).x = 3;    // sintaxe alternativa:  p1->x = 3;
  (*p1).y = 5.3;  // sintaxe alternativa:  p1->y = 5.3;
  printf("%d \n", (*p1).x);
  printf("%f \n", (*p1).y);
  
  *p2 = *p1;
  printf("%d \n", (*p2).x);
  printf("%f \n", (*p2).y);

  system ("pause");     
}
  
