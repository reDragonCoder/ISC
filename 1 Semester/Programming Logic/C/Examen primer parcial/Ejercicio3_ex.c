// Author: reDragonCoder
//Ejercicio 3

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num1=0, num2=0, num3=0, suma;
    
    printf("Ingrese el numero 1: ");
    scanf("%d", &num1);
    printf("Ingrese el numero 2: ");
    scanf("%d", &num2);
    printf("Ingrese el numero 3: ");
    scanf("%d", &num3);
    
    suma=num1+num2;
    if(suma==num3){
        printf("La suma de %d + %d = %d", num1, num2, num3);
    }
    else{
        suma=num1+num3;
        if(suma==num2){
            printf("La suma de %d + %d = %d", num1, num3, num2);
        }
        else{
            suma=num2+num3;
            if(suma==num1){
                printf("La suma %d + %d = %d", num2, num3, num1);
            }
            else{
                printf("Ninguna combinacion es correcta");
            }
        }
    }
    return 0;
}
