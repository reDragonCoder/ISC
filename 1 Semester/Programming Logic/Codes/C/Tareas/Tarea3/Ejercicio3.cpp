// Author: reDragonCoder
//Ejercicio 3 - Sumas consecutivas
//Pide al usuario que ingrese dos números y los sume. Después pregunta si quiere añadir otro número: si la respuesta es 
//afirmativa añádelo al total; en caso contrario finaliza el ciclo y muestra el resultado total en pantalla.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int num1, num2, num3, suma=0;
    //pedir los primeros dos numeros al usuario
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    //suma de los dos primeros numeros
    suma=num1+num2;
    //repetir mientras num3 sea diferente de 0
    while(num3!=0){
        //ingresar otro numero y sumarlo o ingresar 0 y terminar el ciclo
        printf("Si desea agregar otro numero, introduzcalo, si no, ingrese 0 \n");
        printf("Ingrese el otro numero: ");
        scanf("%d", &num3);
        //agregar el num3 a la suma
        suma+=num3;
    }
    //mostrar la suma de los numeros despues de terminar el ciclo
    printf("La suma de los numeros ingresados es: %d", suma);
    return 0;
}

 