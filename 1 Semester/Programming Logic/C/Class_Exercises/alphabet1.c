// Author: reDragonCoder
//Program that displays the letters of the alphabet in uppercase and lowercase

//LIBRARIES
#include <stdio.h>
#include <ctype.h>

//MAIN
int main(){
    //The ASCII alphabet is 65 to 90.
    for(int i=65; i<=90; i++){
        //prints the letters A-Z(65-90) in upper and lower case
        printf("%c \t %c \n", (char)i, tolower((char)i));
    }
    return 0;
}