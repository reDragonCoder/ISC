// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float tiempo_atleta1, tiempo_atleta2, tiempo_total;
    printf("Ingrese el tiempo del atleta 1: ");
    scanf("%f", &tiempo_atleta1);
    printf("Ingrese el tiempo del atleta 2: ");
    scanf("%f", &tiempo_atleta2);
    tiempo_total = tiempo_atleta1 + tiempo_atleta2;
    printf("El tiempo total de los atletas es: %f", tiempo_total);
    return 0;
}