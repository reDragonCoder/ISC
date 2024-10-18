// Author: reDragonCoder
//12. Escribir un programa que muestre por pantalla los cuadrados de los 100 primeros 
//    números enteros. 

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //declarar variable
    int num=0;
    //ciclo para realizar la operacion con los 100 primeros numeros enteros
    for(int i=1; i<=100; i++){
        //elevar el numero i al cuadrado
        num=pow(i, 2);
        //mostrar el numero elevado al cuadrado
        printf("%d \n", num);
    }
    return 0;
}