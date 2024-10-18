// Author: reDragonCoder
//EJERCICIO 10.Convertir una cantidad de grados Celsius a grado farenheith. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float celsius, fahrenheit=0;

    //Pedir datos al usuario
    printf("Ingrese la temperatura en grados celsius: ");
    scanf("%f", &celsius);

    //Calculos
    fahrenheit=(celsius*9/5)+32;

    //Mostrar la conversion
    printf("La temperatura en grados fahrenheit es: %.1f", fahrenheit);

    return 0;
}