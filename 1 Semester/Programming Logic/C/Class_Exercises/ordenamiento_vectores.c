// Author: reDragonCoder
//ordenacion de arreglos (método burbuja)

//LIBRERIAS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define MAX 10

//MAIN
int main(){
    srand(time(NULL));
    int vec[MAX], i=0, temp=0;
    //llenar el vector con aleatorios
    while(i<MAX){
        vec[i]=rand()%100;
        printf("%d \t", vec[i]);
        i++;
    }
    printf("\n\n");
    //ordenar ascendente
    for(int k=1; k<MAX; k++){
        for(int j=0; j<MAX-1;j++){
            //comparaciones
            if(vec[j]>vec[j+1]){
                temp=vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=temp;
            }
        }
    }
    i=0;
    do{
        printf("%d \t", vec[i]);
        i++;
    }while(i<MAX);
    return 0;
}