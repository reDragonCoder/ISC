// Author: reDragonCoder
/*Escribir un programa que dado un tablero de 3x3 relleno con números enteros, crear un programa que compruebe si todos los números están entre 1 y 9 (ambos inclusive) y que ninguno se repite..*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int matrix[3][3];
    int m=0, same=0;
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            matrix[i][j]=0; //we are filling the matrix with 0's
        }
    }

    
    //fill the matrix with numbers given by the user
    printf("Fill the matrix! The numbers must be between 1 and 9, and must not repeat!\n");
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            printf("Insert a number: ");
            scanf("%d", &matrix[r][c]);
            if (matrix[r][c]!=same) {
                matrix[r][c]=same; //start the duplicate search
            }
        }
    }
    
    //check taht the numbers are within range
     for (int r=0; r<3; r++) {
         for (int c=0; c<3; c++) {
             if (matrix[r][c]<1 || matrix[r][c]>9) {
                 m=1;//the numbers are NOT within range
             }
         }
     }
    
    //check that there are NO duplicates
    for (int r=0; r<3; r++) {
        for (int c=0; c<3; c++) {
            if (matrix[r][c]==same) {
                m=1;//numbers have duplicates
            }
        }
    }
  
    //ik im using m as a flag, let me live 
    if (m==0) {
        //show matrix if all teh criteria is met with
        printf("Your original matrix is: \n");
        for (int r=0; r<3; r++) {
            for (int c=0; c<3; c++) {
                printf("%d\t", matrix[r][c]);
            }
            printf("\n\n");
        }
    }
    if (m>0) {
        printf("You're values are incorrect! Please follow the instructions \n");

    }
    
}//main
