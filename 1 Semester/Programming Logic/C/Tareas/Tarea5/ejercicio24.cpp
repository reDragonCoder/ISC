// Author: reDragonCoder
//24. Escribir un programa que convierta números enteros decimales (en base 10) a sus 
//    respectivas representaciones octales (en base 8), por medio de sucesivas divisiones.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int decimal, octal=0, i=1;
    //pedir numero al usuario
    printf("Ingrese un numero decimal: ");
    scanf("%d", &decimal);
    //repetir mientas el numero decimal no sea 0
    while(decimal!=0) {
        //hacer las divisiones de 8
        octal+=(decimal%8)*i;
        decimal/=8;
        i*=10;
    }
    //mostrar el numero en octal
    printf("El numero en octal es: %d", octal);
    return 0;
}
