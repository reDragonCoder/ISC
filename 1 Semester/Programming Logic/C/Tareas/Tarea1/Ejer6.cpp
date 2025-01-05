// Author: reDragonCoder
// EJERCICIO 6. Calcular el nuevo salario de un obrero si obtuvo un incremento del 25% sobre su salario anterior. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float sal_anterior, sal_nuevo=0;

    //Pedir datos al usuario
    printf("Ingrese su salario anterior: ");
    scanf("%f", &sal_anterior);

    //Calcular salario nuevo
    sal_nuevo = sal_anterior * 1.25;

    //Mostrar el salario nuevo
    printf("Su nuevo salario es: $%.2f", sal_nuevo);
    return 0;
} //Main

