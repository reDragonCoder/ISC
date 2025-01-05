// Author: reDragonCoder
//EJERCICIO 2: Construya un diagrama de flujo tal que dado como datos los valores enteros P y
//Q, determine si los mismos satisfacen la siguiente expresión: P5 + Q 4- 2*P2 < 680
//En caso afirmativo debe imprimir los valores P y Q.

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //Declarar variables
    int p, q;
    float exp=0;
    //Pedir datos al usuario
    printf("Ingrese el primer valor (p): ");
    scanf("%d", &p);
    printf("Ingrese el segundo valor (q): ");
    scanf("%d", &q);
    //Realizar el calculo de la expresion
    exp=pow(p,3)+pow(q,4)-(2*pow(p,2));
    //Evaluar el resultado
    if(exp<680){
        //Mostrar resultado de que si satisface una expresion
        printf("%d y %d satisfacen una expresion", p, q);
    }
    else{
        //Mostar el resultado de que no satisface una expresion
        printf("Los valores %d y %d NO satisfacen una expresion", p, q);
    }
    return 0;
}

//Se cambiaron las variables de mayúscula a minúscula porque no son constantes
//Se agregó un else para avisar que los valores p y q no satisfacen una expresión