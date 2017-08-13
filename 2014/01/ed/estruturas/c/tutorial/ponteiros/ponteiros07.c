main () {
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
  
  system ("pause");        
}
