// Author: reDragonCoder
//N numeros aleatorios contar y obtener promedio

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//MAIN
int main(){
    srand(time(NULL));
    int num=0, par=0, impar=0, valorN=0, suma=0;
    float prom=0;
    printf("Dame el total de valores a generar: ");
    scanf("%d", &valorN);
    for(int i=1; i<=valorN; i++){
        num=rand()%101;
        printf("%d \t", num);
        if(num==7){
            continue;
        }
        if(num%2==0){
            par++;
        }
        else{
            impar++;
            suma+=num;
        }
    }
    prom=suma/impar;
    printf("\n Total de pares: %d \n", par);
    printf(" Promedio de impares: %.2f \n", prom);
    return 0;
}