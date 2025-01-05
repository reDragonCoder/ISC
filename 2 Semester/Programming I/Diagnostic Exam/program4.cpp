// Author: reDragonCoder
//Write a program that removes spaces from a string, the result is stored in another string. The string is captured character 
//by character.

//LIBRARIES
#include <stdio.h>
#include <ctype.h>

//GLOBAL CONSTANTS
#define SIZE 30

//MAIN
int main() {
    //VARIABLES
    char string[SIZE], aux_string[SIZE];
    int j=0;

    printf("Write your phrase: ");
    fgets(string, SIZE, stdin);

    //eliminate the spaces and copy the characters in the auxiliar string
    for (int i = 0; i < SIZE; i++){
        if (string[i]=='\0'){
            break;
        }
        else{
            if (!isspace(string[i])){
                aux_string[j]=string[i];
                j++; 
            }
        }
    }

    //end the auxiliar string with the null character
    aux_string[j] = '\0';

    //display the phrase without spaces
    printf("The phrase without spaces is: %s", aux_string);
    
    return 0;
}
