// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
template <class Type> class Node{
    public: 
        Type task;
        Node*next;
        Node(Type t):task(t), next(NULL){} 
};

template <class Type> class Queue{
    private: 
        Node<Type> *frontQueue;
        Node<Type> *backQueue;
        int items;
    public:
        Queue():frontQueue(NULL), backQueue(NULL), items(0){}

        inline void push_back(Type x){
            Node<Type> *neweishon=new Node<Type>(x);  
            if(this->frontQueue==NULL){  
                frontQueue=backQueue=neweishon;  
            }else{
                backQueue->next=neweishon; 
                backQueue=neweishon; 
            }
            this->items++; 
        }

        inline Type pop_front(){
            Node<Type> *tempo=NULL;
            if(this->frontQueue!=NULL) {
                tempo=this->frontQueue;
                this->frontQueue=frontQueue->next;  
                if (this->frontQueue==NULL){ 
                    backQueue=NULL;
                }
                this->items--;
            }
            Type x=tempo->task;
            delete tempo;
            return x;
        }

        inline Type &front(){
            return frontQueue->task;
        }

        inline bool empty(){
            return (this->frontQueue==NULL);
        }

        inline int size(){
            return this->items;
        }
};

int main(){
    Queue <int> queue;

    queue.push_back(7);
    queue.push_back(11);
    queue.push_back(3);
    queue.push_back(6);

    while(!queue.empty()){
        cout<<queue.front()<<endl;
        queue.pop_front();
    }

    return 0;
}
