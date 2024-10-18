// Author: reDragonCoder
//En una escuela preparatoria requieren emitir algunos reportes sobre los N alumnos de un grupo de estudiantes. Entre los datos más importantes
//se encuentra el id, nombre, semestre, grupo y materia. Donde la materia se compone de los siguientes campos: clave de la materia, nombre y 
//calificaciones parciales (en total 3).
//Se pide generar los siguientes reportes:
//  a) Mostrar un listado con el id y nombre de los estudiantes con promedio mayor a 8.5
//  b) Mostrar un listado de los alumnos no aprobados en la materia con clave ABC considerando 7 como califiación suficiente para aprobar
//  c) Mostrar un listado de los alumnos que tienen calificación más alta (entre 9 y 10)
//  d) Mostrar el promedio individual de cada alumno en la materia de Programación
//  e) Es importante crear una función que permita el llenado del arreglo de tamaño N indicado por el usuario
//(se calificará estructuras anidadas, arreglo dinámico de tipo estructura, paso de parámetros, funciones, enumeraciones. Los datos de tipo char
//deberán ser dinámicos, correcto funcionamiento del programa)

//LIBRARIES
#include <iostream>
#include <string.h>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define MAX 30

//STRUCT DECLARATIONS
struct SubjectS{
    char *key;
    char *Sname;
    float grades[3];
    float gpa;
};

struct Student{
    int id;
    char *name;
    int semester;
    char group;
    SubjectS subject;
};

//ENUM DECLARATION
enum menuOptions{
    one=1,
    two,
    three,
    four,
    five
};

//PROTOTYPES
void fillList(Student*, int);
void menu(Student*, int);
void listCaseOne(Student*, int);
void listCaseTwo(Student *, int);
void listCaseThree(Student *, int);
void listCaseFour(Student *, int);

//MAIN
int main(){
    int n=0;
    cout<<"How many students do you want to register?: ";
    cin>>n;
    Student* list=new Student[n]; //dynamic array of students
    fillList(list, n);
    menu(list, n);

    return 0;
}

//IMPLEMENTATIONS
void menu(Student *list, int n){
    int opt=0;
    do{
        cout<<"                ---MENU---           "<<endl;
        cout<<"1) Students with gpa greater than 8.5"<<endl;
        cout<<"2) Students not aproved in the ABC key subject"<<endl;
        cout<<"3) Students with highest grades"<<endl;
        cout<<"4) Students gpa in programming subject"<<endl;
        cout<<"5) Exit"<<endl;
        cout<<endl<<"Enter your option: ";
        cin>>opt;
        switch(opt){
            case one:
                listCaseOne(list, n);
            break;
            case two:
                listCaseTwo(list, n);
            break;
            case three:
                listCaseThree(list, n);
            break;
            case four:
                listCaseThree(list, n);
            break;
        }
    }while(opt!=5);
}

void fillList(Student* list, int n){
    float gpaAux=0;
    for(int i=0; i<n; i++){
        cout<<"Student "<<i+1<<endl;
        //id
        cout<<"ID: ";
        cin>>list[i].id;
        //name
        cout<<"Name: ";
        list[i].name=new char[30];
        fflush(stdin);
        cin>>list[i].name;
        //semester
        cout<<"Semester: ";
        cin>>list[i].semester;
        //group
        cout<<"Group: ";
        fflush(stdin);
        cin>>list[i].group;
        //subject key
        cout<<"Subject key: ";
        list[i].subject.key=new char[3];
        fflush(stdin);
        cin>>list[i].subject.key;
        //subject name
        cout<<"Subject name: ";
        list[i].subject.Sname=new char[30];
        fflush(stdin);
        cin>>list[i].subject.Sname;
        //subject grades
        cout<<"Subject grades: \n";
        for(int g=0; g<3; g++){
            cout<<"Grade["<<g+1<<"]: ";
            cin>>list[i].subject.grades[g];
            gpaAux+=list[i].subject.grades[g];
        }
        list[i].subject.gpa=gpaAux/3;
        cout<<endl;
    }
}

void listCaseOne(Student *list, int n){
    for(int i=0; i<n; i++){
        if(list[i].subject.gpa>8.5){
            cout<<"\n";
            cout<<list[i].id<<"\t"<<list[i].name<<"\t"<<list[i].subject.gpa;
            cout<<"\n\n";
        }
    }
}

void listCaseTwo(Student *list, int n){
    for(int i=0; i<n; i++){
        if((strcmp(list[i].subject.key, "abc")==0 || strcmp(list[i].subject.key, "ABC")==0) && (list[i].subject.gpa>=0 && list[i].subject.gpa<7)){
            cout<<"\n";
            cout<<list[i].id<<"\t"<<list[i].name<<"\t"<<list[i].subject.gpa;
            cout<<"\n\n";
        }
    }
}

void listCaseThree(Student *list, int n){
    for(int i=0; i<n; i++){
        if(list[i].subject.gpa>=9 && list[i].subject.gpa<=10){
            cout<<"\n";
            cout<<list[i].id<<"\t"<<list[i].name<<"\t"<<list[i].subject.gpa;
            cout<<"\n\n";
        }
    }
}

void listCaseFour(Student *list, int n){
    for(int i=0; i<n; i++){
        if(strcmp(list[i].subject.Sname, "programming")||strcmp(list[i].subject.Sname, "Programming")||strcmp(list[i].subject.Sname, "PROGRAMMING")){
            cout<<"\n";
            cout<<list[i].id<<"\t"<<list[i].name<<"\t"<<list[i].subject.gpa;
            cout<<"\n\n"; 
        }
    }
}


