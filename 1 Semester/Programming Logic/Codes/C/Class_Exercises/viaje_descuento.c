// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float costo_primera, costo_segunda, total;
    printf("Ingrese el costo del camion de primera: ");
    scanf("%f", &costo_primera);
    costo_segunda = costo_primera - (costo_primera * 0.30);
    total = (2 * costo_primera) + (3 * costo_segunda);
    printf("El total a pagar por las cinco personas es: %f", total);
    return 0;
}