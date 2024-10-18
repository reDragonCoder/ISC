// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float calif1, calif2, calif3, promedio;
    printf("Dame la primera calificacion: ");
    scanf("%f", &calif1);
    printf("Dame la segunda calificacion: ");
    scanf("%f", &calif2);
    printf("Dame la tercera calificacion: ");
    scanf("%f", &calif3);
    promedio = (calif1 + calif2 + calif3) / 3;
    printf("El promedio es: %.2f", promedio);
    return 0;
}