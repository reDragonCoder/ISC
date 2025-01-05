//Author: reDragonCoder
//NODE DYNAMIC STACK IMPLEMENTED WITH LISTS

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTURES
struct bNode{
    char info;
    bNode *left, *right;
};

struct Node{
    bNode *info;
    Node *next;
};

//DATA TYPE DEFINITION
typedef Node *Stack;

//FUNCTION PROTOTYPES
void push(Stack &, bNode *); //insert in front
void pop(Stack &); //remove in front
bNode *top(Stack); 
bool empty(Stack); //asks if it is empty

//MAIN
int main(){
    Stack root=NULL;
    bNode *temp=NULL;
    
    bNode *t1=new bNode;
    t1->info='A';
    push(root, t1);
    bNode *t2=new bNode;
    t2->info='B';
    push(root, t2);    
    cout<<"pop"<<endl;
    while(!empty(root)){
        temp=top(root);
        cout<<temp->info<<" was eliminated"<<endl;
        pop(root);
    }

    return 0;
}

//FUNTION IMPLEMENTATIONS
//receives the address of a Stack * pointer in list and inserts in front
void push(Stack &list, bNode *val){
    Stack neweishon=new Node; /* Create a new Node */
    neweishon->info=val;
    neweishon->next=NULL;
    /* insert the new Node at the beginning of the list */
    neweishon->next=list;
    /* now the beginning of the list is the new Node */
    list=neweishon;
}

void pop(Stack &list){ //removes at the front of the list
    Stack tempo=NULL;
    if(!empty(list)){ //list points to the beginning of the list
        tempo=list;
        list=list->next; //list points to the next Node
    }
    return;
}

bNode *top(Stack list){ 
    if(!empty(list)){ //list points to the beginning of the list
        return list->info;
    }
    return NULL;
}

bool empty(Stack list){
    return(list==NULL); //list equal to null
}
