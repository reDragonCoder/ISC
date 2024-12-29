// Author: reDargonCoder

//D.A.C.E's enrollment control system maintains student information in a text file.
//The file is called �CEST.DAT�. Write a program that:
//a) Calculate the average index of the students.
//b) Calculate the number of students with a card less than 91.
//c) Calculate the number of male students with an index greater than 3.5.
//d) Given a card number, show the student's index.

//LIBRARIES
#include <iostream>

using namespace std;

//STRUCT DECLARATION
struct Student{
	int id;
	char name[50];
	float index;
	char sex;
};

//PROTOTYPES
void menu();
void fillFile(FILE*);
void showStudentsInfo(FILE*);
void averageIndex(FILE*);
void noStudentsId(FILE*);
void noMaleIndex(FILE*);
void showStudIndex(FILE*);

//MAIN
int main(){
	menu();
	return 0;
}

//IMPLEMENTATIONS
void menu(){
	FILE* cest=NULL;
	int opt;
	do{
		cout<<endl<<endl;
		cout<<"MENU"<<endl;
		cout<<"Fill students file......................................1"<<endl;
		cout<<"Students Info...........................................2"<<endl;
		cout<<"Average index...........................................3"<<endl;
		cout<<"Number of students with ID less than 91.................4"<<endl;
		cout<<"Number of male students with an index higher than 3.5...5"<<endl;
		cout<<"Student index...........................................6"<<endl;
		cout<<"Exit....................................................7"<<endl;
		cout<<"Enter your option: ";
		cin>>opt;
		switch(opt){
			case 1:
				fillFile(cest);
			break;
			case 2:
				showStudentsInfo(cest);
			break;
			case 3:
				averageIndex(cest);
			break;
			case 4:
				noStudentsId(cest);
			break;
			case 5:
				noMaleIndex(cest);
			break;
			case 6:
				showStudIndex(cest);
			break;
			case 7:
				cout<<"\nGoodbye user!";
				exit(1);
			break;
		}
	}while(opt!=7);
}

void fillFile(FILE* cest){
	cest=fopen("cest.dat", "wb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int noStudents;
	
	cout<<"How many students you want to register?: ";
	cin>>noStudents;
	
	for(int i=0; i<noStudents; i++){
		cout<<"Enter the student id: ";
		cin>>aux.id;
		cout<<"Enter the student name: ";
		cin>>aux.name;
		cout<<"Enter the student index: ";
		cin>>aux.index;
		cout<<"Enter the student sex (F or M): ";
		cin>>aux.sex;
		fwrite(&aux, sizeof(Student), 1, cest);
	}
	
	fclose(cest);
}

void showStudentsInfo(FILE* cest){
	cest=fopen("cest.dat", "rb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize;
	
	fseek(cest, 0L, SEEK_END);
	fileSize=ftell(cest)/sizeof(Student);
	fseek(cest, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest);
		printf("\n%d\t%s\t%.2f\t%c", aux.id, aux.name, aux.index, aux.sex);
	}
	
	fclose(cest);
}

void averageIndex(FILE* cest){
	cest=fopen("cest.dat", "rb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize, counter;
	float averageIndex, addition;
	
	fseek(cest, 0L, SEEK_END);
	fileSize=ftell(cest)/sizeof(Student);
	fseek(cest, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest);
		addition+=aux.index;
		counter++;
	}
	
	averageIndex=addition/counter;
	
	cout<<"\nThe average index is: "<<averageIndex;
		
	fclose(cest);
}

void noStudentsId(FILE* cest){
	cest=fopen("cest.dat", "rb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize, noStudents;
	
	fseek(cest, 0L, SEEK_END);
	fileSize=ftell(cest)/sizeof(Student);
	fseek(cest, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest);
		if(aux.id<91){
			noStudents++;
		}
	}
	
	cout<<"\nThe number of students with id less than 91 is: "<<noStudents;
		
	fclose(cest);
}

void noMaleIndex(FILE* cest){
	cest=fopen("cest.dat", "rb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize, noMale;
	
	fseek(cest, 0L, SEEK_END);
	fileSize=ftell(cest)/sizeof(Student);
	fseek(cest, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest);
		if(aux.index>3.5 && aux.sex=='M'){
			noMale++;
		}
	}
	
	cout<<"\nThe number of masculine students with index greater than 3.5: "<<noMale;
		
	fclose(cest);
}

void showStudIndex(FILE* cest){
	cest=fopen("cest.dat", "rb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize, tempId;
	
	cout<<"Enter the student id you are searching for: ";
	cin>>tempId;
	
	fseek(cest, 0L, SEEK_END);
	fileSize=ftell(cest)/sizeof(Student);
	fseek(cest, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest);
		if(aux.id==tempId){
			cout<<"\nThe index of the student with id "<<tempId<<" is "<<aux.index;	
			break;
		}
	}
		
	fclose(cest);
}
