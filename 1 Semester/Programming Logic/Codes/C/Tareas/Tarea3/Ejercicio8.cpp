// Author: reDragonCoder
//Ejercicio 8 - Intereses
//Escribir un programa que pregunte al usuario una cantidad a invertir, el interés anual y
//el número de años, y muestre por pantalla el capital obtenido en la inversión cada año que dura la inversión.

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //declarar las variables
    int anios;
    float cantidad, interes, capital_total=0;
    //pedir los datos al usuario
    printf("Ingrese la cantidad a invertir: ");
    scanf("%f", &cantidad);
    printf("Ingrese el valor del interes anual expresado en decimal: ");
    scanf("%f", &interes);
    printf("Ingrese el numero de anios de la inversion: ");
    scanf("%d", &anios);
    //repetir y mostrar el capital total para cada año de la inversion
    for(int i=1; i<=anios; i++){
        capital_total=cantidad*pow((1+interes), i);
        printf("El capital obtenido en el anio %d es de $%.2f \n", anios, capital_total);
    }
    return 0;
}