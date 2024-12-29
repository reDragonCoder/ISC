// Author: reDargonCoder

//With the same file format as the previous problem, the manager wants to obtain a file
//�master2.dat� containing only employees who have worked more than 20 hours and earn
//less than 1500 dollars per hour.

//LIBRARIES
#include <iostream>

using namespace std;

//STRUCT DECLARATION
struct Employee{
	char name[50];
	char lastName[50];
	int workedHours;
	float salaryXhr;
};

//PROTOTYPES
void fillFile(FILE*);
void showFile(FILE*);
void fillRequested(FILE*, FILE*);
void showRequested(FILE*);

//MAIN
int main(){
	FILE* master=NULL;
	FILE* master2=NULL;
	
	fillFile(master);
	cout<<endl;
	showFile(master);
	fillRequested(master, master2);
	cout<<endl;
	showRequested(master2);
	
	return 0;
}

//IMPLEMENTATIONS
void fillFile(FILE* master){
	master=fopen("master.dat", "wb");
	if(master==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int employeeNo;
	
	cout<<"Enter the number of employees you want to register: ";
	cin>>employeeNo;
	
	for(int i=0; i<employeeNo; i++){
		cout<<"Enter the name of the employee: ";
		cin>>aux.name;
		cout<<"Enter the last name of the employee: ";
		cin>>aux.lastName;
		cout<<"Enter the number of worked hours: ";
		cin>>aux.workedHours;
		cout<<"Enter the salary per hour: ";
		cin>>aux.salaryXhr;
		fwrite(&aux, sizeof(Employee), 1, master);
	}
	
	fclose(master);
}

void showFile(FILE* master){
	master=fopen("master.dat", "rb");
	if(master==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int fileSize;
	fseek(master, 0L, SEEK_END);
	fileSize=ftell(master)/sizeof(Employee);
	fseek(master, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master);
		printf("\n%s\t%s\t%d\t%.2f", aux.name, aux.lastName, aux.workedHours, aux.salaryXhr);
	}
	
	fclose(master);
}

void fillRequested(FILE* master, FILE* master2){
	master=fopen("master.dat", "rb");
	master2=fopen("master2.dat", "wb");
	if(master==NULL || master2==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int fileSize;
	
	fseek(master, 0L, SEEK_END);
	fileSize=ftell(master)/sizeof(Employee);
	fseek(master, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master);
		if((aux.workedHours>20) && (aux.salaryXhr<1500)){
			fwrite(&aux, sizeof(Employee), 1, master2);
		}else{
			continue;
		}
	}
	
	fclose(master);
	fclose(master2);
}

void showRequested(FILE* master2){
	master2=fopen("master2.dat", "rb");
	if(master2==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int fileSize;
	
	fseek(master2, 0L, SEEK_END);
	fileSize=ftell(master2)/sizeof(Employee);
	fseek(master2, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master2);
		printf("\n%s\t%s\t%d\t%.2f", aux.name, aux.lastName, aux.workedHours, aux.salaryXhr);
	}
	
	fclose(master2);
}
