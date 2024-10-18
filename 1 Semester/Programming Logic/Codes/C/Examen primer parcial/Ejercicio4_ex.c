// Author: reDragonCoder
//Ejercicio 4

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int datoA;
    
    printf("Ingrese el dato de A: ");
    scanf("%d", &datoA);
    if(datoA%4==0){
        if(datoA%100==0){
            if(datoA%400==0){
                printf("%d es bisiesto", datoA);
            }
            else{
                printf("%d no es bisiesto", datoA);
            }
        }
        else{
            printf("%d es bisiesto", datoA);
        }
    }
    else{
        printf("%d no es bisiesto", datoA);
    }
    return 0;
}