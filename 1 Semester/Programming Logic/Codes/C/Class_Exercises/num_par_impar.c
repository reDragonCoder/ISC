// Author: reDragonCoder
//Verificar si un numero entero positivo es par o impar

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num;
    printf("Ingrese el numero");
    scanf("%d", &num);
    if (num%2==0){
        printf("El numero es par");
    }
    else{
        printf("El numero es impar");
    }
    return 0;
}
