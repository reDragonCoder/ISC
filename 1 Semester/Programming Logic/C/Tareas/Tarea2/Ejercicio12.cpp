// Author: reDragonCoder
//EJERCICIO 12: El programa calcula lo que hay que pagarle a un trabajador teniendo
//en cuenta su sueldo, horas extras y su categoría

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    int categoria, hrs_extra;
    float sueldo_basico, pago_hrsextra=0, nsueldo=0;
    //Pedir datos al usuario
    printf("Ingrese el sueldo basico del trabajador: ");
    scanf("%f", &sueldo_basico);
    printf("Ingrese la categoria del trabajador: ");
    scanf("%d", &categoria);
    printf("Ingrese las horas extra trabajadas: ");
    scanf("%d", &hrs_extra);
    //Selección del caso segun la categoria del trabajador
    switch(categoria){
        case 1:
            pago_hrsextra=30;
        break;
        case 2:
            pago_hrsextra=38;
        break;
        case 3:
            pago_hrsextra=50;
        break;
        case 4:
            pago_hrsextra=70;
        break;
        default:
            pago_hrsextra=0;
        break;
    }
    //Calcular el pago total
    if(hrs_extra>30){
        nsueldo=sueldo_basico+30*pago_hrsextra;
    }
    else{
        nsueldo=sueldo_basico+hrs_extra*pago_hrsextra;
    }
    //Mostrar el pago total
    printf("El sueldo total es de: $%.2f", nsueldo);
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se cambiaron las variables a un nombre más específico