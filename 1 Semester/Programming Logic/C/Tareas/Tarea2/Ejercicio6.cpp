//EJERCICIO 6: El programa dado como dato un número entero, determina si el
//mismo es par, impar o nulo

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //Definir la variable
    int num;
    //Pedir dato al usuario
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    //Evaluar si num es par, impar o nulo
    if(num==0){
        printf("El numero es nulo");
    }
    else{
        if(pow(-1, num)>0){
            printf("El numero es par");
        }
        else{
            printf("El numero es impar");
        }
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se cambió la variable de A a num para que sea más específica