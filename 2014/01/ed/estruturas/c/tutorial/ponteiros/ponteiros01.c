main () {

  int x, y; 
  int *p1;
  x = 5;
  p1 = &x;
  y = *p1;
  printf("valor de y: %d\n", y);
  printf("endereco para onde aponta o ponteiro p1: %p\n", p1);  
  printf("valor da variavel apontada pelo ponteiro p1: %d\n", *p1);   
  
  system("pause");
}
