// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float calif_parcial1, calif_parcial2, calif_final, calif_proyecto, total_calif;
    printf("Ingrese la calificación del 1er parcial: ");
    scanf("%f", &calif_parcial1);
    printf("Ingrese la calificación del 2ndo parcial: ");
    scanf("%f", &calif_parcial2);
    printf("Ingrese la calificación del final: ");
    scanf("%f", &calif_final);
    printf("Ingrese la calificación del proyecto: ");
    scanf("%f", &calif_proyecto);
    total_calif = (calif_parcial1 * .25) + (calif_parcial2 * .25) + (calif_final * .3) + (calif_proyecto * .2);
    printf("Su calificacion total es: %f", total_calif);
    return 0;
}