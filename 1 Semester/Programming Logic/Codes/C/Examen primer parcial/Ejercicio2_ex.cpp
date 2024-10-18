// Author: reDragonCoder
//Ejercicio 2

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int tipoLlamada, duracionMin, numLlamadas;
    float costo;

    printf("Ingrese el tipo de llamada (1 si es internacional, 2 si es nacional y 3 si es local): ");
    scanf("%d", &tipoLlamada);
    printf("Si su llamada es de tipo local, ingrese el numero de llamadas a realizar: ");
    scanf("%d", &numLlamadas);
    printf("Ingrese la duracion de su llamada en minutos: ");
    scanf("%d", &duracionMin);

    switch (tipoLlamada)
    {
    case 1: 
        if(duracionMin<=3){
            costo=7.59;
            printf("El costo de la llamada es de $%.2f", costo);
        }
        else{
            if(duracionMin>3){
                duracionMin-=3;
                costo=7.59+(duracionMin*3.0);
                printf("El costo de la llamada es de $%.2f", costo);
            }
        }
        break;
    
    case 2:
        if(duracionMin<=3){
            costo=1.20;
            printf("El costo de la llamada es de $%.2f", costo);
        }
        else{
            if(duracionMin>3){
                duracionMin-=3;
                costo=1.20*(duracionMin*1.00);
                printf("El costo de la llamada es de $%.2f", costo);
            }
        }
        break;

    case 3:
        if(numLlamadas<=50){
            printf("El costo de sus llamadas es de $0");
        }
        else{
            if(numLlamadas>50){
                numLlamadas-=50;
                costo=numLlamadas*6.00;
                printf("El costo de sus llamadas es de $%.2f", costo);
            }
        }
        break;

    default:
        printf("Ingrese un tipo de llamada valido");
        break;
    }
    return 0;
}