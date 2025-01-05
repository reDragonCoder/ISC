// Author: reDragonCoder
//Terminal example

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//NAMESPACE
using namespace std;

//MAIN
int main(int argc, char *argv[]){ //the arguments arrive from the terminal
    //VARIABLES
    long int addition=0;

    for(int i=0; i<argc; i++){
        if(isdigit(*argv[i])){
            addition+=strtol(argv[i], NULL, 0);
        }
    }

    //strtol --> variable to vconvert, pointer, base to convert (3 parameters) - 0(decimal), 2(binary), 8(octal), 16(hexadecimal)
    cout<<"Addition: "<<addition<<endl;
    
}
