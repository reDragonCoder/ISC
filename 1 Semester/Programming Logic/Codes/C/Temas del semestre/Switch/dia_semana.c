// Author: reDragonCoder
//Determinar el día de la semana

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num;
    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &num);
    switch(num){
        case 1:
            printf("El dia de la semana es lunes");
            break;
        case 2:
            printf("El día de la semana es martes");
            break;
        case 3:
            printf("El dia de la semana es miercoles");
            break;
        case 4:
            printf("El dia de la semana es jueves");
            break;
        case 5:
            printf("El dia de la semana es viernes");
            break;
        case 6:
            printf("El dia de la semana es sabado");
            break;
        case 7:
            printf("El dia de la semana es domingo");
            break;
        default:
            printf("Ingrese un numero valido");
            break;
    }
    return 0;
}