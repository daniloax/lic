main () {

  int x; 
  int *p1;
  x = 5;
  p1 = &x;
  *p1 = 8;
  printf("%d\n", *p1);    

  system("pause");
}