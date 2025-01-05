// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

typedef int type;

typedef struct Element{
    type coefficient;
    type exponent;
    struct Element *link;
}Node;

//PROTOTYPES
Node *insertNode(Node*, type, type);
void showList(Node*);
Node *simplifyList(Node*list);

//MAIN
int main(){
    Node *list;
    list=NULL;
    type elementN, coefficient, exponent;
    cout<<"How many elements do you want to register?: ";
    cin>>elementN;
    for(int i=0; i<elementN; i++){
        cout<<"Enter the coefficient for node "<<i+1<<": ";
        cin>>coefficient;;
        cout<<"Enter the exponent for node "<<i+1<<": ";
        cin>>exponent;
        list=insertNode(list, coefficient, exponent);
        coefficient=0;
        exponent=0;
    }
    cout<<endl;
    showList(list);
    list=simplifyList(list);
    cout<<endl;
    showList(list);
    return 0;
}

//IMPLEMENTATIONS
Node* createNode(type coefficient, type exponent, Node *band){
    Node *aux;
    aux=(Node*)malloc(sizeof(Node));
    aux->coefficient=coefficient;
    aux->exponent=exponent;
    aux->link=band;
    return aux;
}

Node *insertNode(Node* list, type coefficient, type exponent){
    Node *aux=createNode(coefficient, exponent, NULL);
    if(!list){
        list=aux;
    }else{
        Node* current=list;
        while(current->link){
            current=current->link;
        }
        current->link=aux;
    }
    return list;
}

void showList(Node* list) {
    Node* q=list;
    int k=0;
    while(q){
        if(q->coefficient!=0){
            if(k>0){
                if(q->coefficient>0){
                    cout<<"+";
                }else{
                    cout<<"-";
                }
            }
            if(abs(q->coefficient)!= 1 || q->exponent==0){
                cout<<abs(q->coefficient);
            }
            if(q->exponent>0) {
                cout<<"x";
                if(q->exponent!=1){
                    cout<<"^"<<q->exponent;
                }
            }
            k++;
        }
        q=q->link;
    }
}

//start end para simplify list

Node *simplifyList(Node*list){ 
    Node *auxList;
    auxList=NULL;
    int e=0, addC=0;
    Node *current=list;
    while(current){
        if(current->exponent>e){
            e=current->exponent;
        }
        current=current->link;
    }
    while(e>=0){
        current=list;
        while(current){
            if(current->exponent==e){
                addC+=current->coefficient;
                
            }
            current=current->link;
        }
        auxList=createNode(addC, e, auxList);
        e--;
        addC=0;
    }
    return auxList;
}
