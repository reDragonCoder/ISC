// Author: reDragonCoder
//Escriba un programa que presente un menú de opciones para seleccionar un número entero entre
//1-7, y cada opción un mensaje indicando el día que corresponde, por ejemplo 3 corresponde al
//miércoles considerando que el 1 es lunes.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int dia;
    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &dia);
    switch(dia){
        case 1:
            printf("Es lunes");
        break;
        case 2:
            printf("Es martes");
        break;
        case 3:
            printf("Es miercoles");
        break;
        case 4:
            printf("Es jueves");
        break;
        case 5:
            printf("Es viernes");
        break;
        case 6:
            printf("Es sabado");
        break;
        case 7:
        printf("Es domingo");
        break;
        default:
            printf("Ingrese un numero valido");
        break;
    }
    return 0;
}