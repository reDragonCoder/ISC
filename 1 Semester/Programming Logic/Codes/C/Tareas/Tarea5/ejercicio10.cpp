// Author: reDragonCoder
//10. Escribir un programa que sume los elementos de la diagonal principal de una matriz de 
//    tamaño n x n

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//MAIN
int main(){
	//inicializar los numeros aleatorios
    srand(time(NULL));
	//declarar variables
    int n;
	//pedir tamaño de la matriz al usuario (matriz cuadrada)
    printf("Ingrese el tamanio de su matriz: ");
    scanf("%d", &n);
	//declarar mas variables
    int matriz[n][n];
    int suma=0;
	//llenar la matriz con numeros aleatorios
    for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
		    matriz[i][k]=rand()%100;
		}
	}
	//mostrar la matriz
    for(int i=0; i<n; i++){
	    for(int k=0; k<n; k++){
			printf("%d \t", matriz[i][k]);
		}
		printf("\n\n");
	}
	//sumar los elementos de la diagonal de la matriz
    for(int i=0; i<n; i++){
	    for(int k=0; k<n; k++){
			if (i==k){
				suma+=matriz[i][k];
			}
		}
	}
	//mostarar la suma de los elementos de la diagonal de la matriz
    printf("La suma de los elementos de la diagnonal de la matriz es: %d", suma);
    return 0;
}