// Author: reDragonCoder
//Un programa que contengas las siguientes opciones dentro de un menu :
//captura matriz y mostrarla, multiplicar por un numero la matriz, obtener la suma de alguna fila, 
//obtener la suma de alguna columna, obtener la suma de todos los datos de la matriz, capturar una matriz de tamaño 5 x 5 y mostrar,
//capturar y mostrar la matriz de cualquier matriz de orden M x N, obtener la suma de dos matrices de orden M x N,
//lea un arreglo de M filas y M columnas y que calcule la suma de los elementos de la diagonal principal y
//determinar si una matriz es de tipo diagonal: es una matriz cuadrada en la cual todos 
//sus elementos son cero, excepto los electos de la diagonal principal 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int opc;
    int filas, columnas;
    int matriz1[3][3];
    printf("MENU DE MATRICES \n");
    printf("--------------------------------------- \n");
    printf("1) Capturar matriz y mostrarla \n");
    printf("2) Multiplicar la matriz por un numero \n");
    printf("3) Obtener la suma de alguna fila de la matriz \n");
    printf("4) Obtener la suma de alguna columna de la matriz \n");
    printf("5) Obtener la suma de todos los datos de la matriz \n");
    printf("6) Capturar una matriz de 5x5 y mostrarla \n");
    printf("7) Capturar y mostrar cualquier matriz de orden MxN \n");
    printf("8) Obtener la suma de dos matrices de orden MxN \n");
    printf("9) Leer un arreglo de M filas y N columnas y calcular la suma de los elementos de la diagonal principal \n");
    printf("10) Determinar si una matriz es de tipo diagonal (es decir, matriz cuadrada en la cual todos sus elementos son cero, excepto la diagonal principal) \n");
    printf("--------------------------------------- \n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opc);
    switch(opc){
        case 1:
            printf("Ingrese el numero de filas de su matriz: ");
            scanf("%d", &filas);
            printf("Ingrese el numero de columnas de su matriz: ");
            scanf("%d", &columnas);
            for(int i=0; i<filas; i++){
                for(int j=0; j<columnas; j++){
                    printf("Ingrese un valor en la posicion [%d][%d]: ", i, j);
                    scanf("%d", &matriz1[i][j]);
                }   
            }
            printf("\n");
            for(int i=0; i<filas; i++){
                for(int j=0; j<columnas; j++){
                    printf("%d", matriz1[i][j]);
                    printf("\t");
                }
                printf("\n");
            }
        break;
        case 2:
    
        break;
    }

    return 0;
}
