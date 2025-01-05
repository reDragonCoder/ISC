// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float numKilos, totalPagar, costoxkg;
    printf("Ingrese el numero de kilos: ");
    scanf("%f", &numKilos);
    printf("Ingrese el precio del kilo: ");
    scanf("%f", &costoxkg);
    if (numKilos >= 0 && numKilos <= 2){
        totalPagar = (costoxkg*numKilos);
        printf("Total a pagar: $%f", totalPagar);
    }
    if (numKilos >= 2.01 && numKilos <= 5){
        totalPagar = (costoxkg*numKilos) * 0.9;
        printf("Total a pagar: $%f", totalPagar);
    }
    if (numKilos >= 5.01 && numKilos <= 10){
        totalPagar = (costoxkg*numKilos) * 0.85;
        printf("Total a pagar: $%f", totalPagar);
    }
    if (numKilos >= 10.01){
        totalPagar = (costoxkg*numKilos) * 0.8;
        printf("Total a pagar: $%f", totalPagar);
    }
    return 0;
}