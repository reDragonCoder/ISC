// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float hrsmes, tarifaxhr, pago;
    printf("Ingrese las horas trabajadas en el mes: ");
    scanf("%f", &hrsmes);
    printf("Ingrese la tarifa por hora: ");
    scanf("%f", &tarifaxhr);
    pago = hrsmes * tarifaxhr;
    printf("El promedio es: %.2f", pago);
    return 0;
}