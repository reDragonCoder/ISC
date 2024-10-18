// Author: reDragonCoder
//EJERCICIO 7: El programa dados como datos tres números enteros, determina si
//los mismos están en orden creciente

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    int num1, num2, num3;
    //Pedir datos al usuario
    printf("Ingrese el numero 1: ");
    scanf("%d", &num1);
     printf("Ingrese el numero 2: ");
    scanf("%d", &num2);
     printf("Ingrese el numero 3: ");
    scanf("%d", &num3);
    //Evaluar el orden de los numeros
    if(num1<num2){
        if(num2<num3){
            printf("Los numeros estan en orden creciente");
        }
        else{
            printf("Los numeros NO estan en orden creciente");
        }
    }
    else{
        printf("Los numeros NO estan en orden creciente");
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se cambiaron las variables de A, B, C a num1, num2, num3 para que sean más específicas