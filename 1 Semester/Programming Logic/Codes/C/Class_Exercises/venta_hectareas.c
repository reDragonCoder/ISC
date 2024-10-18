// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float DESCUENTO, hectareas, costo, costo_descuento, costo_individual, total_hectareas;
    int PERSONAS, i;
    PERSONAS = 3;
    DESCUENTO = 0.07;
    costo = 0;
    for (i = 1; i <= PERSONAS; i++)
    {
        printf("Ingrese la cantidad de hectareas vendidas a la persona %d: ", i);
        scanf("%f", &hectareas);
        costo = costo + (hectareas * 300);
    }
    costo_descuento = costo - (costo * DESCUENTO);
    costo_individual = costo_descuento / PERSONAS;
    total_hectareas = (costo / 3000) * 10;
    printf("El numero total de hectareas vendidas es: %f\n", total_hectareas);
    printf("El costo individual con descuento es: %f\n", costo_individual);
    printf("El costo total con descuento es: %f\n", costo_descuento);
    return 0;
}