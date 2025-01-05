// Author: reDragonCoder
//Create a program that inputs a string of characters, which will be inverted by transforming capital letters 
//in lower case and vice versa, the inverted string will be the result of the program. It may or may not use the
// functions contained in string.h or ctype.h.

//LIBRARIES
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//GLOBAL CONSTANT
#define SIZE 30

//MAIN
int main(){
    //VARIABLES
    char orgString[SIZE], invString[SIZE];
    int length=0;

    printf("Enter your string: ");
    scanf("%[^\n]", orgString); //it captures the string until an \n appears
    length=strlen(orgString);
    for(int i=0; i<length; i++){
        if(islower(orgString[i])){
            invString[i]=toupper(orgString[i]);
        }else if(isupper(orgString[i])){
            invString[i]=tolower(orgString[i]);
        }else{
            invString[i]=orgString[i];
        }
    }
    invString[length+1]='\0';
    strrev(invString);
    printf("Your inverted string is: %s", invString);
    
    return 0;
}