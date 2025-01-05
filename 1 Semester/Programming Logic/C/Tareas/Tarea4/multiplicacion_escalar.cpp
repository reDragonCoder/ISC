// Author: reDragonCoder
//multiplicar un vector con un escalar
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
    int vecA[TAM], vecB[TAM], vecC[TAM], vecD[TAM], suma=0, escalar;

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
    printf("Sumatoria del vector A: %d \n\n", suma);

    //suma de vecC = vecA + vecB
    for(int i=0; i<TAM; i++){
        vecC[i]=vecA[i]+vecB[i];
    }

    //mostrar el contenido del vecC
    printf("Contenido del vector C: \n");
    for(int i=0; i<TAM; i++){
        printf("%d ", vecC[i]);
    }
    printf("\n");
    //producto por un escalar
    printf("Valor del escalar: ");
    scanf("%d", &escalar);
    for(int i=0; i<TAM; i++){
        vecD[i]=escalar*vecC[i];
    }
    printf("\n");
    //mostrar el vector D
    printf("Contenido vector D: \n");
    for(int i=0; i<TAM; i++){
        printf("%d ", vecD[i]);
    }
    return 0;
}