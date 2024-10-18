// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float precio=0, suma=0, total=0;
    while(suma<=200){
        printf("Dame el precio: ");
        scanf("%f", &precio);
        suma+=precio;
        total++;
    }
    printf("El total es: %f", total);
    return 0;
}