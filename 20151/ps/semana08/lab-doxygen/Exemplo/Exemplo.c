/*!	
*	Descrição do arquivo.
*	\author Genaína Nunes Rodrigues.
*	\since 01/12/11.
*	\version 1.0.
*
*/

/*!
* 
* \param a valor inteiro para ser verificado quanto à paridade.
* \return retorna 0, caso "a" seja par e 1 caso "a" seja impar.
*
*/
int VerificaParidade( int a){
	if (a == 0) {
		a++;
	}
	return a%2;
}

/**
* 
* @param a caracter de entrada
* @return a proxima letra do alfabeto depois de @param a, se for a ultima letra, rertorna para a primeira.
*/
char ProximaLetra( char a){
	a++;
	return a;
}

