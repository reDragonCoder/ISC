// Author: reDragonCoder
//El Estadio Cuscatlán es uno de los estadios más importantes de Centroamérica. Este estadio tiene
//diversos sectores. El costo de la entrada a los eventos futbolísticos del estadio se asigna en
//virtud de los sectores del estadio mediante la siguiente tabla:
//Sector         || Costo de la entrada
//Sol general    || $3
//Sol preferente || $5
//Sombra         || $8
//Tribuna        || $15
//Platea         || $20
//Se pide construir un programa que permita seleccionar un sector del estadio, ingresar la
//cantidad de entradas solicitadas y calcular el total a pagar por las entradas.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int sectorEstadio, cantBol;
    float totalPagar=0;

    printf("MENU DE OPCIONES \n");
    printf("Sol general ...... 1 \n");
    printf("Sol preferente ... 2 \n");
    printf("Sombra ........... 3 \n");
    printf("Tribuna .......... 4 \n");
    printf("Platea ........... 5 \n");
    printf("Selecciona tu opcion: ");
    scanf("%d", &sectorEstadio);
    printf("Ingrese la cantidad de entradas a comprar: ");
    scanf("%d", &cantBol);

    switch(sectorEstadio){
        case 1:
            totalPagar=cantBol*3;
        break;
         case 2:
            totalPagar=cantBol*5;
        break;
         case 3:
            totalPagar=cantBol*8;
        break;
         case 4:
            totalPagar=cantBol*15;
        break;
         case 5:
            totalPagar=cantBol*20;
        break;
        default:
            printf("Ingrese una opcion valida");
        break;
    }
    printf("El pago total es: $%.2f", totalPagar);
    return 0;
}