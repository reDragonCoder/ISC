// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCT DECLARATIONS
struct Date{
    int dd, mm, yy;
};

struct Student{
    char name[20];
    int id;
    Date enrolDate;
    float grades[3];
};

//NOTE:
//Struct declaration type 2 (not the best option)
//struct Student{
//  int id;
//  char name[20];
//  floar grades[3];
//  struct Date{
//      int dd, mm, yy;
//  }
//}

//PROTOTYPES
void menu();
Student getStudent();
void showStudent(Student);
Date getDate();

//MAIN
int main(){
    //CALLBACK
    menu();

    return 0;
}

//IMPLEMENTATIONS
void menu(){
	int opt;
    Student alumn;
	do{
		cout<<"Options "<< endl;
		cout<<"Get student information .... 1\n";
		cout<<"Show student ............... 2\n";
		cout<<"Exit ....................... 3\n";
		cout<<"Select one option: ";
		cin>>opt;
		switch(opt){
			case 1: 
                alumn=getStudent();
            break;
			case 2: 
                showStudent(alumn);
            break;
		}
	}while(opt!=3);
}

Student getStudent(){
    Student aux;
    cout<<"Get student"<<endl;
    cout<<"Id: ";
    cin>>aux.id;
    cout<<"Name: ";
    cin>>aux.name;
    cout<<"Admission date: "<<endl;
    aux.enrolDate=getDate();
    for(int i=0; i<3; i++){
        cout<<"Grade: ["<<i<<"]: ";
        cin>>aux.grades[i];
    }
    return aux;
}

Date getDate(){
    Date temp;
    cout<<"Day: ";
    cin>>temp.dd;
    cout<<"Month: ";
    cin>>temp.mm;
    cout<<"Year: ";
    cin>>temp.yy;
    return temp;
}

void showStudent(Student alumn){
    float addition=0;
    cout<<"Student Information"<<endl;
    cout<<"Id: "<<alumn.id<<endl;
    cout<<"Name: "<<alumn.name<<endl;
    cout<<"Enrolment date: "<<alumn.enrolDate.dd<<"/"<<alumn.enrolDate.mm<<"/"<<alumn.enrolDate.yy<<endl;
    for(int i=0; i<3; i++){
        addition+=alumn.grades[i];
    }
    cout<<"Final grade: "<<addition/3<<endl;
}