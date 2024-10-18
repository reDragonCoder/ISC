// Author: reDragonCoder
/*Escribir un programa que rote una matriz 90 grados*/

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>//rand
#include <time.h>//time null

//CONSTANTES GLOBALES
const int PARA=4;

//MAIN
int main(){
    srand(time(NULL)); //start the rand generator
    int matrix[PARA][PARA];
    
    //fill the matrix with random numbers
    for (int r=0; r<PARA; r++) {
        for (int c=0; c<PARA; c++) {
            matrix[r][c]=rand()%11;
        }
    }
    
    //show matrix just because
    printf("Your original matrix is: \n");
    for (int r=0; r<PARA; r++) {
        for (int c=0; c<PARA; c++) {
            printf("%d\t", matrix[r][c]);
        }
        printf("\n\n");
    }
    
    
    printf("Your original matrix, but rotated by 90 degrees: \n");
    for (int r=0; r<PARA; r++) {//print all rows
        for (int c=(PARA-1); c>=0; c--) {//its like saying c=1; c<=3 but like backwards
            printf("%d\t", matrix[c][r]);//swich the position of the numbers
        }
        printf("\n\n");

    }
    
    printf("\n");
    
}//main
