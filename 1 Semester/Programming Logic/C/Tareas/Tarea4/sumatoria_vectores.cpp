// Author: reDragonCoder
//Sumatoria de vectores

//LIBRERIAS
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TAM 10

//MAIN
int main(){
    srand(time(NULL));
    int vecA[TAM], vecB[TAM], vecC[TAM], suma=0;

    //llenar el vector A con valores aleatorios
    for(int i=0; i<TAM; i++){
        vecA[i]=rand()%31;
        vecB[i]=rand()%51;
    }

    //mostrar el vector A
    printf("Contenido vector A: \n");
    for(int i=0; i<TAM; i++){
        printf("%d ", vecA[i]);
    }
    printf("\n\n");
    //mostrar el vector B
    printf("Contenido vector B: \n");
    for(int i=0; i<TAM; i++){
        printf("%d ", vecB[i]);
    }
    printf("\n\n");
    //obtener sumatoria
    for(int i=0; i<TAM; i++){
        suma+=vecA[i];
    }
    printf(" \n Sumatoria del vector A: %d \n", suma);

    //suma de vecC = vecA + vecB
    for(int i=0; i<TAM; i++){
        vecC[i]=vecA[i]+vecB[i];
    }

    //mostrar el contenido del vecC
    printf("Contenido del vector C: ");
    for(int i=0; i<TAM; i++){
        printf("%d ", vecC[i]);
    }

    return 0;
}