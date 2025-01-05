// Author: reDragonCoder
//Write a program that fills a 4X4 matrix with characters randomly. Show in screen. Copy the vowels 
//from the arrangement to a vector. 

//LIBRARIES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//GLOBAL CONSTANTS
#define MAX 4

//MAIN
int main(){
    //VARIABLES
    char characters[MAX][MAX], vowels[MAX];
    int k=0;

    srand(time(NULL));
    
    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
            characters[r][c]=rand()%26+97;
        }
    }

    for(int r=0; r<MAX; r++){
        for(int c=0; c<MAX; c++){
            printf(" %c ", characters[r][c]);
            if(characters[r][c]==97 || characters[r][c]==101 || characters[r][c]==101 || characters[r][c]==111 || characters[r][c]==117){
                vowels[k]=characters[r][c];
                k++;
            }
        }
        printf("\n");
    }
    vowels[k]='\0';
    printf("\n");
    printf("The vowels in the matrix are: ");
    for(int i=0; i<k; i++){
        printf(" %c ", vowels[i]);
    }
    return 0;
}