// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int n, num, suma=0;
    printf("Ingrese el numero de datos: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        printf("Ingrese un numero entero: ");
        scanf("%d", &num);
        if (num>0) {
            suma+=num;
        }
    }
    printf("La suma de los valores positivos fue de: %d", suma);
    return 0;
}