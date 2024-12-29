// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TYPEDEF AND STRUCT DEFINITION
typedef int type;

typedef struct Element{
    type data;
    struct Element *left;
    struct Element *right;
}Node;

//PROTOTYPES
Node* createNode(type x, Node* l, Node *r);
void showList(void);
void showListEndStart(void);
bool isEmpty(void);
void insertStart(type x);
void freeMemory(void);

void insertEnd(type x);
Node* insertBefore(type x, type y);
Node* insertAfter(type x, type y);
void compactList(void);
Node* deleteFirst(type x);
bool exists(type x);

Node* start;
Node* end;

//MAIN
int main(){
    end=start=NULL;

    end=start=createNode(7, NULL, NULL);
    insertEnd(7);
    insertEnd(7);
    insertEnd(8);
    insertEnd(7);
    insertEnd(7);
    insertEnd(8);
    insertEnd(7);
    insertEnd(7);
    insertEnd(8);

    showList();

    compactList();

    showList();

    freeMemory();

    return 0;
}

//IMPLEMENTATIONS
bool isEmpty(void){
    if(start==NULL){
        return true;
    }

    return false;
}

Node* createNode(type x, Node *l, Node *r){
    Node *neweishon;
    neweishon=(Node*)malloc(sizeof(Node));
    neweishon->data=x;
    neweishon->left=l;
    neweishon->right=r;
    return neweishon;
}

void showList(void){
    int k;
    Node* q=start;

    puts("\nLIST: ");
    for(k=0; q; q=q->right){
        printf("%d ", q->data);
        k++;
    }
    printf("\n");
}

void showListEndStart(void){
    int k;
    Node* q=end;

    puts("\nLIST START-END: ");
    for(k=0; q; q=q->left){
        printf("%d ", q->data);
        k++;
    }
    printf("\n");
}

void insertStart(type x){
    Node* neweishon=createNode(x, NULL, NULL);
    neweishon->right=start;
    start->left=neweishon;
    start=neweishon;
}

void freeMemory(void){
    printf("\n");
    printf("Freeing memory \n");
    if(!isEmpty()){
        while(start){
            Node *temp=start;
            start=start->right;
            printf("Freeing %d\n", temp->data);
            free(temp);
        }
    }
}

void insertEnd(type x){
    Node *neweishon=createNode(x, NULL, NULL);
    neweishon->left=end;
    end->right=neweishon;
    end=neweishon;
}

Node* insertBefore(type x, type y){
    Node* neweishon=createNode(x, NULL, NULL);
    Node* q=start;
    Node* p=NULL;
    for(int i=0; q; q=q->right){
        if(q->data==y){
            if(q->left==NULL){
                insertStart(x);
            }else{
                p=q->left;
                q->left=neweishon;
                p->right=neweishon;
                neweishon->left=p;
                neweishon->right=q;
            }
            break;
        }
        i++;
    }
    return start;
}

Node* insertAfter(type x, type y){
    Node* neweishon=createNode(x, NULL, NULL);
    Node* q=start;
    Node* p=NULL;
    for(int i=0; q; q=q->right){
        if(q->data==y){
            if(q->right==NULL){
                insertEnd(x);
            }else{
                p=q->right;
                q->right=neweishon;
                p->left=neweishon;
                neweishon->right=p;
                neweishon->left=q;
            }
            break;
        }
        i++;
    }
    return start;
}

void compactList(void){
    Node* p=start;
    Node* q=NULL;
    Node* temp=NULL;

    while(p!=NULL){
        q=p->right;
        while(q!=NULL){
            if(p->data==q->data){
                temp=q->right;
                if(temp!=NULL){
                    temp->left=q->left;
                }
                if(q->left!=NULL){
                    q->left->right=temp;
                }
                free(q);
                q=temp;
            }else{
                q=q->right;
            }
        }
        p=p->right;
    }
}

Node* deleteFirst(type x){
    Node* q=start;
    Node* p=NULL;
    for(int i=0; q; q=q->right){
        if(q->data==x){
            p=q->left;
            p->right=q->right;
            q->right->left=p;
            free(q);
            q=NULL;
            break;
        }
        i++;
    }
    return start;
}

bool exists(type x){
    Node* q=start;
    bool found=false;
    for(int i=0; q; q=q->right){
        if(q->data==x){
            found=true;
        }
        i++;
    }
    return found;
}