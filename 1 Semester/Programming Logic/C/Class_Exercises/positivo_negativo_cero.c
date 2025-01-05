// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float num;
    printf("Ingrese un numero: ");
    scanf("%f", &num);
    if (num == 0){
        printf("El numero es cero");
    }
    else{
        if(num > 0){
            printf("El numero es positivo");
        }
        else{
            printf("El numero es negativo");
        }
    }
    return 0;
}