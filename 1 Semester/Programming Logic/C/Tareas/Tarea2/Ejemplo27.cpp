// Author: reDragonCoder
//Ejemplo 2.7
//Construya un diagrama de flujo tal que dado como datos dos variables de tipo entero, obtenga el resultado de la siguiente función:
//Si num=1 entonces val=v*100
//Si num=2 entonces val=v**100
//Si num=3 entonces val=v/100
//Para cualquier otro numero val=0

//LIBRERIAS
#include <stdio.h>
#include <math.h> //sqrt(), pow()

//MAIN
int main(){
    int num=0, v=0, val=0;
    printf("Please introduce the required option: ");
    //im assuming that the user already knows the options
    scanf("%d",&num);
    printf("Please indicate your needed value: ");
    scanf("%d",&v);
    switch (num) {
        case 1:
            val=100*v;
            break;
        case 2:
            val=pow(100, v);
            break;
        case 3:
            val=100/v;
            break;
        default:
            val=0;
            break;
    }
    printf("Your final value is: %d\n", val);
}//main
