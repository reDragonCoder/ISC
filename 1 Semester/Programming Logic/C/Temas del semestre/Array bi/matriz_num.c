// Author: reDragonCoder
//Leer y mostrar una matriz de números

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int matriz[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Ingrese un numero para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}