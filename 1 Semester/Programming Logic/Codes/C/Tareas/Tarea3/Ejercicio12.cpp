// Author: reDragonCoder
//Ejercicio 12 - Primos
//Escribir un programa que pida al usuario un número entero y muestre por pantalla si es un número primo o no.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int num, c=0;
    //pedir el numero a evaluar
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    //repetir mientras i sea menor o igual a num
    for(int i=1; i<=num; i++){
        //agregar 1 al contador c mientras se cumpla la condicion
        if(num%i==0){
            c++;
        }
    }
    //si el contador es igual a 2, el numero es primo
    if(c==2){
        printf("El numero es primo");
    }
    //si no, el numero no es primo
    else{
        printf("El numero NO es primo");
    }
    return 0;
}