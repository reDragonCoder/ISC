// Author: reDragonCoder
//EJERCICIO 1: El número de sonidos emitidos por un grillo en un minuto, es una función de la
//temperatura. Como resultado de esto, es posible determinar el nivel de la temperatura haciendo
//uso de un grillito como termómetro. la fórmula es T=N/4+40

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Declarar variables
    float temp_fahrenheit=0, num_sonidos;
    //Pedir datos al usuario
    printf("Ingrese el numero de sonidos emitidos por el grillo en un minuto: ");
    scanf("%f", &num_sonidos);
    //Evaluar y realizar calculos de la temperatura
    if(num_sonidos>0){
        temp_fahrenheit=num_sonidos/4+40;
        //Mostrar el resultado
        printf("Temperatura: %0.2f", temp_fahrenheit);
    }
    else{
        //Mostrar error en el numero de sonidos
        printf("Ingrese un numero valido");
    }
    return 0;
}

//Se cambiaron las variables N=num_sonidos y T=temp_fahrenheit
//Se declaró num_sonidos (N) como flotante para poder realizar correctamente los cálculos
//Se agregó un else para avisar que N<0 no es valido