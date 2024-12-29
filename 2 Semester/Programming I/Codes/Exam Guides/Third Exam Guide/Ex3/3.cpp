// Author: reDargonCoder

//Write a program that creates a character file with lines of fixed size 80, from a file
//(also text) that contains lines of variable size between 1 and 80 characters. For this the file
//created is filled with blanks in the lines with size less than 80.

//LIBRARIES
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//PROTOTYPES
char* captureFileName();
void fixedFile(FILE*, FILE*, char*);

//MAIN
int main(){
	char* name;
	FILE* fixed=NULL;
	FILE* variable=NULL;
	name=captureFileName();
    fixedFile(variable, fixed, name);
    cout<<"Creating file...\n";
    cout<<"Check your files";
	delete[] name;
	return 0;
}

//IMPLEMENTATIONS
char* captureFileName(){
    char* fileName=new char[20];
    cout<<"Enter your file name: ";
    cin>>fileName;
    strcat(fileName, ".txt");
    return fileName;
}

void fixedFile(FILE* variable, FILE* fixed, char* name){
	variable=fopen("80char.txt", "r");
	fixed=fopen(name, "w");
	
	if(variable==NULL || fixed==NULL) {
        cout<<"ERROR";
        exit(1);
    }
    
    char line[300]; 
    while (fgets(line, sizeof(line), variable) != NULL) {
        int length=strlen(line);
        if(length>=80){
            fprintf(fixed, "%.*s\n", 80, line);
            fprintf(fixed, "%-80s\n", line+80);
        }else{
            fprintf(fixed, "%-80s\n", line);
        }
    }
	
	fclose(variable);
	fclose(fixed);
}




