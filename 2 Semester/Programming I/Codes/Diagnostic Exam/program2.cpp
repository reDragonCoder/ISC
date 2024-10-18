// Author: reDragonCoder
//Write a program that handles a matrix of float numbers. The matrix is filled manually. The row and column size is a constant equal to 5.
//The program must obtain the multiplication of a matrix by a scalar. The scalar value is a constant equal to 2.

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANTS
const int SIZE=5, SCALAR=2;

//MAIN
int main(){
    //VARIABLES
    float matrix[SIZE][SIZE];

    //fill the matrix
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("Enter the value of the position [%d][%d]: ", r, c);
            scanf("%f", &matrix[r][c]);
        }
    }

    //show the matrix
    printf("\n");
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("[%.2f]    ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n\n");

    //multiplicate the matrix by the scalar and show it
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            matrix[r][c]*=SCALAR;
            printf("[%.2f]    ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}