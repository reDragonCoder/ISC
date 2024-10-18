// Author: reDragonCoder
/*Escribir un programa que calcule el cubo de un número real (float). El valor del numero lo recibe como parámetro. El resultado deberá ser otro número real y devolverse con un return. */

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float num=0, numAux=0;
    
    //ask for the number
    printf("What number would you like to elevate: ");
    scanf("%f", &num);
    
    //cube the number
    numAux= num * num * num;
   
    //return with decimals
    printf("You're final number is: %0.3f\n", numAux);
    
    return 0;
    
}//main
