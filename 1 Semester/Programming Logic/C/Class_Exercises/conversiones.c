// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main() {
    float pies, metros, suma_pulgadas, suma_yardas, suma_metros, suma_millas;
    printf("Ingresa la cantidad en pies: ");
    scanf("%f", &pies);
    printf("Ingresa la cantidad en metros: ");
    scanf("%f", &metros);
    suma_metros = (pies/3.281) + metros;
    suma_pulgadas = suma_metros * 39.37;
    suma_yardas = suma_metros * 1.094;
    suma_millas = suma_metros / 1609;
    printf("La suma expresada en pulgadas es: %f\n", suma_pulgadas);
    printf("La suma expresada en yardas es: %f\n", suma_yardas);
    printf("La suma expresada en metros es: %f\n", suma_metros);
    printf("La suma expresada en millas es: %f\n", suma_millas);
    return 0;
}