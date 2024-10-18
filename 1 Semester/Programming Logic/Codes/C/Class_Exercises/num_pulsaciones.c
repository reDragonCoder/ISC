// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float edad, pulsaciones;
    printf("Ingrese su edad: ");
    scanf("%f", &edad);
    pulsaciones = (220 - edad) / 10;
    printf("Por cada 10 seg de ejercicio, usted debe tener: %f pulsaciones", pulsaciones);
    return 0;
}