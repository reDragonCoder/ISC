// Author: reDragonCoder
//Program that shows numbers according to the ASCII alphabet

//LIBRARIES
#include <stdio.h>
#include <ctype.h>

//MAIN
int main(){
    //it is forced to convert A-Z to numbers (ASCII code)
    for(int i='A'; i<='Z'; i++){
        //prints the numbers A-z (ASCII code)
        printf("%d \n", i);
        //prints the letters A-Z in upper and lower case
        printf("%c \t %c \n", (char)i, tolower((char)i));
    }
    return 0;
}