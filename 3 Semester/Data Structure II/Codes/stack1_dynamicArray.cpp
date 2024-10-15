// Author: reDragonCoder
//NODE STACK IMPLEMENTED WITH A DYNAMIC ARRAY

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTS
struct Node{
   char value;
   Node *left, *right;
};

//DATA TYPE DEFINITION
typedef Node *pnode;

struct Stack{ //structure for the stack
   int topeishon; //top of the stack
   int max; //maximum stack elements
   pnode* array; //dynamic array
};

//FUNCTIONS
void makeStack(Stack &ps, int n){
   ps.max=n;
   ps.topeishon=-1;
   ps.array=new pnode[n];
}

bool overFlow(Stack &ps){ //full stack
   return(ps.topeishon==ps.max-1)? true:false;
}

void push(Stack &ps, pnode elem){ 
   if(overFlow(ps)){ //check overflow
      cout<<"Full stack!"<<endl;
      return;
   }
   ps.array[++(ps.topeishon)]=elem; //insert element on stack
   return;
}

bool empty(Stack &ps){ //empty pile
   return (ps.topeishon==-1)?true:false;
}

void pop(Stack &ps){
   if(empty(ps)){ //check low flow
      cout<<"Empty stack!"<<endl;
      return;
   } 
   ps.topeishon--;
   return; //extract the element from the pivot
}

pnode top(Stack &ps){ //shows the top of the stack 
   if(empty(ps)){ //Check that it does not occur under flow by stack emptyStack
      cout<<"Empty stack!"<<endl;
      return NULL;
   } 
   return ps.array[ps.topeishon]; //extract the element from the pivot
}

//MAIN
int main(){
   Stack s;
   makeStack(s,5);
   pnode t1, t2, t3;
   t1=new Node;
   t1->value='A';
   t2=new Node;
   t2->value='B';
   t3=new Node;
   t3->value='C';
   push(s, t1); //we insert the element x
   push(s, t2);
   push(s, t3);
   while(!empty(s)){
      pnode aux=top(s);
      cout<<"topeishon -> "<<aux->value<<endl;
      pop(s); //we extract the element from the pivot
   }

   return 0;
}
