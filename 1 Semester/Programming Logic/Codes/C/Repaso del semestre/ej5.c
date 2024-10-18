// Author: reDragonCoder
//Escriba un algoritmo/programa que permita obtener el factorial de un número. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num, factorial=1;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    for(int i=num; i>=1; i--){
        factorial*=i;
    }
    printf("%d! = %d", num, factorial);
    return 0;
}