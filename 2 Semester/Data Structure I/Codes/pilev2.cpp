// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <iostream>

using namespace std;

//GLOBAL CONSTANTS
#define MAX 100
#define dataType int

//GLOBAL VARIABLES
dataType pileList[MAX];
int topeishon;

//PROTOTYPES
void menu();
void createPile();
bool emptyPile();
bool fullPile();
void cleanPile();
void push(dataType element);
dataType pop();
dataType getTopeishon();

//MAIN
int main(){
    createPile();
    menu();
    return 0;
}

//IMPLEMENTATIONS
void menu(){
    int opt=0, element=0, top=0;
    do{
        cout<<endl;
        cout<<"OPTIONS"<<endl;
        cout<<"Clean pile......................................1"<<endl;
        cout<<"Add an element..................................2"<<endl;
        cout<<"Pull out an element.............................3"<<endl;
        cout<<"Get the top element.............................4"<<endl;
        cout<<"Exit............................................5"<<endl;
        cout<<"Select your option: ";
        cin>>opt;
        cout<<endl;
        switch(opt){
            case 1:
                cleanPile();
                cout<<"You have successfully cleaned the pile"<<endl;
                break;
            case 2: 
                cout<<"Type your number: ";
                cin>>element;
                push(element);
                cout<<"Succesfully saved element"<<endl;
                break;
            case 3:
                element=pop();
                cout<<"The element you pulled out was ["<<element<<"]"<<endl;
                break;
            case 4:
                top=getTopeishon();
                cout<<"The top element in the pile is ["<<top<<"]"<<endl;
                break;
        }
    }while(opt!=5);
}

void createPile(){
    topeishon=-1;
}

bool emptyPile(){
    if(topeishon==-1){
        return true;
    }else{
        return false;
    }
}

bool fullPile(){
    if(topeishon==MAX-1){
        return true;
    }else{
        return false;
    }
}

void cleanPile(){
    topeishon=-1;
}

void push(dataType element){
    if(fullPile()==true){ 
        cout<<"The pile is full"<<endl;
    }else{
        topeishon++;
        pileList[topeishon]=element;
    }
}

dataType pop(){
    if(emptyPile()==true){
        cout<<"You can't pop any element, the pile is empty";
        return(-1); 
    }else{
        dataType temp=pileList[topeishon];
        topeishon--;
        return(temp);
    }
}

dataType getTopeishon(){
    if(emptyPile()==true){
        cout<<"You can't get the top, the pile is empty"<<endl;
        return(-1); 
    }else{
        return(pileList[topeishon]);
    }
}