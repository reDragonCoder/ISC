// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float precio_original, precio_ganancia, GANANCIA;
    printf("Ingrese el precio original del artículo: ");
    scanf("%f", &precio_original);
    GANANCIA = 0.05;
    precio_ganancia = (precio_original * GANANCIA) + precio_original;
    printf("El precio de venta para obtener una ganancia de 5 porciento es: %f", precio_ganancia);
    return 0;
}