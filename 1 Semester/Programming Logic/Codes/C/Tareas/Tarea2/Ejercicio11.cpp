// Author: reDragonCoder
//EJERCICIO 11: El programa, dados como dato la clave de la zona a ka cual se llamó
//y el número de minutos que duró la llamada, calcula el costo total de la misma

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    int clave, numin;
    float costo=0;
    //Pedir datos al usuario
    printf("Ingrese la clave de la zona a donde se marco (12, 15, 18, 19, 23, 25 o 29): ");
    scanf("%d", &clave);
    printf("Ingrese el numero de minutos que duro la llamada: ");
    scanf("%d", &numin);
    //Selección del caso segun la clave ingresada
    switch(clave){
        case 12:
            costo=numin*2;
        break;
        case 15:
            costo=numin*2.2;
        break;
        case 18:
            costo=numin*4.5;
        break;
        case 19:
            costo=numin*3.5;
        break;
        case 23:
            costo=numin*6;
        break;
        case 25:
            costo=numin*6;
        break;
        case 29:
            costo=numin*5;
        break;
        default:
            printf("Ingrese una clave valida");
        break;
    }
    //Mostrar el costo de la llamada
    printf("El costo total de la llamada es: %.2f", costo);
 
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se agregó un default para las claves incorrectas
