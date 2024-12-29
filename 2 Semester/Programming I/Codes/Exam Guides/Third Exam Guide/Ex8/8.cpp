// Author: reDargonCoder

//Develop a program that allows us to save the CODE, NAME and NOTE of the subjects taken,
//in a file. The operations to be carried out on said file are: list the subjects that belong to
//certain department (Ex: EC, MA, CI, etc.), list the subjects in which a certain degree has been obtained
//note, and list all the subjects taken.

//LIBRARIES
#include <iostream>
#include <string.h>

using namespace std;

//PROTOTYPES
void menu();
void captureFile(FILE*);
void perDepartment(FILE*);
void perGrade(FILE*);
void allSubjects(FILE*);

//MAIN
int main(){
	menu();
	return 0;
}

//IMPLEMENTATIONS
void menu(){
	FILE* subjects=NULL;
	int opt;
	captureFile(subjects);
	do{
		cout<<endl<<endl;
		cout<<"MENU"<<endl;
		cout<<"List subjects by department...1"<<endl;
		cout<<"List subjects by grade........2"<<endl;
		cout<<"List all subjects taken.......3"<<endl;
		cout<<"Exit..........................4"<<endl;
		cout<<"Enter your option: ";
		cin>>opt;
	
		switch(opt){
			case 1:
				perDepartment(subjects);
			break;
			case 2:
				perGrade(subjects);
			break;
			case 3:
				allSubjects(subjects);
			break;	
			case 4:
				cout<<"\nGoodbye user!";
				exit(1);
			break;	
		}
	}while(opt!=4);
}

void captureFile(FILE* subjects){
	subjects=fopen("subjects.txt", "a");
	if(subjects==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int subjectsNo;
	char code[2], name[50];
	float grade;
	
	cout<<"How many subjects you want to add?: ";
	cin>>subjectsNo;
	for(int i=0; i<subjectsNo; i++){
		cout<<"Enter the subject code (2 letters): ";
		fflush(stdin);
		gets(code);
		cout<<"Enter the subject name: ";
		fflush(stdin);
		gets(name);
		cout<<"Enter the grade obtained in that subject: ";
		cin>>grade;
		fprintf(subjects, "%s\t%s\t%.2f \n", code, name, grade);
	}
	
	fclose(subjects);
}

void perDepartment(FILE* subjects){
	subjects=fopen("subjects.txt", "r");
	if(subjects==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char code[2], name[50], userCode[2];
	float grade;
	
	cout<<"Enter the subject code you want to search for: ";
	fflush(stdin);
	gets(userCode);
	
	rewind(subjects);
	while(fscanf(subjects, "%s%s%f", code, name, &grade)!=EOF){
		if(strcmp(code, userCode)==0){
			printf("\n%s\t%s\t%.2f", code, name, grade);
		}
	}
	
	fclose(subjects);
}

void perGrade(FILE* subjects){
	subjects=fopen("subjects.txt", "r");
	if(subjects==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char code[2], name[50];
	float grade;
	int userGrade;
	
	cout<<"Enter the grade you want to search for: ";
	cin>>userGrade;
	
	rewind(subjects);
	while(fscanf(subjects, "%s%s%f", code, name, &grade)!=EOF){
		if(grade==userGrade){
			printf("\n%s\t%s\t%.2f", code, name, grade);
		}
	}
	
	fclose(subjects);
}

void allSubjects(FILE* subjects){
	subjects=fopen("subjects.txt", "r");
	if(subjects==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	char code[2], name[50];
	float grade;
	
	rewind(subjects);
	while(fscanf(subjects, "%s%s%f", code, name, &grade)!=EOF){ //for not repeting the last student (EOF=End Of File)
		printf("\n%s\t%s\t%.2f", code, name, grade);
	}
	
	fclose(subjects);
}
