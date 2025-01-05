// Author: reDragonCoder
//Ejercicio 1

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    char nombre[50];
    int tipoHab, cantDias, numMemb;
    float totalPagar;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    fflush(stdin);
    printf("Ingrese el tipo de habitacion (1, 2 o 3): ");
    scanf("%d", &tipoHab);
    printf("Ingrese la cantidad de dias que se hospedara: ");
    scanf("%d", &cantDias);
    printf("Ingrese su numero de membresia: ");
    scanf("%d", &numMemb);
    if(numMemb>=100 && numMemb<=200){
        switch (tipoHab){
        case 1: 
            if(cantDias>0 && cantDias<=5){
                totalPagar=(700*cantDias)-200;
                printf("El huesped %s pagara $%.2f", nombre, totalPagar);
            }
            else{
                if(cantDias>5){
                    totalPagar=((700*cantDias)-200)*0.95;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    printf("Ingrese una cantidad de dias valida");
                }
            }
        break;
        case 2:
             if(cantDias>0 && cantDias<=5){
                totalPagar=(1000*cantDias)-200;
                printf("El huesped %s pagara $%.2f", nombre, totalPagar);
            }
            else{
                if(cantDias>5){
                    totalPagar=((1000*cantDias)-200)*0.90;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    printf("Ingrese una cantidad de dias valida");
                }
            }
        break;
        case 3:
            if(cantDias>0 && cantDias<=5){
                totalPagar=(1200*cantDias)-200;
                printf("El huesped %s pagara $%.2f", nombre, totalPagar);
            }
            else{
                if(cantDias>5){
                    totalPagar=((1200*cantDias)-200)*0.85;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    printf("Ingrese una cantidad de dias valida");
                }
            }
        break;
        default:
            printf("Ingrese un numero de habitacion valido");
        break;
        }
    }
    else{
        if(numMemb>0 && numMemb<100 && numMemb>200){
            switch (tipoHab){
            case 1: 
                if(cantDias>0 && cantDias<=5){
                    totalPagar=700*cantDias;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    if(cantDias>5){
                        totalPagar=(700*cantDias)*0.95;
                        printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                    }
                    else{
                        printf("Ingrese una cantidad de dias valida");
                    }
                }
            break;
            case 2:
                if(cantDias>0 && cantDias<=5){
                    totalPagar=1000*cantDias;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    if(cantDias>5){
                        totalPagar=(1000*cantDias)*0.90;
                        printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                    }
                    else{
                        printf("Ingrese una cantidad de dias valida");
                    }
                }
            break;
            case 3:
                if(cantDias>0 && cantDias<=5){
                    totalPagar=1200*cantDias;
                    printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                }
                else{
                    if(cantDias>5){
                        totalPagar=(1200*cantDias)*0.85;
                        printf("El huesped %s pagara $%.2f", nombre, totalPagar);
                    }
                    else{
                        printf("Ingrese una cantidad de dias valida");
                    }
                }
            break;
            default:
                printf("Ingrese un numero de habitacion valido");
            break;
            }
        }
    }
    return 0;  
}