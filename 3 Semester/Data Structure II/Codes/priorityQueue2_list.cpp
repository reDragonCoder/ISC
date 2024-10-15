// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//STRUCTS
struct Task{
   int priority;
   string name;
};

//CLASSES
class Node{
   private:
      Task info;
      Node *next;

   public:
      Node(Task val){
         info=val;
         this->next=NULL;
      }

      Task getTask(){return this->info;}
      void setTask(Task val){this->info=val;}
      Node* getnext(){ return this->next;}
      void setnext(Node *p){this->next = p;}
};

class ListPriority{
   private:
      Node* root;

   public:
      ListPriority(){root=NULL;}
      ~ListPriority();
      void insert(Task v);
      Task minElement();
      void eliminateMin();
      bool empty(){return root==NULL;}; 
};

ListPriority::~ListPriority(){
   Node* aux;
   while(root){
      aux=root;
      root=root->getnext();
      aux->setnext(NULL);
      delete aux;
   }
}

void ListPriority::insert(Task val){
   Node* pos=root, *prev=NULL;
   Node* neweishon=new Node(val);
   bool found=false;
   while(!found && pos!=NULL){
      if (pos->getTask().priority<=val.priority){
         prev=pos;
         pos=pos->getnext();
      }
      else
         found=true;
   }
   if(prev!=NULL)
      prev->setnext(neweishon);
   else
      root=neweishon;
   neweishon->setnext(pos);
}

Task ListPriority::minElement(){
   if(!empty())
      return root->getTask();
   Task t;
   t.priority=-1;
   t.name="Empty queue";
   return t;
}

void ListPriority::eliminateMin(){
   Node *aux;
   if(!empty()){
      aux=root;
      root=aux->getnext();
      aux->setnext(NULL);
      delete aux;
   }
   else
      cout<<"Empty queue";
}

int main(){
   ListPriority* l=new ListPriority();
   Task t;
   t.name="A";
   t.priority=5;
   l->insert(t);
   t.name="B";
   t.priority=7;
   l->insert(t);  
   t.name="C";
   t.priority=2;
   l->insert(t); 
   while(!l->empty()){
      cout << l->minElement().name;
      l->eliminateMin();
   }
}
