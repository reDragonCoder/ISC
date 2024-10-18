// Author: reDragonCoder
//2. Escribir un programa que calcule cual es el menor de dos números enteros que se
//   indican por el usuario. El resultado será otro número entero que se muestra en pantalla.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int num1, num2;
    //pedir los 2 numeros a comparar al usuario
    printf("Ingrese el primer numero entero a evaluar: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero entero a evaluar: ");
    scanf("%d", &num2);
    //evaluar si el primer numero es mayor al segundo numero
    if(num1>num2){
        printf("El numero mayor es: %d", num1);
    }
    else{
        printf("El numero mayor es: %d", num2);
    }
    return 0;
}