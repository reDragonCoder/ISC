// Author: reDragonCoder

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
template <class Type> class Node{
    public:
        Type info;
        Node *next;
        Node(Type dato):info(dato), next(NULL){}
};

template <class Type> class Pile{
    private:
        Node <Type> *topeishon;
        int elementNo;
    public:
        Pile():topeishon(NULL){
            this->elementNo=0;
        }

        ~Pile(){
            while(!this->empty())
            this->pop();
        }

        inline void push(Type x){
            Node<Type> *neweishon=new Node<Type>(x);
            neweishon->next=topeishon;
            this->topeishon=neweishon;
            this->elementNo++;
        }

        inline Type pop(){
            Node<Type> *temp=NULL;
            if(this->topeishon!=NULL){
                temp=this->topeishon;
                this->topeishon=temp->next;
            }
            Type x=temp->info;
            this->elementNo--;
            delete temp;
            return x;
        }

        inline Type top(){
            return topeishon->info;
        }
        inline bool empty(){
            return (this->topeishon==NULL);
        }
        inline int size(){
            return this->elementNo;
        }
};

// MAIN
int main(){
    Pile<int> p;
    int aux=0;
    p.push(5);
    p.push(6);
    cout<<p.top()<<endl;
    aux=p.size();
    cout<<aux<<endl;
    p.pop();
    cout<<p.top()<<endl;
    aux=p.size();
    cout<< aux;
}