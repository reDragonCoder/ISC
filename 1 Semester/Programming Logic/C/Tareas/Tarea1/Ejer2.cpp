// Author: reDragonCoder
//EJERCICIO 2. Calcular el pago de un empleado. Para ello se dispone de sus horas laboradas 
//en el mes, así como la tarifa por hora. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float pago_empleado=0, tarifaXHr, hrsXMes;

    //Pedir datos al usuario
    printf("Ingrese sus horas laboradas en el mes: ");
    scanf("%f", &hrsXMes);
    printf("Ingrese la tarifa por hora: ");
    scanf("%f", &tarifaXHr);

    //Calcular pago empleado
    pago_empleado=tarifaXHr*hrsXMes;

    //Mostrar el pago del empleado
    printf("El pago del empleado es: $%.2f", pago_empleado);
    return 0;
} //Main