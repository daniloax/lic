/*
 * tamantipo.c - Mostra o tamanho dos tipos: short/long int, char, float 
 *               e double
 * 2011 - (GPL) Jean Landim - <jewanbb@gmail.com>
 */
#include<stdio.h>
#include<stdlib.h>

int main() {

   int i;
   char *tipos[6];

         tipos[0] = "char";
         tipos[1] = "int";
         tipos[2] = "float";
         tipos[3] = "long int";
         tipos[4] = "double";
         tipos[5] = "short int";

   for (i = 0; i < 5; i++)
      printf("O valor de %s e de %d bytes\n", tipos[i], sizeof(tipos[i])); 
   
   system("pause");
   
   return 0;
   
}
   
