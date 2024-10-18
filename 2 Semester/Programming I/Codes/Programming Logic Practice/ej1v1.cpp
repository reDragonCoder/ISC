// Author: reDragonCoder
//Write a program that takes the size of the side of a square and presents it as a frame.

//LIBRARIES
#include <stdio.h>

//MAIN
int main(){
    //VARIABLES
    int num=0, opc=0;

    do{
        //ask the user for a number
        printf("Enter a number: ");
        scanf("%d", &num);
        //show the frame
        for(int i=0; i<num; i++){ //rows
            for(int j=0; j<num; j++){ //columns
                if(i==0 || i==(num-1) || j==0 || j==(num-1)){ //subtract 1 from the number 
                    printf("%d ", num);
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        } 

        //ask the user if they want to continue entering numbers
        printf("Continue? yes=1, no=0: ");
        scanf("%d", &opc);
    }while(opc!=0);
    
    return 0;
}