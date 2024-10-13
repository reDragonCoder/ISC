// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

//MAIN
int main(){
    system("cls");

    //variables
    int height, tree_counter=0, space_counter=0;

    //ask height
    printf("Enter the height of the tree: ");
    scanf("%d", &height);

    printf("\n");

    //print tree
    for(int i=1; i<=height+1; i++){
        //calculates the number of "o"s that were printed in the current row
        tree_counter=((i)*2)-1;
        //calculates the number of spaces that were printed in the current row
        space_counter=height-i+1;
        //print spaces in current row
        for(int j=0; j<space_counter; j++){
            printf(" ");
        }
        //prints the first o of the row as a *
        if(i==1){
            printf("*");
        }
        else{
        //prints the "o's" in the current row
            for(int j=0; j<tree_counter; j++){
                printf("o");
            }
        }
  
        printf("\n");
    }
    //print the trunk of the tree (always equal to 3)
    for(int i=0; i<3; i++){
        for(int j=0; j<height; j++){
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}
