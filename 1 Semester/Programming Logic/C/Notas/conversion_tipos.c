// Author: reDragonCoder

//Conversión de tipos
//Tipos de datos --> char, int, float, double
//char en un int, un int en un float, un float en un double //cast implícito
//double en un float, float en un int, int en un char //cast explícito

//Ejemplo:
//float calif;
//int num;      
//calif=num;  --> si se puede

//num=calif  --> error
//num=(int)calif; --> conversion de mas grande a mas pequeño, quitando decimales


//#include <ctype.h> //to lower
//Ejemplo que muestre las letras del abecedario en mayusculas y en minusculas
//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//    for(int i=65; i<=90; i++){
//        printf("%c \t %c \n", (char)i, tolower((char)i));
//   }
//    return 0;
//}