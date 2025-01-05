// Author: reDragonCoder
//Ejercicio 7 – Mi edad
//Escribir un programa que pregunte al usuario su edad y muestre por pantalla todos 
//los años que ha cumplido (desde 1 hasta su edad).

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int edad;
    //pedir al usuario que ingrese su edad
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    //mostrar los años cumplidos
    printf("Usted a cumplido: \n");
    for(int i=1; i<=edad; i++){
        printf("%d \n", i);
    }
    printf("anios");
    return 0;
}