// Author: reDragonCoder
//20. Escribir un programa que indique si los dos arrays dados como entrada son iguales o no.

//LIBRERIAS
#include <stdio.h>
#include <stdbool.h>

//CONSTANTES GLOBALES
#define MAX 5

//MAIN
int main(){
    //declarar variables
    int array1[MAX], array2[MAX];
    bool ban=true;
    //llenar primer array
    for(int i=0; i<MAX; i++){
        printf("Ingrese un numero para el primer array: ");
        scanf("%d", &array1[i]);
    }
    printf("\n");
    //llenar segundo array
    for(int j=0; j<MAX; j++){
        printf("Ingrese un numero para el segundo array: ");
        scanf("%d", &array2[j]);
    }
    //comparar cada posicion de ambos arrays
    for(int k=0; k<MAX; k++){
        //declarar bandera como verdadero y continuar si los valores de la posicion k son iguales
        if(array1[k]==array2[k]){
            ban=true;
            continue;
        }
        else{
            //declarar bandera como falso y terminar el ciclo si los valores de la posicion k son diferentes
            if(array1[k]!=array2[k]){
                ban=false;
                break;
            }
        }
    }
    printf("\n");
    //mostrar si los arrays son iguales o no
    if(ban==true){
        printf("Los arrays son iguales");
    }
    else{
        if(ban==false){
            printf("Los arrays NO son iguales");
        }
    }
    return 0;
}