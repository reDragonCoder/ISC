// Author: reDragonCoder
//Ejercicio 10 – Triángulos de dígitos
//Escribir un programa que pida al usuario un número entero y muestre por pantalla un triángulo 
//rectángulo como el de más abajo.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int tam;
    //pedir la altura del triangulo
    printf("Ingrese la altura de su triangulo: ");
    scanf("%d", &tam);
    //dibujar el triangulo
    for(int i=1; i<=tam+1; i=i+2){
        for(int j=i; j>0; j=j-2){
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}

//FUNCIONAMIENTO INTERNO
//1 1 -1
//3 3 1 -1
//5 5 3 1 -1

//FUNCIONAMIENTO EXTERNO
//1
//3 1
//5 3 1