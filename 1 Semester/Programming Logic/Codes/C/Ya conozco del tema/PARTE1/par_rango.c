// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int inicio, fin;
    printf("Ingrese el valor de inicio del rango: ");
    scanf("%d", &inicio);
    printf("Ingrese el valor final del rango: ");
    scanf("%d", &fin);
    for (int i=inicio; i<=fin; i++){
        if (i%2==0){
            printf("%d\n", i);
        }
    }
    return 0;
}