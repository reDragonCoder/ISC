// Author: reDragonCoder
//Simple lists
//NOTE: &(reference) to send a structure to a function

//A node is a structure 

//LIBRARIES
#include <iostream>
#include <stdlib.h> //dynamic memmory library
#include <string.h>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANT
#define TOT 4

//STRUCTS
struct Node{
    int id;
    char name[15];
    float gpa;
    Node *link; //recursive declaration
};

//DATA TYPE DEFINITION
typedef struct Node *Tlist; //*Tlist is a pointer data type
//Node *list; //Node is not a pointer data type, *list is a pointer data type

//PROTOTYPES
void menu();
Node capture();
void insert(Tlist&, Node); //& cause I'm going to modify
void shift(Tlist); //not & cause I'm not going to modify
void eliminate(Tlist&);

//MAIN
int main(){
    menu();

    return 0;
}

//IMPLEMENTATIONS
void menu(){
    int opc=0;
    Tlist list=NULL;
    Node data;
    enum{INSERT=1, SHIFT, ELIMINATE, EXIT};
    char vecEnum[][10]={"Insert", "Shift", "Eliminate", "Exit"};
    do{
        for(int i=0; i<TOT; i++){
            cout<<vecEnum[i]<<"....."<<i+1<<endl;
        }
        cin>>opc;
        switch(opc){
            case INSERT:
                data=capture();
                insert(list, data);
            break;
            case SHIFT:
                shift(list);
            break;
            case ELIMINATE:
                eliminate(list);
            break;
        }
    }while(opc!=EXIT);
}

Node capture(){
    Node aux;
    cout<<"ID: ";
    cin>>aux.id;
    cout<<"Name: ";
    cin>>aux.name;
    cout<<"GPA: ";
    cin>>aux.gpa;
    return aux;
}

void insert(Tlist &list, Node data){ //& to give the reference
    Tlist nueveishon;
    nueveishon=new(struct Node); //it creates a struct with the Node fields
    nueveishon->id=data.id; //-> with pointers, . with the other ones
    strcpy(nueveishon->name,data.name);
    nueveishon->gpa=data.gpa;
    nueveishon->link=list;
    list=nueveishon;
}

void shift(Tlist list){
    int tot=0;
    while(list!=NULL){
        cout<<list->id<<"-"<<list->name<<"-"<<list->gpa<<endl;
        //move to the next one
        list=list->link;
        tot++; //count nodes
    }
    cout<<"Your list has "<<tot<<" nodes \n";
}

void eliminate(Tlist &list){
    Tlist aux;
    aux=list;
    if(list==NULL){
        cout<<"The list is empty \n";
    }else{
        if(aux==list){
            list=list->link;
        }else{
            list->link=aux;
        }
        cout<<"The student "<<aux->id<<" has been deleted \n";
        delete aux;
    }
}


