// Author: reDragonCoder
//16. Escribir un programa que lea del teclado y ordene de mayor a menor 20 números 
//    reales.

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define MAX 5

//MAIN
int main(){
    //declarar variables
    int temp=0, i=0;
    float vec[MAX];
    //llenar el vector con numeros reales
    for(i=0; i<=MAX; i++){
        printf("Ingrese un numero real: ");
        scanf("%f", &vec[i]);
    }
    printf("\n\n");
    //ordenar de manera ascendente (método burbuja)
    for(int k=0; k<=MAX; k++){
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
    //imprimir los numeros del vector ya ordenados
    do{
        printf("%.2f \t", vec[i]);
        i++;
    }while(i<MAX);
    return 0;
}