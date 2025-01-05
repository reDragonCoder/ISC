// Author: reDragonCoder
//Ejercicio 9 – Triángulos de *
//Escribir un programa que pida al usuario un número entero y muestre por pantalla un triángulo rectángulo 
//como el de más abajo, de altura el número introducido.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variable
    int tam;
    //pedir la altura del triangulo al usuario
    printf("Ingrese la altura de su triangulo: ");
    scanf("%d", &tam);
    //dibujar el triangulo
    for(int i=1; i<=tam; i++){
        for(int j=1; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}