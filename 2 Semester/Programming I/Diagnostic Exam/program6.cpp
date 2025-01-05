// Author: reDragonCoder
//Write a program that handles two matrices of real numbers. The matrices are filled manually. The size of the rows and columns 
//is the same constant of size 5. The program should obtain the sum of both matrices and save the result in a third matrix.

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANTS
#define SIZE 5

//MAIN
int main(){
    //VARIABLES
    float matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result_matrix[SIZE][SIZE];
    float sum=0;

    //fill the first matrix manually
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("Enter the number in the position [%d][%d]: ", r, c);
            scanf("%f", &matrix1[r][c]);
        }
    }
    printf("\n");

    //fill the second matrix manually
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("Enter the number in the position [%d][%d]: ", r, c);
            scanf("%f", &matrix2[r][c]);
        }
    }
    printf("\n");

    //sum of the matrices
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            sum=matrix1[r][c]+matrix2[r][c];
            result_matrix[r][c]=sum;
        }
    }

    //show the first matrix
    printf("First matrix \n");
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("[%.2f]  ", matrix1[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    //show the second matrix
    printf("Second matrix \n");
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("[%.2f]  ", matrix2[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    //show the result matrix
    printf("Sum of the 2 matrices \n");
    for(int r=0; r<SIZE; r++){
        for(int c=0; c<SIZE; c++){
            printf("[%.2f]  ", result_matrix[r][c]);
        }
        printf("\n");
    }
    
    return 0;
}