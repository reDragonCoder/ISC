// Author: reDragonCoder
//Solucion de la formula general 

//LIBRERIAS
#include <stdio.h> //printf, scanf
#include <math.h> //pow, sqrt

//MAIN
int main(){
    //variables
    float x1=0, datoA=0, datoB=0, datoC=0;
    printf("Ingrese el valor de a: ");
    scanf("%f", &datoA);
    printf("Ingrese el valor de b: ");
    scanf("%f", &datoB);
    printf("Ingrese el valor de c: ");
    scanf("%f", &datoC);
    x1=((-datoB)-sqrt(pow(datoB, 2)-(4*datoA*datoC)))/(2*datoA);
    printf("x1 = %.2f", x1);
    return 0; 
} //main