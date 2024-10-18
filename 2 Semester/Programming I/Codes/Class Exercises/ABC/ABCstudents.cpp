// Author: reDragonCoder
//ABC-Students
//Altas, bajas, cambios y consultas (ABC)
//The ID is the key space, it helps to delete and change the status cause is someting irrepetible

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define MAX 3
#define TOTGRADES 4

//STRUCT DECLARATIONS
struct Student{
	int id;
	char name[20];
	float grades[TOTGRADES];
	bool status;
};

//GLOBAL VARIABLES
int topeishon=0;

//PROTOTYPES
void menu();
void subMenu(Student[]);
void setStudent(Student[]);
void deleteStudent(int, Student[]);
int getID();
void showStudents(Student []);
bool findStudent(int, Student[]);
void showIndividual(int, Student[]);
void showGPA(Student[]);

//MAIN
int main(){
	//CALLBACK
	menu();

	return 0;
}

//IMPLEMENTATIONS
void menu(){
	int opt=0, id=0;
	Student group[MAX];
	do{
		cout<<endl;
		cout << "--OPTIONS-- \n";
		cout << "Set student  ...... 1\n";
		cout << "Delete student .... 2\n";
		cout << "Show  submenu ..... 3\n";
		cout << "Exit .............. 4\n";
		cout << "Select one option: ";
		cin >> opt;
		switch(opt){
			case 1:
				if(topeishon<MAX){
					setStudent(group);
					topeishon++; //Pile's logic (without cycle, cwith top as global variable)
					cout<<endl;
				}
				else{
					cout<<"The group is full"<<endl;
				}
				break;
			case 2: 
				id=getID();
				deleteStudent(id, group);
				break;
			case 3:
				subMenu(group);
				break;
		}
	}while(opt!=4);
}

void subMenu(Student group[]){
	int opt=0, id=0;
	bool exists=false;
	do{
		cout<<endl;
		cout<<"--SHOW OPTIONS--"<<endl;
		cout<<"Show students ........... 1 \n";
		cout<<"Exist ................... 2 \n";
		cout<<"Show individual ......... 3 \n";
		cout<<"Show gpa................. 4 \n";
		cout<<"Exit .................... 5 \n";
		cout<<"Select one option: ";
		cin>>opt;
		switch(opt){
			case 1:
				showStudents(group);
				break;
			case 2:
				id=getID();
				exists=findStudent(id, group);
				if(exists==true){
					cout<<endl;
					cout<<"The student exists"<<endl;
				}else if(exists==false){
					cout<<endl;
					cout<<"The student does not exists"<<endl;
				}
				break;
			case 3:
				id=getID();
				showIndividual(id, group); 
				break;
			case 4:
				showGPA(group);
				break;
		}
	}while(opt!=5);
}

void setStudent(Student group[]){
	cout<<endl;
	cout<<"Introduce the student info: "<<endl;
	cout<<"ID: ";
	cin>>group[topeishon].id;
	cout<<"Name: ";
	cin>>group[topeishon].name;
	cout<<"Grades: "<<endl;
	for(int g=0; g<TOTGRADES; g++){
		cout<<"Grade "<<g<<": ";
		cin>>group[topeishon].grades[g];
	}
	group[topeishon].status=true;
}

void deleteStudent(int id, Student group[]){
	cout<<endl;
	for(int i=0; i<topeishon; i++){
		if(group[i].id==id){
			group[i].id={};
			group[i].status=false;
			topeishon--;
			break;
		}
	}
	cout<<"Deleted succesfully"<<endl;
}

int getID(){
	cout<<endl;
	int id;
	cout<<"ID: ";
	cin>>id;
	return id;
}

void showStudents(Student group[]){
	cout<<endl;
	cout<<"Students \n";
	for(int i=0; i<topeishon; i++){
		if(group[i].status==true){
			cout<<"Id: "<<group[i].id<<"\t"<<"Name: "<<group[i].name<<"\t"<<endl;
			for(int g=0; g<TOTGRADES; g++){
				cout<<"Grade "<<g<<": "<<group[i].grades[g]<<"\t";
			}
			cout<<endl;
		}
	}
}

bool findStudent(int id, Student group[]){
	for(int i=0; i<topeishon; i++){
		if(group[i].id==id){
			return true;
		}
	}
	return false;
}

void showIndividual(int id, Student group[]){
	cout<<endl;
	for(int i=0; i<topeishon; i++){
		if(group[i].id==id){
			cout<<"Student"<<endl;
			cout<<"Id: "<<group[i].id<<"\t"<<"Name: "<<group[i].name<<"\t"<<endl;
			for(int g=0; g<TOTGRADES; g++){
				cout<<"Grade "<<g<<": "<<group[i].grades[g]<<"\t";
			}
			cout<<endl;
		}
	}
}

void showGPA(Student group[]){
	float studentGPA=0, groupGPA=0;
	cout<<endl;
	for(int i=0; i<topeishon; i++){
		cout<<"Id: "<<group[i].id<<"\t"<<"Name: "<<group[i].name<<"\t"<<endl;
		for(int g=0; g<TOTGRADES; g++){
			studentGPA+=group[i].grades[g];
		}
		studentGPA/=TOTGRADES;
		groupGPA+=studentGPA;
		cout<<"GPA: "<<studentGPA<<endl;
		studentGPA=0;
	}
	groupGPA/=topeishon;
	cout<<"The group GPA is: "<<groupGPA<<endl;
}

