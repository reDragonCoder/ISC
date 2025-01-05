// Author: reDragonCoder
//Ejercicio 2 - Más allá del cuarenta y dos
//Crea un código que pida al usuario un número y se repita hasta que coloque un número mayor a 42.
//Cuando se cumpla esta condición muestra el resultado en pantalla indicando esto al usuario y finaliza el ciclo.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int num=0;
    //repetir el ciclo mientras numero sea menor o igual a 42
    while(num<=42){
        //pedir el numero al usuario
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }
    //mostrar que se ingreso un numero mayor a 42 al finalizar el ciclo
    printf("Usted ingreso un numero mayor a 42");
    return 0;
}