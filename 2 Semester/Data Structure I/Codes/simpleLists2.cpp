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
void freeMemory(Node *start);
Node *insertStart(Node *start, type x); //it returns a pointer to a start (Node *insertStart)
Node *insertEnd(Node *start, type x); //it returns a pointer to an end (Node *insertEnd)
Node *insertBefore(Node *start, type x, type y);
Node *insertAfter(Node *start, type x, type y);
Node* deleteFirst(Node *start, type x);
Node* deleteAll(Node *start, type x);
bool exists(Node *start, type x);

//MAIN
int main(){
    //Start node definition
    Node *start;
    start=NULL;

    if(isEmpty(start)){
        cout<<"\nThe list is empty\n";
    }else{
        cout<<"\nThe list is not empty\n";
        showList(start);
    }

    start=deleteFirst(start, 5);

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

Node* insertEnd(Node *start, type x){
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
    return start;
}

Node *insertBefore(Node *start, type x, type y){
    Node *newishon=createNode(x, NULL);
    Node *q=start;
    Node *k=start;
    int b=0;
    if(!start){
        start=newishon;
    }else{
        for(int i=0; k; k=k->link){
            i++;
            if(k->data==y){
                b=i;
            }
        }
        if(b==1){
            start=insertStart(start, x);
        }else{
            for(int i=0; q; q=q->link){
                if(q->link->data==y){
                    newishon->link=q->link;
                    q->link=newishon;
                    break;
                }
                i++;
            }
        }
    }
    return start;
}

Node* insertAfter(Node *start, type x, type y){
    Node *newishon=createNode(x, NULL);
    Node *q=start;
    if(!start){
        start=createNode(x, NULL);
    }else{
        for(int k=0; q; q=q->link){
            if(q->data==y){
                newishon->link=q->link;
                q->link=newishon;
            }
            k++;
        }
    }
    return start;
}

Node* deleteFirst(Node *start, type x){ 
    Node *q;
    q=(Node*)malloc(sizeof(Node));
    q=start;
    if(!start){
        cout<<"There is no elements that can be erased";
        return NULL;
    }else{
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
