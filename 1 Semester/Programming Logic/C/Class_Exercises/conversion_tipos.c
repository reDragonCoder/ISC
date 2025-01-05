// Author: reDragonCoder
//Ejemplo de conversion de tipos

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int numA=10, numB=7;
    float numC;
    //almacenamos valores enteros dentro de un flotante
    numC=numA/numB;  //cast implícito
    printf("%f \n", numC);

    int datoA;
    float datoB=8.5;
    datoA=(int)datoB;
    printf("%d \n", datoA);

    printf("%d \n",(char)'A'); //da 65 en Ascii es A (entero)
    printf("%c \n", (int) 'A'); //da A (caracter)
    printf("%c \n", (char)65); //da A en Ascii es 65 (caracter)

    return 0;
}