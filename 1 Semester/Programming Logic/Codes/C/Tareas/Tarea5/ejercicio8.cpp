// Author: reDragonCoder
//8. Escribir un programa que llene matriz de afuera hacia adentro

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define TAM 5

//MAIN
int main(){
    //declarar variables
    int matriz[TAM][TAM];
    int contador=1;

    //ciclo externo
    for(int i=0; i<TAM; i++){
        //primer ciclo anidado
        for(int k=i; k<TAM-i; k++){
            matriz[i][k]=contador++;
        }
        //segundo ciclo anidado
        for(int k=i+1; k<=TAM-i-1; k++){
            matriz[k][TAM-i-1]=contador++;
        }
        //tercer ciclo anidado
        for(int k=TAM-i-2; k>=i; k--){
            matriz[TAM-i-1][k]=contador++;
        }
        //cuarto ciclo anidado
        for(int k=TAM-2-i; k>i; k--){
            matriz[k][i]=contador++;
        }
    }
    //mostrar la matriz
    for(int i=0; i<TAM; i++){
        for(int k=0; k<TAM; k++){
            if(matriz[i][k]<10){
                printf("%d \t", matriz[i][k]);
            }
            else{
                printf("%d \t", matriz[i][k]);
            }
        }
        printf("\n");
    }
    return 0;
}
