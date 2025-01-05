// Author: reDragonCoder

//Uso de los operadores de incremento ++ y decremento -- (solo enteros)
//NOTA: la asignacion va de derecha a izquierda

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int numA=1; //numero inicializado en 1
    int numB=++numA; //++numA --> numA=numA+1 ---- Primero usa la variable y luego le suma 1
    int numC=numA++; //numA++ --> numA=numA+1 ---- Primero toma el numero A, se lo asigna y despues suma 1 a A

    printf("numB = %d \n", numB);
    printf("numC = %d \n", numC);
    printf("numA = %d \n", numA);
    return 0;
}
