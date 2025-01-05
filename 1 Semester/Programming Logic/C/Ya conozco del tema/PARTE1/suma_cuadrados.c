// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    float num, x, suma=0;
    for (int i=1; i<=30; i++){
        printf("Ingrese un valor positivo: ");
        scanf("%f", &num);
        if (num>0){
            x=sqrt(num);
            suma=suma+x;
        }
        else{
            printf("El valor no es positivo");
        }
    }
    printf("La sumatoria de los cuadrados es: %f", suma);
    return 0;
}