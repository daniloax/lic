int Fibonacci (int n) {
  pilhachar *p1;
  int fib, x;

  InicializaPilha (&p1);
  InserePilha (&p1, n);
  fib = 0;
  while (!PilhaVazia (p1)) {
	x = RetiraPilha (&p1);
	if ((x == 0) || (x == 1))
	  fib = fib + 1;
	else {
	  InserePilha (&p1, x-1);
	  InserePilha (&p1, x-2);
	}
  }
  return fib;
}
