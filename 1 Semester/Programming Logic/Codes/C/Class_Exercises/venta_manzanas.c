// Author: reDragonCoder
//Determinar cuanto pagará una persona que compre manzanas 
//en esa frutería.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float numKilos=0, costoXkilo=0, totalPagar=0;
    printf("Cuantos kilos compraste? ");
    scanf("%f", &numKilos);
    printf("Costo por kilo: ");
    scanf("%f", &costoXkilo);
    if(numKilos>=0){ //si el valor es mayor a cero se puede hacer el sig. codigo
        //Evaluar cada uno de los rangos que pide el ejercicio
        if(numKilos>=0 && numKilos<=2){
            totalPagar = costoXkilo * numKilos;
        }
        if(numKilos>=2.01 && numKilos<=5){
            totalPagar = (costoXkilo * numKilos)*0.9;
        }
        if(numKilos>=5.01 && numKilos<=10){
            totalPagar = (costoXkilo * numKilos)*0.85;
        }
        if(numKilos>=10.01){
            totalPagar = (costoXkilo * numKilos)*0.9;
        }
        printf("Total $: %.2f", totalPagar);
    }
    else{ //cuando los valores son negativos
        printf("Ingrese numeros positivos");
    }
    return 0;
}