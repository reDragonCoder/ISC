// Author: reDragonCoder
//EJERCICIO 10: El programa, dados como datos tres números cuyos valores pueden ser iguales, 
//determina cuál es el mayor o los mayores

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    float num1, num2, num3;
    //Pedir datos al usuario
    printf("Ingrese el numero 1: ");
    scanf("%f", &num1);
    printf("Ingrese el numero 2: ");
    scanf("%f", &num2);
    printf("Ingrese el numero 3: ");
    scanf("%f", &num3);
    //Evaluar los numeros y mostrar el resultado
    if(num1>num2){
        if(num1>num3){
            printf("El numero 1 es el mayor");
        }
        else{
            if(num1==num3){
                printf("El numero 1 y el numero 3 son los mayores");
            }
            else{
                printf("El numero 3 es el mayor");
            }
        }
    }
    else{
        if(num1==num2){
            if(num1>num3){
                printf("El numero 1 y el numero 2 son los mayores");
            }
            else{
                if(num1==num3){
                    printf("El numero 1, numero2 y numero 3 son los mayores");
                }
                else{
                    printf("El numero 3 es el mayor");
                }
            }
        }
        else{
            if(num2>num3){
                printf("El numero 2 es el mayor");
            }
            else{
                if(num2==num3){
                    printf("EL numero 2 y el numero 3 son los mayores");
                }
                else{
                    printf("El numero 3 es el mayor");
                }
            }
        }
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se cambiaron las variables de A, B, C a num1, num2, num3 para que sean más específicas