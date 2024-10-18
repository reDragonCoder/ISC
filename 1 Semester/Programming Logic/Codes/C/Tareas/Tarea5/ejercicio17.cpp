// Author: reDragonCoder
/*Escribir un programa que calcule la matriz transpuesta de una matriz bidimensional cuadrada de tamaño M. El tamaño de la matriz y su contenido se leerá por teclado.*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int m=0;
    int matrix[m][m];
   
    //parameters of matrix
    printf("What size would you like your matrix to be?: ");
    scanf("%d", &m);
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            matrix[i][j]=0; //we are filling the matrix with 0's
        }
    }
    
    //fill the matrix with numbers given by the user
    printf("Fill the matrix! \n");
    for (int r=0; r<m; r++) {
        for (int c=0; c<m; c++) {
            printf("Insert a number: ");
            scanf("%d", &matrix[r][c]);
        }
    }
    
    //show matrix just because
    printf("Your original matrix is: \n");
    for (int r=0; r<m; r++) {
        for (int c=0; c<m; c++) {
            printf("%d\t", matrix[r][c]);
        }
        printf("\n\n");
    }
    
    
    printf("Your original matrix, but rotated by 90 degrees: \n");
    for (int r=0; r<m; r++) {//print all rows
        for (int c=0; c<m; c++) {//its like saying c=1; c<=3 but like backwards
            printf("%d\t", matrix[c][r]);//swich the position of the numbers
        }
        printf("\n\n");

    }
    
    printf("\n");
    
}//main
