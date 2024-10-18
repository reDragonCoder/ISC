// Author: reDragonCoder
//18. Escribir un programa que determine si una matriz es simétrica.

//LIBRERIAS
#include <stdio.h>
#include <stdbool.h>

//MAIN
int main(){
    //declarar variables
    int matriz[3][3];
    bool simetria=true;
    //pedir datos al usuario
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Ingrese un numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
    //mostrar la matriz
    printf("Matriz: \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    //comprobar si es simetrica
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (matriz[i][j]!=matriz[j][i]) { 
                simetria=false;
                break;
            }
        }
        if(!simetria){
            break;
        }
    }
    //mostrar si es simetrica o no
    if(simetria){
        printf("La matriz es simetrica");
        return 0;
    }
    else{
        printf("La matriz NO es simetrica");
    }
    return 0;
}
