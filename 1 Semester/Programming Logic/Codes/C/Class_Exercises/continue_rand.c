// Author: reDragonCoder
//Manejo de continue y numeros aleatorios

//LIBRERIAS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TOT 10

//MAIN
int main(){
    //activar la generacion de aleatorios
    srand(time(NULL));
    int num=0, contador=0;
    for(int i=1; i<=TOT; i++){
        num=rand()%101;
        printf("%d \n", num);
        if(num>=15 && num<=30){
            continue;
        }
        contador++;
    }
    printf("Total de valores: %d", contador);
    return 0;
}