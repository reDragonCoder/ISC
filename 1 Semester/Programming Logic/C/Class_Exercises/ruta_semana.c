// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float tiem_lunes, tiem_miercoles, tiem_viernes, total;
    printf("Ingrese el tiempo en min y seg del lunes: ");
    scanf("%f", &tiem_lunes);
    printf("Ingrese el tiempo en min y seg del miercoles: ");
    scanf("%f", &tiem_miercoles);
    printf("Ingrese el tiempo en min y seg del viernes: ");
    scanf("%f", &tiem_viernes);
    total = (tiem_lunes + tiem_miercoles + tiem_viernes) / 3;
    printf("El tiempo promedio de la semana es: %f", total);
    return 0;
}