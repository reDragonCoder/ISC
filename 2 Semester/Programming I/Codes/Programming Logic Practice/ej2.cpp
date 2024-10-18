// Author: reDragonCoder
//Write a program that takes an integer and prints a square for each digit of the number.

//LIBRARIES
#include <stdio.h>

//MAIN
int main(){
    //VARIABLES
    int num=0, digit=0;

    //ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &num);

    //divide the number and print the frame of each digit
    while(num!=0){
        digit=num%10;
        //show the frames
        for(int i=0; i<digit; i++){ //rows
            for(int j=0; j<digit; j++){ //columns
                if(i==0 || i==(digit-1) || j==0 || j==(digit-1)){ //subtract 1 from the number 
                    printf("%d ", digit);
                }
                else{
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
        num/=10;
    }
    
    return 0;
}