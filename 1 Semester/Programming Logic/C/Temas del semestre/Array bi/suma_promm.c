// Author: reDragonCoder
//Calcular la suma y el promedio de los elementos de una matriz

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int matriz[3][3], suma=0;
    float prom=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Ingrese el valor de la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            suma+=matriz[i][j];
        }
    }
    prom=suma/9;
    printf("La suma es: %d\n", suma);
    printf("El promedio es %.2f", prom);
    return 0;
}