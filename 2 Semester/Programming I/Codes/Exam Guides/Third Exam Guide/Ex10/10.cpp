// Author: reDargonCoder

//The monthly data handled by a payroll system is stored in a text file on a file called �master.dat�. 
//Write a program that calculates the average number of hours worked in the month and the total amount 
//of money to be paid in the month.

//LIBRARIES
#include <iostream>

using namespace std;

//STRUCT DECLARATION
struct Employee{
	char name[50];
	char lastName[50];
	int workedHours;
	float hourlySalary;
};

//PROTOTYPES
void fillFile(FILE*);
void showEmployeesInfo(FILE*);
void averageHours(FILE*);
void moneyXmonth(FILE*);

//MAIN
int main(){
	FILE* master=NULL;
	
	fillFile(master);
	cout<<endl;
	showEmployeesInfo(master);
	cout<<endl;
	averageHours(master);
	moneyXmonth(master);
	
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
		cout<<"Enter the employee name: ";
		cin>>aux.name;
		cout<<"Enter the employee last name: ";
		cin>>aux.lastName;
		cout<<"Enter the worked hours per month: ";
		cin>>aux.workedHours;
		cout<<"Enter the salary per hour: ";
		cin>>aux.hourlySalary;
		fwrite(&aux, sizeof(Employee), 1, master);
	}
	
	fclose(master);
}

void showEmployeesInfo(FILE* master){
	Employee aux;
	int fileSize;
	master=fopen("master.dat", "rb");
	if(master==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	fseek(master, 0L, SEEK_END);
	fileSize=ftell(master)/sizeof(Employee);
	fseek(master, 0L, SEEK_SET);
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master);
		printf("\n%s\t%s\t%d\t%.2f", aux.name, aux.lastName, aux.workedHours, aux.hourlySalary);
	}
	
	fclose(master);
}

void averageHours(FILE* master){
	master=fopen("master.dat", "rb+");
	if(master==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int counter=0, fileSize=0, hoursXmonth=0;
	float average=0;
	
	fseek(master, 0L, SEEK_END);
	fileSize=ftell(master)/sizeof(Employee);
	fseek(master, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master);
		hoursXmonth+=aux.workedHours;
		counter++;
	}
	
	average=hoursXmonth/counter;
	
	cout<<"\nAverage hours worked in the month: "<<average<<" hours";
	
	fclose(master);
}

void moneyXmonth(FILE* master){
	master=fopen("master.dat", "rb+");
	if(master==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	Employee aux;
	int fileSize=0, hoursXmonth=0;
	float moneyXmonth=0, salary=0;
	
	fseek(master, 0L, SEEK_END);
	fileSize=ftell(master)/sizeof(Employee);
	fseek(master, 0L, SEEK_SET);
	
	for(int i=0; i<fileSize; i++){
		fread(&aux, sizeof(Employee), 1, master);
		hoursXmonth=aux.workedHours;
		salary=aux.hourlySalary;
		moneyXmonth+=(hoursXmonth*salary);
		hoursXmonth=0;
		salary=0;	
	}
	
	cout<<"\nTotal amount of money to be paid in the month: $"<<moneyXmonth;
	
	fclose(master);
}
