// Author: reDragonCoder
// Que pida un número del 1 al 12 y diga el nombre del mes correspondiente

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num;
    printf("Ingrese un numero del 1 al 12: ");
    scanf("%d", &num);
    switch(num){
        case 1:
            printf("El mes es enero");
            break;
        case 2:
            printf("El mes es febrero");
            break;
        case 3:
            printf("El mes es marzo");
            break;
        case 4:
            printf("El mes es abril");
            break;
        case 5:
            printf("El mes es mayo");
            break;
        case 6:
            printf("El mes es junio");
            break;
        case 7:
            printf("El mes es julio");
            break;
        case 8:
            printf("El mes es agosto");
            break;
        case 9:
            printf("El mes es septiembre");
            break;
        case 10:
            printf("El mes es octubre");
            break;
        case 11:
            printf("El mes es noviembre");
            break;
        case 12:
            printf("El mes es diciembre");
            break;
        default:
            printf("Ingrese una opcion valida");
            break;
        
    }
    return 0;
}