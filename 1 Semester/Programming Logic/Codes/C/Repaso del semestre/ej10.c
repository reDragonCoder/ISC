// Author: reDragonCoder
//Se tiene en un arreglo cincuenta elementos representando calificaciones de los estudiantes 
//de una escuela. Realice un algoritmo que lea el arreglo y calcule la calificación promedio del 
//grupo, además, que cuente los estudiantes que obtuvieron calificaciones arriba del promedio 
//del grupo.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float calificaciones[50];
    int contador_alum=0;
    float promedio=0, sumatoria=0;
    for(int i=0; i<50; i++){
        printf("Ingrese la calificacion del alumno %d: ", i+1);
        scanf("%f", &calificaciones[i]);
        sumatoria+=calificaciones[i];
    }
    promedio=sumatoria/5;
    for(int i=0; i<5; i++){
        if(calificaciones[i]>promedio){
            contador_alum++;
        }
        else{
            continue;
        }
    }
    printf("\n");
    printf("La calificacion promedio del grupo es: %.2f \n", promedio);
    printf("El numero de estudiantes arriba del promedio es: %d", contador_alum);
    return 0;
}