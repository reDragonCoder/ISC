// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

//DATA TYPE DEFINITION
typedef int Item;

//NODE DEFINITION   
typedef struct Element{
    Item data;
    struct Element *next;
}Node;

//PROTOTYPES
Node* createNode(Item x, Node* next);
void insertCircular(Node** lc, Item x);
void eliminateFront(Node** lc);
bool isEmpty(Node* lc);
void obtainFront(Node* lc);

void showList(Node* lc);
void freeMemory(Node* lc);

//MAIN
int main(){
    Node *lc;
    lc=NULL;
    lc=createNode(4, NULL);
    showList(lc);

    insertCircular(&lc, 5);
    showList(lc);

    insertCircular(&lc, 6);
    showList(lc);

    insertCircular(&lc, 7);
    showList(lc);

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

void eliminateFront(Node** lc){
    Node* q;
    Node* p;
    p=*lc;
    q=p->next;
    (*lc)->next=q->next;
    p->next=q->next;
    free(q);
}

bool isEmpty(Node *lc){
    if(lc==NULL){
        return true;
    }
    return false;
}

void obtainFront(Node* lc){
    Node* q;
    Item front=0;
    q=lc;
    if(isEmpty(lc)) {
        puts("---Empty---");
    }else{
        q=q->next;
        front=q->data;
    }
    printf("Front Item: %d", front);
    printf("\n");
}

void showList(Node *lc){
    Node* q=lc;
    Item front=0;
    puts("\nList: ");
    if(isEmpty(lc)) {
        puts("---Empty---");
    }else{
      do{
        q=q->next;
        front=q->data;
        printf("%d, ", front);
      }while(q!=lc);
    }
    printf("\n");
}

void freeMemory(Node *lc){
    printf("\nFreeing memory \n");
    Node* q=lc;
    Node* temp;
    q=q->next;
    if(!isEmpty(lc)){
        temp=q;
        printf("Freeing: %d\n", temp->data);
        q=q->next;
        free(temp);

        while(q!=lc) {
            temp=q;
            printf("Freeing: %d\n", temp->data);
            q=q->next;
            free(temp);
        }
        temp=q;
        printf("Freeing: %d\n", temp->data);
        q=q->next;
        free(temp);
    }
}





