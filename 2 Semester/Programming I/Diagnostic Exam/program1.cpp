// Author: reDragonCoder
//Write a program that handles a vector of integers. The vector is randomly filled with values containing 2 digits.
//The size of the vector is a constant declared with the word const and has size 100. The program must obtain and 
//display on the screen the sum, the average and the smallest of the elements.

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//GLOBAL CONSTANTS
const int SIZE=100;

//MAIN
int main(){
    //VARIABLES
    int vector[SIZE];
    int num=0, aux_smallest=0, smallest=0;
    float sum=0, average=0;

    //initialize random numbers
    srand(time(NULL));
    
    //fill the vector with random numbers (2 digits)
    for(int i=0; i<SIZE; i++){
        num=rand()%90+10;
        vector[i]=num;
        //evaluate the smallest number
        aux_smallest=vector[0];
        if(vector[i]<aux_smallest){
            smallest=vector[i];
        }
        //sum of the values
        sum+=vector[i];
        //print the vector
        printf("%d  ", vector[i]);
    }

    printf("\n \n");
    //print the sum 
    printf("The sum of the elements in the vector is: %.0f \n", sum);
    //calculate the average
    average=sum/SIZE;
    //print the average
    printf("The average of the elements in the vector is: %.2f \n", average);
    //print the smallest number
    printf("The smallest element in the vector is: %d", smallest);

    return 0;
}