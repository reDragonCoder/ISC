// Author: reDragonCoder
//Escriba algoritmo/programa que encuentre en una lista de N números positivos el número mayor

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int n;
    float num, num_mayor=0;
    printf("Ingrese la cantidad de numeros que quiere registrar: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Ingrese un numero: ");
        scanf("%f", &num);
        if(num<0){
            printf("NO ingresaste un numero positivo");
            break;
        }
        else{
            if(num>num_mayor){
                num_mayor=num;
            }
        }
    }
    printf("El numero mayor es: %.3f", num_mayor);
    return 0;
}