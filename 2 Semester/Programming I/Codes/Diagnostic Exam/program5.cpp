// Author: reDragonCoder
//Write a program that captures two strings and joins them (concatenate) leaving a '$' symbol between both strings, instead of a space. 
//The result will be stored in a third chain. It is not valid to use string.h functions.

//LIBRARIES
#include <stdio.h>

//GLOBAL CONSTANTS
#define SIZE 30
#define FINALSIZE 62

//MAIN
int main(){
    //VARIABLES
    char string1[SIZE], string2[SIZE], finalString[FINALSIZE];
    int position=0;

    //ask the user for two phrases
    printf("Write the first phrase: ");
    fgets(string1, SIZE, stdin);
    printf("Write the second phrase: ");
    fgets(string2, SIZE, stdin);

    //add the first string
    for(int i=0; i<SIZE; i++){
        if (string1[i]!='\n'){ 
            finalString[position]=string1[i];
            position++;
        } 
        else{
            break;
        }
    }

    //add the '$' symbol
    finalString[position]='$'; 
    position++;

    //add the second string
    for(int i=0; i<FINALSIZE; i++){
        if (string2[i]!='\n'){ 
            finalString[position]=string2[i];
            position++;
        }
        else{
            break;
        }
    }

    //end the final string with the null character
    finalString[position]='\0'; 

    //display the final phrase
    printf("%s", finalString);
    
    return 0;
}
