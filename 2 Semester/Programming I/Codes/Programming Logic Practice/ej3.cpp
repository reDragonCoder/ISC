// Author: reDragonCoder
//Write a program that fills a 5x5 matrix with random numbers and get: the sum of the rows, the 
//average of each column, the percentage of the pair numbers and show the result next to the matrix in the screen

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//GLOBAL CONSTANT
# define MAX 5

//MAIN
int main(){
    //VARIABLES
    int matrix[MAX][MAX];
    int sum_row=0, row=0, pairs=0;
    float average1=0, average2=0, average3=0, average4=0, average5=0, pairs_percentage=0;

    //initialize random numbers
    srand(time(NULL));

    //fill the matrix with random numbers
    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
            matrix[r][c]=rand()%10;
            //show the matrix
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    //show the sum of the rows 
    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
        sum_row+=matrix[r][c];
            if(c==(MAX-1)){
                row=r+1;
                printf("The sum of the row %d is %d", row, sum_row);
            }
        }
        sum_row=0;
        printf("\n");
    }
    printf("\n");

    //show the average of each column
    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
            if(c==0){
                average1+=matrix[r][c];
            }else{
                if(c==1){
                    average2+=matrix[r][c];
                }else{
                    if(c==2){
                        average3+=matrix[r][c];
                    }else{
                        if(c==3){
                            average4+=matrix[r][c];
                        }else{
                            if(c==4){
                                average5+=matrix[r][c];
                            }
                        }
                    }
                }
            }
        }
    }
    average1/=MAX;
    printf("The average of the [1] column is: %.2f \n", average1);
    average2/=MAX;
    printf("The average of the [2] column is: %.2f \n", average2);
    average3/=MAX;
    printf("The average of the [3] column is: %.2f \n", average3);
    average4/=MAX;
    printf("The average of the [4] column is: %.2f \n", average4);
    average5/=MAX;
    printf("The average of the [5] column is: %.2f \n", average5);

    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
            if((matrix[r][c]%2==0) && (matrix[r][c]!=0)){
                pairs++;
            }
        }
    }
    pairs_percentage=(pairs*100)/25;
    printf("\n");
    printf("The percentage of pairs in the matrix is: %.2f percent", pairs_percentage);

    return 0;
}


