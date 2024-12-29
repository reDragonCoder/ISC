// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

//DATA TYPE DEFINITION
typedef char* Item;

//NODE DEFINITION
typedef struct Element{
    Item data;
    struct Element *next;
}Node;

//PROTOTYPES
bool isEmpty(Node* lc);
Node* createNode(Item x, Node* next);
void insertCircular(Node** lc, Item x);
void eliminate(Node** lc, Item entry);
void showList(Node* lc);
void freeMemory(Node* lc);
bool search(Node **lc, Item x);

//MAIN
int main(){
    Node *lc;
    lc=NULL;
    lc=createNode("juan", NULL);

    insertCircular(&lc, "Pedro");
    insertCircular(&lc, "Thiago");
    insertCircular(&lc, "Omar");

    showList(lc);

    if(search(&lc, "Thiago")){
        puts("The element is in the list");
    }else{
        puts("The element is NOT in the list");
    }

    freeMemory(lc);

    return 0;
}

//IMPLEMENTATIONS
Node* createNode(Item x, Node *next){
    Node* neweishon;
    neweishon=(Node*)malloc(sizeof(Node));
    neweishon->data=x;
    neweishon->next=neweishon;
    return neweishon;
}

void insertCircular(Node **lc, Item x){
    Node *neweishon=createNode(x, NULL);
    if(*lc!=NULL) {
        neweishon->next=(*lc)->next;
        (*lc)->next=neweishon;
    }
    *lc=neweishon;
}

void eliminate(Node **lc, Item entry){
    Node* current;
    int found=0;
    if((*lc)==NULL) return;
    
    current=*lc;
    
    //search loop
    while((current->next!=*lc)&&(!found)) {
        found=(current->next->data==entry);
        if(!found){
            current=current->next;
        }
    }
    found=(current->next->data==entry);
    //link previous node with next one
    if(found){
        Node* p;
        p=current->next;
        if(*lc==(*lc)->next) {
            *lc=NULL;
        }else{
            if(p==*lc) {
                *lc=current;
            }
            current->next=p->next;
        }
        free(p);
    }
}

bool isEmpty(Node *lc){
    if (lc==NULL) {
        return true;
    }
    return  false;
}

void showList(Node *lc){
    Node* q=lc;
    puts("\nList: ");
    if(isEmpty(lc)) {
        puts("---Empty---");
    }else{
        if(q->next==lc) {
            printf("%s, ", q->data);
        }else{
            do{
                printf("%s, ", q->data);
                q=q->next;
            } while(q!=lc);
        }
    }
    printf("\n");
}

void freeMemory(Node *lc){
    printf("\nFreeing memory \n");
    Node* q=lc;
    if(!isEmpty(lc)){
        Node *temp=q;
        printf("Freeing: %s\n", temp->data);
        q=q->next;
        free(temp);

        while(q!=lc) {
            temp=q;
            printf("Freeing: %s\n", temp->data);
            q=q->next;
            free(temp);
        }
    }
}

bool search(Node **lc, Item x){
    Node* current;
    bool here=false;

    if (*lc==NULL) {
        return here;
    }

    current=*lc;

    if(current->data==x) {
        return true;
    }

    while((current->next!=*lc) && (!here)){
        here=(current->next->data==x);
        if(!here){
            current=current->next;
        }
    }

    return here;
}