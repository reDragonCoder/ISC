// Author: reDragonCoder
/*Escribir un programa llamado “signo”, que reciba un número real, y muestre un número entero con el valor: -1 si el número es negativo, 1 si es positivo o 0 si es cero */

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float num=0;
    int result=0;
    
    //ask for the number.
    printf("Indicate a number: ");
    scanf("%f", &num);
    
    if (num<0) {
        result=-1;
        printf("%d", result);
    }
    if (num==0) {
        result=0;
        printf("%d", result);    }
    if (num>0) {
        result=1;
        printf("%d", result);
    }
    
    printf("\n");
    
}//main
