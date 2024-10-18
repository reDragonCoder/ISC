// Author: reDragonCoder
//Matrices: llenado, mostrar, matriz diagonal, matriz nula

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CONSTANTES GLOBALES
#define MAX 5
const int TOTREN = 3;
const int TOTCOL = 4;

//MAIN
int main(){
	srand(time(NULL));
	//int matA[MAX][MAX]={{0,0,0},{0,0,0},{0,0,0}};
	int matA[MAX][MAX];
	int matB[TOTREN][TOTCOL];
	
	//matriz nula matB
	for(int i=0; i<TOTREN; i++){
		for(int j=0; j<TOTCOL; j++){
			matB[i][j]=0;    //inicializar cada posici�n de la matriz
		}
	}
	
	//mostrar matB
	printf("Matriz Nula -matB- \n");
	for(int i=0; i<TOTREN; i++){
		for(int j=0; j<TOTCOL; j++){
			printf("%d \t",matB[i][j]);
		}
		printf("\n\n");
	}
	
	//llenar matriz cuadrada matA
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			matA[i][j]=rand()%100;
		}
	}
	
	//mostrar matA
	printf("\n\n");
	printf("Matriz Cuadrada -matA- \n");
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			printf("%d \t",matA[i][j]);
		}
		printf("\n\n");
	}
	
	//matriz diagonal
	printf("\n\n");
	printf("Matriz Diagonal \n");
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			if (i==j){
				printf("%d \t",matA[i][j]);
			}
			else{
				printf("0 \t");
			}
		}
		printf("\n\n");
	}
	
	printf("\n\n");
	printf("Marco de la matriz \n");
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			if (i==0 || j==0 || i==MAX-1 || j==MAX-1){
				printf("%d \t",matA[i][j]);
			}
			else{
				printf("  \t");
			}
		}
		printf("\n\n");
	}
}


