// Author: reDragonCoder
//Determinar si un número es divisible por 3

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num;
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    if(num%3==0){
        printf("El numero es divisible entre 3");
    }
    else{
        printf("EL numero no es divisible entre 3");
    }
    return 0;
}