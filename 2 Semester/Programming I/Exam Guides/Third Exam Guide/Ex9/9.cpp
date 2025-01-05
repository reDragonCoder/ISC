// Author: reDargonCoder

//Write a program that receives a file name as input and creates a copy.dat file with
//the content thereof.

//LIBRARIES
#include <iostream>
#include <string.h>

using namespace std;

//PROTOTYPES
char* captureFileName();
void fillFile(FILE*, char*);
void createCopy(FILE*, FILE*, char*);

//MAIN
int main(){
    FILE* userFile=NULL;
    FILE* copy=NULL;
    char* fileName;
    
    fileName=captureFileName();
    fillFile(userFile, fileName);
    createCopy(userFile, copy, fileName);
    
    cout<<"\nCreating file copy...\n";
    cout<<"Check your files";
    
    delete[] fileName;
    
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

void fillFile(FILE* userFile, char* fileName){
	userFile=fopen(fileName, "a");
	if(userFile==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char line[500];
	int lineNo;
	cout<<"How many lines you want to write?: ";
	cin>>lineNo;
	
	for(int i=0; i<lineNo; i++){
		cout<<"Enter your "<<i+1<<" line: ";
		fflush(stdin);
		gets(line);
		fputs(line, userFile);
		fputs("\n", userFile);
	}
	
	fclose(userFile);
}

void createCopy(FILE* userFile, FILE* copy, char* fileName){
	userFile=fopen(fileName, "r");
	copy=fopen("copy.dat", "ab");
	if(userFile==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char line[500];
	while(fgets(line, sizeof(line), userFile)){
		fputs(line, copy);
	}
	
	fclose(userFile);
	fclose(copy);
}

