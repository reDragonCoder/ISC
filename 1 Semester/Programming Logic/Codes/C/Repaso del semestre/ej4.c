// Author: reDragonCoder
//Escriba un algoritmo/programa para calcular la serie: 12 + 22 + 32 + ... + 10002

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float n=0, totalSerie=0;
    n=(10002-12)/8+1;
    totalSerie=n/2*(12+10002);
    printf("El resultado de la serie es: %.2f", totalSerie);
    return 0;
}
