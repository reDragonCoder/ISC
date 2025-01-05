// Author: reDragonCoder
//Determinar si un número es positivo, negativo o cero

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num;
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    if (num>0){
        printf("El numero es positivo");
    }
    if(num<0){
        printf("EL numero es negativo");
    }
    if(num==0){
        printf("El numero es cero");
    }
    return 0;
}