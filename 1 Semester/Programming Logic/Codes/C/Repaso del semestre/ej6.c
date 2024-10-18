// Author: reDragonCoder
//Escriba un algoritmo para determinar el sueldo neto para cada trabajador con base a las  horas trabajadas 
//las cuales no deben ser mayor a 56 horas. Capturar para cada trabajador: la clave, nombre, puesto, horas 
//trabajadas e importe por hora. Deberá imprimir la clave, nombre, puesto, sueldo neto y la deducción (2.5 % 
//del sueldo parcial). Tome en cuenta que tiene N trabajadores. Al final deberá determinarse la cantidad total 
//que se paga en sueldos.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num_trabajadores=0, hrs_trabajadas=0, clave;
    float impxHr=0, total_sueldos=0, sueldo_neto=0, deduccion=0;
    char nombre[20]={""}, puesto[30]={""};
    printf("Ingrese cuantos trabajadores tiene: ");
    scanf("%d", &num_trabajadores);
    if(num_trabajadores>0){
        for(int i=1; i<=num_trabajadores; i++){
            printf("Ingrese la clave del trabajador %d (4 digitos): ", i);
            scanf("%d", &clave);
            printf("Ingrese el nombre del trabajador %d: ", i);
            fflush(stdin);
            scanf("%s", nombre);
            printf("Ingrese el puesto del trabajador %d: ", i);
            fflush(stdin);
            scanf("%s", puesto);
            printf("Ingrese el numero de horas trabajadas: ");
            scanf("%d", &hrs_trabajadas);
            if(hrs_trabajadas<0 || hrs_trabajadas>56){
                printf("Ingrese horas validas!");
                break;
            }
            else{
                printf("Ingrese el importe por hora: ");
                scanf("%f", &impxHr);
                sueldo_neto=hrs_trabajadas*impxHr;
                deduccion=sueldo_neto*0.025;
                printf("%d %s (%s) tiene un sueldo neto de: $%.2f y una deduccion de %.2f \n", clave, nombre, puesto, sueldo_neto, deduccion);
                total_sueldos+=sueldo_neto;
            }
        }
        printf("El total de sueldos a pagar es de: %.2f", total_sueldos);
    }
    else{
        printf("Ingrese un numero de trabajadores valido!");
    }

    return 0;
}