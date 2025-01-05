// Author: reDragonCoder
//EJERCICIO 1. Obtener el promedio simple de un estudiante a partir de sus tres notas parciales. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float nota1, nota2, nota3, promedio=0;

    //Pedir datos al usuario
    printf("Ingrese la nota 1: ");
    scanf("%f", &nota1);
    printf("Ingrese la nota 2: ");
    scanf("%f", &nota2);
    printf("Ingrese la nota 3: ");
    scanf("%f", &nota3);
    
    //Calcular el promedio
    promedio=(nota1+nota2+nota3)/3;

    //Mostrar promedio
    printf("Su promedio es de: %.2f", promedio);
    return 0;
}// Main