// Author: reDragonCoder
//Cuadrado de numeros con ciclos anidados

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int tam=0;
    printf("Tamano del cuadro: ");
    scanf("%d", &tam);
    //Ciclo i para indicar RENGLONES
    for(int i=1; i<=tam; i++){
        //Ciclo j para indicar COLUMNAS
        for(int j=1; j<=tam; j++){
            printf("%d ", j);
        }//j
        printf("\n");
    }
    return 0;
}