// Author: reDragonCoder
//14. Escribir un programa que imprima una pirámide de dígitos como la de la figura, 
//    tomando como entrada el número de filas de la misma:

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variable
    int filas;
    //pedir numero de filas al usuario
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    for (int i=1; i<=filas; i++){
        //agregar los espacios en blanco para alinear el triangulo
        for (int j=1; j<=filas-i; j++){
            printf(" ");
        }
        //mostrar los numeros en orden ascendente
        for (int j=1; j<=i; j++){
            printf("%d", j);
        }
        //mostrar los numeros en orden descendente
        for (int j=i-1; j>=1; j--){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
