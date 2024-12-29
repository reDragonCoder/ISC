// Author: reDargonCoder

//There is a file whose records have the following structure: Name, Age, Sex. You want to elaborate
//a program that lists all women who are older than X age inside the file. The file name is given by the user.
#include <iostream>
#include <string.h>

using namespace std;

//STRUCT DECLARATION
struct Patient{
    char name[25];
    int age;
    char sex;
}; 

//PROTOTYPES
void fillFile(FILE*);
void addWomen(char*, FILE*, FILE*, int);
void showWomen(char*, FILE*);
int captureXage();
char* captureFileName();

//MAIN
int main(){
    FILE* patients=NULL;
    FILE* women=NULL;
    int age=0;
    char* name;
    fillFile(patients);
    age=captureXage();
    name=captureFileName();
    addWomen(name, patients, women, age);
    showWomen(name, women);
    delete[] name;
    return 0;
}

//IMPLEMENTATIONS
void fillFile(FILE* patients){
	Patient aux;
	patients=fopen("patients.dat", "ab");
	if(patients==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int patientsNo;
	
	cout<<"How many patients you want to register?: ";
	cin>>patientsNo;
	
	for(int i=0; i<patientsNo; i++){
		cout<<"Enter the patient name: ";
		cin>>aux.name;
		cout<<"Enter the patient age: ";
		cin>>aux.age;
		cout<<"Enter the patient sex (F or M): ";
		cin>>aux.sex;
		fwrite(&aux, sizeof(Patient), 1, patients);
	}
	
	fclose(patients);
}

int captureXage(){
    int age;
    cout<<"Enter the age from which you want to search: ";
    fflush(stdin);
    cin>>age;
    return age;
}

char* captureFileName(){
    char* fileName=new char[20];
    cout<<"Enter your new file name: ";
    cin>>fileName;
    strcat(fileName, ".dat");
    return fileName;
}

void addWomen(char* name, FILE* patients, FILE* women, int age){
    Patient temp;
    int fileSize;
    patients=fopen("patients.dat", "rb");
    women=fopen(name, "w");
    if(patients==NULL || women==NULL){
        cout<<"ERROR";
        exit(1);
    }

    fseek(patients, 0L, SEEK_END);
    fileSize=ftell(patients)/sizeof(Patient);
    fseek(patients, 0L, SEEK_SET);
    for(int i=0; i<fileSize; i++){
    	fread(&temp, sizeof(Patient), 1, patients);
		if((temp.age>=age) && (temp.sex=='F')){
	    	fwrite(&temp, sizeof(Patient), 1, women);
		}	
	}

    fclose(patients); 
    fclose(women);
}

void showWomen(char*name, FILE* women){
	Patient female;
	int fileSize;
	women=fopen(name, "rb");
	if(women==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	fseek(women, 0L, SEEK_END);
	fileSize=ftell(women)/sizeof(Patient);
	fseek(women, 0L, SEEK_SET);
	for(int i=0; i<fileSize; i++){
		fread(&female, sizeof(Patient), 1, women);
		printf("\n%s\t%d\t%c", female.name, female.age, female.sex);
	}
	
	fclose(women);
}
