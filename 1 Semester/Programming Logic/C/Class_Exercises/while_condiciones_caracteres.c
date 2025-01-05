// Author: reDragonCoder
//Ejercicio de while y condiciones con caracteres
//Obtener la sumatoria de una serie de numeros, el valor 7 no lo debe sumar y debe preguntar si desea continuar

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num, suma=0;
    char resp; 
    do{
        printf("Ingrese un numero a sumar: ");
        scanf("%d", &num);
        if(num!=7){
            suma+=num;
        }
        printf("Continuar s/n: ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp!='n');
    printf("La suma de los numeros es: %d", suma);
    return 0;
}