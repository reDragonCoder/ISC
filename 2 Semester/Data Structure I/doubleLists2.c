// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//TYPEDEF AND STRUCT DEFINITION
typedef char type;

typedef struct Element{
    type data;
    struct Element *left;
    struct Element *right;
}Node;

Node* createNode(type x, Node* l, Node *r);
void insertEnd(type x);
void showList(void);
bool isEmpty(void);
void freeMemory(void);
void sort();


Node* start;
Node* end;

int main(){
    int n=0;
    char c;
    end=start=NULL;

    printf("How many nodes you want to create?: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        if(i==1){
            printf("Enter the character: ");
            fflush(stdin);
            scanf("%c", &c);
            end=start=createNode(c, NULL, NULL);
        }else{
            printf("Enter the character: ");
            fflush(stdin);
            scanf("%c", &c);
            insertEnd(c);
        }
    }

    showList();
    sort();
    showList();
    freeMemory();
    
    return 0;
}

//IMPLEMENTATIONS
Node* createNode(type x, Node *l, Node *r){
    Node *neweishon;
    neweishon=(Node*)malloc(sizeof(Node));
    neweishon->data=x;
    neweishon->left=l;
    neweishon->right=r;
    return neweishon;
}

void insertEnd(type x){
    Node *neweishon=createNode(x, NULL, NULL);
    neweishon->left=end;
    end->right=neweishon;
    end=neweishon;
}

void showList(void){
    int k;
    Node* q=start;

    puts("\nLIST: ");
    for(k=0; q; q=q->right){
        printf("%c ", q->data);
        k++;
    }
    printf("\n");
}

bool isEmpty(void){
    if(start==NULL){
        return true;
    }
    return false;
}

void freeMemory(void){
    printf("\n");
    printf("Freeing memory \n");
    if(!isEmpty()){
        while(start){
            Node *temp=start;
            start=start->right;
            printf("Freeing %c\n", temp->data);
            free(temp);
        }
    }
}

void sort(){
    Node* q;
    Node* p;
    int temp;
    for(q=start; q; q=q->right){
        for(p=q->right; p; p=p->right){
            if(q->data>p->data){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}


