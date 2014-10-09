#include <stdio.h>
#include <stdlib.h>

//-------------------------------------
void ponteiros1 () {

  int x;
  char c;
  int *p1;
  char *p2;
  p1 = NULL;  


  int  y;
  x = 5;
  y=7; 
  p1 = &x;
  printf(" %d\n", *p1);
  p2 = &y;
  printf(" %d\n", *p2);
}

//-------------------------------------
void ponteiros2 () {
  int x, y, *p1, *p2;
  x = 5;
  y=7;
  p1 = &x;
  printf(" %d\n", *p1);
  p2 = &y;
  printf(" %d\n", *p2);
   
  *p2=*p1;
  printf(" %d\n", *p2);
}

//-------------------------------------
void ponteiros3 () {
  int *p1, *p2;
   
  p1 =  malloc (sizeof(int));
  p2 =  malloc (sizeof(int));

  *p1 = 10;
  *p2 = 20;

  printf(" %d\n", *p1);
  printf(" %d\n", *p2);       
}    
     
//-------------------------------------
void ponteiros4 () {
  int *p1, *p2;
   
  p1 =  malloc (sizeof(int));
  p2 =  malloc (sizeof(int));

  *p1 = 10;
  *p2 = 20;

  printf(" %d\n", *p1);
  printf(" %d\n", *p2); 
  
  *p2 = *p1;
  printf(" %d\n", *p1);
  printf(" %d\n", *p2);       
}    
     
//-------------------------------------
void ponteiros5 () {
  int *p1, *p2;
   
  p1 =  malloc (sizeof(int));
  p2 =  malloc (sizeof(int));

  *p1 = 10;
  *p2 = 20;

  printf(" %d\n", *p1);
  printf(" %d\n", *p2); 
  
  p2 = p1;
  printf(" %d\n", *p1);
  printf(" %d\n", *p2);       
}    
     
//-------------------------------------
void ponteiros6 () {
  int *p1, *p2;
   
  p1 =  malloc (sizeof(int));
  p2 =  malloc (sizeof(int));

  *p1 = 10;
  *p2 = 20;

  printf(" %d\n", *p1);
  printf(" %d\n", *p2); 
  
  free (p2);
  p2 = p1;
  printf(" %d\n", *p1);
  printf(" %d\n", *p2);  
}

//-------------------------------------
void ponteiros7 () {
  int *p1;
  float *p2;
  void *p3;
  
  p1 = malloc (sizeof (int));
  *p1 = 5;
  p3 = p1;
  p2 = malloc (sizeof (float));
  *p2 = 6.2;
  p3 = p2;
}

//-------------------------------------
void ponteiros8 () {

typedef struct reg {
  int x;
  float y;
} registro;

  registro *p1, *p2;

  p1 = malloc (sizeof (registro));
  p2 = malloc (sizeof (registro));    
  (*p1).x = 3;
  (*p1).y = 5.3;
  printf("%d \n", (*p1).x);
  printf("%f \n", (*p1).y);
  
  *p2 = *p1;
  printf("%d \n", (*p2).x);
  printf("%f \n", (*p2).y);
}

//-------------------------------------
void ponteiros9 () {

typedef struct elemento {
  char x;
  struct elemento *prox;
} lista;

  lista *pinicio, *p1;

  pinicio = NULL;

  p1 = malloc (sizeof (struct elemento));
  p1->x = 'x';   
  p1->prox = pinicio;
  pinicio = p1;

  p1 = malloc (sizeof (struct elemento));
  p1->x = 'y';   
  p1->prox = pinicio;
  pinicio = p1;

  p1 = malloc (sizeof (struct elemento));
  p1->x = 'z';   
  p1->prox = pinicio;
  pinicio = p1;

  printf("elemento1  %c \n", pinicio->x);
  printf("elemento2  %c \n", pinicio->prox->x);
  printf("elemento3  %c \n", pinicio->prox->prox->x);
}

//-------------------------------------
main () {
  ponteiros1 ();
  system ("pause");     
  ponteiros2 ();
  system ("pause");     
  ponteiros3 ();
  system ("pause");     
  ponteiros4 ();
  system ("pause");     
  ponteiros5 ();
  system ("pause");     
  ponteiros6 ();
  system ("pause");     
  ponteiros7 ();
  system ("pause");     
  ponteiros8 ();
  system ("pause");     
  ponteiros9 ();
  system ("pause");     
}
  
