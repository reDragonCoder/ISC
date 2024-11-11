// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

// CLASSES
template <class Type>
class Node{
    public:
        Type task;
        Node* next;
        Node(Type t):task(t), next(NULL){}
};

template <class Type>
class Queue {
    private:
        Node<Type> *frontQueue; 
        Node<Type> *backQueue;   
        int items;

    public:
        Queue():frontQueue(NULL), backQueue(NULL), items(0){}

        inline void push_back(Type x) {
            Node<Type> *newNode=new Node<Type>(x);
            if(this->frontQueue==NULL){
                frontQueue=backQueue=newNode;
            }else{
                backQueue->next=newNode;
                backQueue=newNode;
            }
            this->items++;
        }

        inline Type pop_front(){
            Node<Type> *temp=NULL;
            if(this->frontQueue!= NULL){
                temp=this->frontQueue;
                frontQueue=frontQueue->next;
                if(frontQueue==NULL){
                    backQueue=NULL;  
                }
                Type x=temp->task;
                delete temp;
                this->items--;
                return x;
            }else{
                cout<<"Queue is empty";
            }
        }

        inline Type& front(){
            if (frontQueue!=NULL) {
                return frontQueue->task;
            }else{
                cout<<"Queue is empty";
            }
        }

        inline bool empty(){
            return (this->frontQueue==NULL);
        }

        inline int size(){
            return this->items;
        }
};

//MAIN
int main(){
    Queue<int> queue;

    queue.push_back(7);
    queue.push_back(10);
    queue.push_back(15);

    cout<<queue.front() << endl; 
    queue.pop_front();
    cout<<queue.front() << endl;
    queue.pop_front();
    cout<<queue.front() << endl;
    queue.pop_front();
    return 0;
}
