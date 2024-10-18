// Author: reDragonCoder
//EJERCICIO 5: El programa dado como dato un número entero, determina si el mismo es positivo, negativo o nulo


//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir la variable
    int num;
    //Pedir dato al usuario
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    //Evaluar si num es positivo, negativo o nulo
    if(num>0){
        printf("El numero es positivo");
    }
    else{
        if(num==0){
            printf("El numero es nulo (0)");
        }
        else{
            printf("El numero es negativo");
        }
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes