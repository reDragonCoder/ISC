// Author: reDragonCoder
//EJERCICIO 5. Calcular el número de pulsaciones que una persona debe tener por cada 10 segundos de ejercicio, si la fórmula es: 
//numero pulsaciones = (220 - edad)/10 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    int no_pulsaciones=0, edad;

    //Pedir datos al usuario
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    //Calcular el numero de pulsaciones
    no_pulsaciones = (220 - edad)/10;

    //Mostrar el numero de pulsaciones
    printf("Su numero de pulsaciones por cada 10 segundos de ejercicio debe de ser de: %d", no_pulsaciones);
    return 0;
} //Main