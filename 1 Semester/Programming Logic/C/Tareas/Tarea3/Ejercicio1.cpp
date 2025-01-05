// Author: reDragonCoder
//Ejercicio 1- Suma hasta cincuenta
//Crea una variable que se llame total, después pide a tu usuario que ingrese un número y 
//lo sume al valor de total. Haz que esto se repita hasta que el valor de total sea mayor 
//a 50 y muestra el resultado en pantalla.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int total=0, num;
    //repetir el ciclo mientras el total sea menor a 50
    while(total<50){
        //pedir numero al usuario
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        //sumar el numero al total
        total+=num;
    }
    //mostrar la suma de los numeros al finalizar el ciclo
    printf("El total de los numeros ingresados es: %d", total);
    return 0;
}