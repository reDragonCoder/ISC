// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int total, num, suma_par=0, suma_impar=0, prom, j=0;
    printf("Indique el numero de valores a ingresar: ");
    scanf("%d", &total);
    for(int i=1; i<=total; i++){
        printf("Ingrese el numero: ");
        scanf("%d", &num);
        if(num%2==0){
            suma_par+=num;
        }
        else{
            if(num%2!=0){
                j++;
                suma_impar+=num;
                prom=suma_impar/j;
            }
        }
    }
    printf("La suma de los valores pares es: %d\n", suma_par);
    printf("El promedio de los valores impares es: %d", prom);
    return 0;

}