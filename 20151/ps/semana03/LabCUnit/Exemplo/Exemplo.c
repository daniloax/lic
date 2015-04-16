/* Função retorna 0, caso "a" seja par e 1 caso "a" seja impar */
int VerificaParidade(int a) {
	
	if (a == 0)
	  a = a + 2;

	if (a < 0)
	  a = abs(a);
	  
	return a%2;
}

/*
 Função TestaParidade:
 Entrada	Esperado
 0			0
 1			1
 2			0
 3			1
 .			.
 .			.
 .			.
 */

/* Retorna a proxima letra do alfabeto, se for a ultima letra, retorna para a primeira*/
char ProximaLetra(char a) {
// if (a >= 65 && a <= 90 && a >= 97 && a <= 122) {
	  
	  if (a == 90) {
	    a = 65;
	    return a;
	  
	  }
	  
	  if (a == 122) {
	    a = 97;
	    return a;

	  }
	  a++;
	  return a;
}

/*
Função ProximaLetra:
 Entrada	Esperado
 A			B
 B			C
 Z			A
 a			b
 b			c
 z			a
 .			.
 */

