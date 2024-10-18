// Author: reDragonCoder
//Realice un algoritmo que lea dos vectores de cien elementos y que calcule la suma de éstos 
//guardando su resultado en otro vector, el cual se debe presentar en forma impresa.

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define TAM 100

//MAIN
int main(){
    int vector1[TAM], vector2[TAM], suma[TAM];
    printf("Ingrese los valores del primer vector: \n");
    for(int i=0; i<TAM; i++){
        scanf("%d", &vector1[i]);
    }
    printf("Ingrese los valores del segundo vector: \n");
    for(int i=0; i<TAM; i++){
        scanf("%d", &vector2[i]);
    }
    for(int i=0; i<TAM; i++){
        suma[i]=vector1[i]+vector2[i];
    }
    printf("La suma es: \n");
    for(int i=0; i<TAM; i++){
        printf("%d, ", suma[i]);
    }
    return 0;
}