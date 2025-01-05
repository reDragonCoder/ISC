// Author: reDragonCoder
//Write a program that captures two strings and compare them. It is not valid to use the function string.h. The program must display
//0 if the strings are equal. Display -1 if the first string is bigger (in terms of characters) or display 1 if the second string is
//bigger.

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANTS
#define SIZE 30

//MAIN
int main(){
    //VARIABLES
    char string1[SIZE], string2[SIZE];
    int counter1=0, counter2=0;

    //ask the user for two phrases
    printf("Write your first phrase: ");
    fgets(string1, SIZE, stdin);
    printf("Write your second phrase: ");
    fgets(string2, SIZE, stdin);

    //count the number of characters in the first string
    for(int i=0; i<SIZE; i++){
        counter1++;
        if(string1[i]=='\0'){
            break;
        }
    }

    //count the number of characters in the second string
    for(int i=0; i<SIZE; i++){
        counter2++;
        if(string2[i]=='\0'){
            break;
        }
    }
    printf("\n\n");

    //evaluate the strings status (equal or bigger than the other one)
    if(counter1==counter2){
        printf("Strings status: 0 (they're equal)");
    }
    else{
        if(counter1>counter2){
            printf("Strings status: -1 (string 1 is bigger)");
        }
        else{
            printf("String status: 1 (string 2 is bigger)");
        }
    }
    
    return 0;
}