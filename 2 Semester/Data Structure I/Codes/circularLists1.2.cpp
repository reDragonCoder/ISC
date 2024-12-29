// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

//DATA TYPE DEFINITION
typedef int Item;

//NODE DEFINITION
typedef struct Element{
    Item real;
    Item imaginary;
    struct Element *next;
}Node;

//PROTOTYPES
bool isEmpty(Node* lc);
Node* createNode(Item y, Item x, Node *next);
void insertCircular(Node** lc, Item x, Item y);
void eliminate(Node** lc, Item x, Item y);
void eliminateAll(Node** lc, Item x, Item y);
void addition(Node* lc);
void showList(Node* lc);
void freeMemory(Node* lc);
bool found(Node** lc, Item x,Item y);

//MAIN
int main(){
    Node *lc;
    lc=NULL;
    lc=createNode(2, 3, NULL); //x and then y
    insertCircular(&lc, 2, 3);// y and then x
    insertCircular(&lc, 4, 8);
    insertCircular(&lc, 7, 7);
    insertCircular(&lc, 7, 7);
    insertCircular(&lc, 4, 8);

    showList(lc);

    eliminateAll(&lc, 7, 7);

    showList(lc);

    freeMemory(lc);

    return 0;
}   

//IMPLEMENTATIONS
Node* createNode(Item y,Item x, Node *next){
    Node *neweishon;
    neweishon=(Node*)malloc(sizeof(Node));
    neweishon->real=x;
    neweishon->imaginary=y;
    neweishon->next=neweishon;
    return neweishon;
}

void insertCircular(Node **lc, Item x, Item y){
    Node *neweishon=createNode(y,x, NULL);
    if (*lc!=NULL) {
        neweishon->next=(*lc)->next;
        (*lc)->next=neweishon;
    }
    *lc=neweishon;
}

void eliminate(Node **lc, Item x, Item y){
    Node* current;
    int found=0;
    if ((*lc)==NULL) return;
    
    current = *lc;
    
    while
    ((current->next!=*lc)&&(!found)) {
        found=((current->next->real==x)&&(current->next->imaginary==y));
        if (!found) {
            current=current->next;
        }
    }
    found=((current->next->real==x)&&(current->next->imaginary==y));
    if (found) {
        Node *p;
        p=current->next;
        if (*lc==(*lc)->next) {
            *lc=NULL;
        }else{
            if (p==*lc) {
                *lc=current;
            }
            current->next=p->next;
        }
        free(p);
    }
}

void eliminateAll(Node **lc, Item x, Item y) {
    Node* current=*lc;
    Node* aux=NULL;
    Node* aux2;

    if(current==NULL) return; 

    do{
        aux2=current->next; 
        if(current->real==x && current->imaginary==y) {
            if (aux==NULL) {
                *lc=aux2;
            }else{
                aux->next=aux2;
            }
            free(current);
            current=aux2; 
        }else{
            aux=current;
            current=aux2; 
        }
    } while(current!=*lc); 
}
    

void addition(Node *lc){
    Node *q=lc;
    int realSum=0, imgSum=0;
    if(!isEmpty(lc)) {
        realSum+=q->real;
        imgSum+=q->imaginary;
        q=q->next;
        while (q!=lc) {
            realSum+=q->real;
            imgSum+=q->imaginary;
            q=q->next;
        }
    }
    printf("%d + %di",realSum, imgSum);
}

bool isEmpty(Node *lc){
    if (lc==NULL) {
        return true;
    }
    return  false;
}

void showList(Node *lc){
    Node *q=lc;
    puts("\nList: ");
    if (isEmpty(lc)) {
        puts("---empty---");
    }else{
        if (q->next==lc) {
            printf("%d + %di, ",q->real, q->imaginary);
        }else{
            do {
                printf("%d + %di, ",q->real, q->imaginary);
                q=q->next;
            } while (q!=lc);
        }
    }
    printf("\n");
}

bool found(Node **lc, Item x, Item y) {
    bool here=false;
    Node *current;

    if (*lc==NULL) {
        return here;
    }

    current=*lc;

    if((current->real==x) && (current->imaginary==y)){
        return true;
    }

    while ((current->next!=*lc) && (!here)) {
        here = ((current->next->real==x) && (current->next->imaginary==y));
        if(!here){
            current=current->next;
        }
    }

    return here;
}


void freeMemory(Node *lc){
    printf("Freeing memory \n");
    Node *q=lc;
    if (!isEmpty(lc)) {
        Node *temp=q;
        printf("Freeing: %d %d\n", temp->real,temp->imaginary);
        q=q->next;
        free(temp);
        while (q!=lc) {
            temp=q;
            printf("Freeing: %d %d\n", temp->real,temp->imaginary);
            q=q->next;
            free(temp);
        }
    }
}