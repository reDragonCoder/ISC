// Author: reDargonCoder

//With the above student welfare file format you want to get �CEST1.DAT�, �CEST2.DAT�,
//�CEST3.DAT�, �CEST4.DAT� such that:
//a) �CEST1.DAT� contains the information of male students with a 90 card with an index greater than or equal to 3.50
//b) �CEST2.DAT� contains the information of the students with an index greater than 4.25 who entered after the year 92
//c) �CEST3.DAT� contains the names of the students 94 whose last names begin with A and B.
//d) �CEST4.DAT� contains the ID cards of students named Jos� and who have an index higher than 4.00

//LIBRARIES
#include <iostream>
#include <string.h>

using namespace std;

//STRUCT DECLARATION
struct Student{
	int id;
	int year;
	char name[30];
	char lastName[30];
	float index;
	char sex;
};

//PROTOTYPES
void menu();
void fillCest(FILE*);
void showCest(FILE*);
void fillCest1(FILE*, FILE*);
void showCest1(FILE*);
void fillCest2(FILE*, FILE*);
void showCest2(FILE*);
void fillCest3(FILE*, FILE*);
void showCest3(FILE*);
void fillCest4(FILE*, FILE*);
void showCest4(FILE*);

//MAIN
int main(){
	menu();
	return 0;
}

//IMPLEMENTATIONS
void menu(){
	FILE* cest=NULL;
	FILE* cest1=NULL;
	FILE* cest2=NULL;
	FILE* cest3=NULL;
	FILE* cest4=NULL;
	int opt;
	do{
		cout<<endl<<endl;
		cout<<"MENU"<<endl;
		cout<<"Fill CEST - data file.....................................................................1"<<endl;
		cout<<"Show CEST - data file.....................................................................2"<<endl;
		cout<<"Show CEST1 - masculine students info of year 90 with index equal or grater than 3.5.......3"<<endl;
		cout<<"Show CEST2 - students info with index greater than 4.25 that entered after year 92........4"<<endl;
		cout<<"Show CEST3 - female students name from year 94 with last names that starts with A or B ...5"<<endl;
		cout<<"Show CEST4 - students id with 'Jose' name and index greater than 4.0......................6"<<endl;
		cout<<"Exit......................................................................................7"<<endl;
		cout<<"Enter your option: ";
		cin>>opt;
		switch(opt){
			case 1:
				fillCest(cest);
			break;
			case 2:
				showCest(cest);
			break;
			case 3:
				fillCest1(cest, cest1);
				showCest1(cest1);
			break;
			case 4:
				fillCest2(cest, cest2);
				showCest2(cest2);
			break;
			case 5:
				fillCest3(cest, cest3);
				showCest3(cest3);
			break;
			case 6:
				fillCest4(cest, cest4);
				showCest4(cest4);
			break;
			case 7:
				cout<<"\nGoodbye user!";
				exit(1);
			break;
		}
	}while(opt!=7);
}

void fillCest(FILE* cest){
	cest=fopen("cest.dat", "wb");
	if(cest==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int noStudents;
	
	cout<<"Enter the number of students you want to register: ";
	cin>>noStudents;
	
	for(int i=0; i<noStudents; i++){
		cout<<"Enter the students ID: ";
		cin>>aux.id;
		cout<<"Enter the students entry year: ";
		cin>>aux.year;
		cout<<"Enter the students name: ";
		cin>>aux.name;
		cout<<"Enter the students last name: ";
		cin>>aux.lastName;
		cout<<"Enter the students index: ";
		cin>>aux.index;
		cout<<"Enter the students sex (F or M): ";
		cin>>aux.sex;
		fwrite(&aux, sizeof(Student), 1, cest);
	}
	
	fclose(cest);
}

void showCest(FILE* cest){
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
		printf("\n%d\t%d\t%s\t%s\t%.2f\t%c", aux.id, aux.year, aux.name, aux.lastName, aux.index, aux.sex);
	}
	
	fclose(cest);
}

void fillCest1(FILE* cest, FILE* cest1){
	cest=fopen("cest.dat", "rb");
	cest1=fopen("cest1.dat", "wb");
	if(cest==NULL || cest1==NULL){
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
		if((aux.sex=='M' || aux.sex=='m') && (aux.year==90) && (aux.index>=3.5)){
			fwrite(&aux, sizeof(Student), 1, cest1);
		}
	}
	
	fclose(cest);
	fclose(cest1);
}

void showCest1(FILE* cest1){
	cest1=fopen("cest1.dat", "rb");
	if(cest1==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize;
	
	fseek(cest1, 0L, SEEK_END);
	fileSize=ftell(cest1)/sizeof(Student);
	fseek(cest1, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest1);
		printf("\n%d\t%d\t%s\t%s\t%.2f\t%c", aux.id, aux.year, aux.name, aux.lastName, aux.index, aux.sex);
	}
	
	fclose(cest1);
}

void fillCest2(FILE* cest, FILE* cest2){
	cest=fopen("cest.dat", "rb");
	cest2=fopen("cest2.dat", "wb");
	if(cest==NULL || cest2==NULL){
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
		if((aux.index>4.25) && (aux.year>92)){
			fwrite(&aux, sizeof(Student), 1, cest2);
		}
	}
	
	fclose(cest);
	fclose(cest2);
}

void showCest2(FILE* cest2){
	cest2=fopen("cest2.dat", "rb");
	if(cest2==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize;
	
	fseek(cest2, 0L, SEEK_END);
	fileSize=ftell(cest2)/sizeof(Student);
	fseek(cest2, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest2);
		printf("\n%d\t%d\t%s\t%s\t%.2f\t%c", aux.id, aux.year, aux.name, aux.lastName, aux.index, aux.sex);
	}
	
	fclose(cest2);
}

void fillCest3(FILE* cest, FILE* cest3){
	cest=fopen("cest.dat", "rb");
	cest3=fopen("cest3.dat", "wb");
	if(cest==NULL || cest3==NULL){
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
		if(((aux.sex=='F') || (aux.sex=='f')) && ((aux.lastName[0]=='a') || (aux.lastName[0]=='A') || (aux.lastName[0]=='b') || (aux.lastName[0]=='B')) && (aux.year==94)){
			fwrite(&aux, sizeof(Student), 1, cest3);
		}
	}
	
	fclose(cest);
	fclose(cest3);
}

void showCest3(FILE* cest3){
	cest3=fopen("cest3.dat", "rb");
	if(cest3==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize;
	
	fseek(cest3, 0L, SEEK_END);
	fileSize=ftell(cest3)/sizeof(Student);
	fseek(cest3, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest3);
		printf("\n%s\t%s", aux.name, aux.lastName);
	}
	
	fclose(cest3);
}

void fillCest4(FILE* cest, FILE* cest4){
	cest=fopen("cest.dat", "rb");
	cest4=fopen("cest4.dat", "wb");
	if(cest==NULL || cest4==NULL){
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
		if(((strcmp(aux.name, "jose")==0) || (strcmp(aux.name, "Jose")==0) || (strcmp(aux.name, "JOSE")==0)) && (aux.index>4)){
			fwrite(&aux, sizeof(Student), 1, cest4);
		}
	}
	
	fclose(cest);
	fclose(cest4);
}

void showCest4(FILE* cest4){
	cest4=fopen("cest4.dat", "rb");
	if(cest4==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Student aux;
	int fileSize;
	
	fseek(cest4, 0L, SEEK_END);
	fileSize=ftell(cest4)/sizeof(Student);
	fseek(cest4, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Student), 1, cest4);
		printf("\n%d", aux.id);
	}
	
	fclose(cest4);
}
