// Author: reDargonCoder

//Write a program that, given the names of two character files, makes a mixture of the two
//in a new file, with the condition that the lines are interspersed. The name of the new file is
//given as a parameter.
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//PROTOTYPES
char* captureFileName();
void mixFiles(char*, FILE*, FILE*, FILE*);

//MAIN
int main(){
    char* name;
    FILE *file1=NULL;
    FILE *file2=NULL;
    FILE *file3=NULL;
    name=captureFileName();
    mixFiles(name, file1, file2, file3);
    cout<<"\nCreating mixed file..."<<endl;
    cout<<"\nCheck your file";
    delete[] name;
    return 0;
}

//IMPLEMENTATIONS
char* captureFileName(){
    char* fileName=new char[20];
    cout<<"Enter your new file name: ";
    cin>>fileName;
    strcat(fileName, ".txt");
    return fileName;
}

void mixFiles(char* name,  FILE* file1, FILE* file2, FILE*file3){
    file1=fopen("text1.txt", "r");
    file2=fopen("text2.txt", "r");
    file3=fopen(name, "a");
    if(file1==NULL || file2==NULL || file3==NULL){
		cout<<"ERROR TYPE: OPENING/CREATING FILE! \n";
		exit(1);
	}

  	//mixing logic
  	char line1[1000];
    char line2[1000];
    while(fgets(line1, sizeof(line1), file1) && fgets(line2, sizeof(line2), file2)){
        fputs(line1, file3);
        fputs(line2, file3);
    }

    while(fgets(line1, sizeof(line1), file1)){
        fputs(line1, file3);
    }
    while (fgets(line2, sizeof(line2), file2)){
        fputs(line2, file3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
}
