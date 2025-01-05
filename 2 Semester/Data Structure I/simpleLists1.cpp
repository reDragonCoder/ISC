// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

//DATA TYPE DEFINITIONS
//definition of the Node structure
typedef int type; //definition of general data type

typedef struct Element{
    type data;
    struct Element *link;
}Node;

//PROTOTYPES
bool isEmpty(Node *start);
Node* createNode(type x, Node *band); //it returns a pointer to a Node (Node* createNode)
void showList(Node *start);
Node *insertStart(Node *start, type x); //it returns a pointer to a start (Node *insertStart)
void freeMemory(Node *start);
void insertEnd(Node *start, type x); //it returns a pointer to an end (Node *insertEnd)
void insertBefore(Node *start, type x, type y);
void insertAfter(Node *start, type x, type y);
Node* deleteFirst(Node *start, type x);
Node* deleteAll(Node *start, type x);
bool exists(Node *start, type x);

//MAIN
int main(){
    //Start node definition
    Node *start;
    start=NULL;
    start=createNode(10, NULL);

    start=insertStart(start, 9);
    start=insertStart(start, 8);
    start=insertStart(start, 7);
    start=insertStart(start, 6);
    start=insertStart(start, 8);
    start=insertStart(start, 5);

    showList(start);

    if(exists(start, 3)==true){
        cout<<"\nThe number is in the list\n";
    }else{
        cout<<"\nThe number is NOT in the list!\n";
    }

    freeMemory(start);
    return 0;
}

bool isEmpty(Node *start){
    if(start==NULL){
        return true;
    }
    return false;
}

Node* createNode(type x, Node *band){
    Node *neweishon;
    neweishon=(Node*)malloc(sizeof(Node));
    neweishon->data=x;
    neweishon->link=band;
    return neweishon;
}

void showList(Node *start){
    int k=0;
    Node *q=start;
    cout<<"\nLIST\n";
    for(k=0; q/*will run as long as q is not NULL*/; q=q->link){
        cout<<q->data<<" ";
        k++;
    }
    cout<<endl;
}

Node *insertStart(Node *start, type x){
    Node *aux=createNode(x, NULL);
    aux->link=start;
    start=aux;
    return aux;
}

void freeMemory(Node *start){
    cout<<"\nFREE UP MEMORY\n";
    if(!isEmpty(start)){
        while(start){
            Node *aux=start;
            start=start->link;
            cout<<"Deleting "<<aux->data;
            free(aux);
            cout<<"\n";
        }
    }
}

void insertEnd(Node *start, type x){
    Node *aux=createNode(x, NULL);
    if(!start){
        start=aux;
    }else{
        Node* current=start;
        while(current->link){
            current=current->link;
        }
        current->link=aux;
    }
}

void insertBefore(Node *start, type x, type y){
    Node *newishon=createNode(x, NULL);
    Node *q=start;
    for(int k=0; q; q=q->link){
        if(q->link->data==y){
            newishon->link=q->link;
            q->link=newishon;
            break;
        }
        k++;
    }
}

void insertAfter(Node *start, type x, type y){
    Node *newishon=createNode(x, NULL);
    Node *q=start;
    for(int k=0; q; q=q->link){
        if(q->data==y){
            newishon->link=q->link;
            q->link=newishon;
        }
        k++;
    }
}

Node* deleteFirst(Node *start, type x){
    Node *q;
    q=(Node*)malloc(sizeof(Node));
    q=start;
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p=q;
    for(int k=0; q; q=q->link){
        if(q->data==x){
            p->link=q->link;
            break;
        }
        p=q;
        k++;
    }
    return p;
}

Node* deleteAll(Node *start, type x){
    Node *q;
    q=(Node*)malloc(sizeof(Node));
    q=start;
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p=q;
    for(int k=0; q; q=q->link){
        if(q->data==x){
            p->link=q->link;
        }
        p=q;
        k++;
    }
    return start;
}

bool exists(Node *start, type x){
    int k;
    bool flag=false;
    for(k=0; start; start=start->link){
        if(start->data==x){
            flag=true;
        }
    }
    k++;
    return flag;
}