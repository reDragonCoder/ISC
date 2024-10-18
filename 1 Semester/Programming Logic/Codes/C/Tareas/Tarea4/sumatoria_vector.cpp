// Author: reDragonCoder
//Sumatoria de elementos de un vector

//LIBRERIAS
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TAM 10

//MAIN
int main(){
    srand(time(NULL));
    int vecA[TAM], suma=0;

    //llenar el vector A con valores aleatorios
    for(int i=0; i<TAM; i++){
        vecA[i]=rand()%31;
    }

    //mostrar el vector A
    for(int i=0; i<TAM; i++){
        printf("%d ", vecA[i]);
    }

    //obtener sumatoria
    for(int i=0; i<TAM; i++){
        suma+=vecA[i];
    }
    printf(" \n Sumatoria: %d", suma);

    return 0;
}