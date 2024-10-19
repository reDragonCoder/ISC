//Clases Anidadas - Creando una lista enlazada simple

//LIBRARIES
#include <iostream>
#include <stdlib.h>

//NAMESPACE
using namespace std;

//CLASSES
class List{
    public: 
        /*La clase nodo se considera un atributo de la clase lista, 
        la colocamos en la parte publica para no tener que
        implementar metodos get y set para atributos num y *next
        Coloco primero la clase Nodo porque posteriormente tengo 
        declaraciones de punteros del tipo Nodo*/
        class Node{
            public:
                int num; //atributo de la clase Node
                Node *next; //atributo de la clase Node

                Node(int num){
                    this->num=num;
                    this->next=NULL;
                }
        }; //fin clase Node

    private:
        Node *start; //atributo de la clase List
        Node *end; //atributo de la clase List

    public:
        List(){ //constructor de la clase List
            start=end=NULL;
        }

        void insertStart(int n){
            Node *aux;
            aux=new Node(n);
            if(start==NULL){
                start=end=aux;
            }else{
                aux->next=start;
                start=aux;
            }
        }

        void print(){
            if(start==NULL){
                cout<<endl<<"Empty pile... It's not posible to print it";
            }else{
                Node *aux=start;
                cout<<endl<<"Pile ------------> ";
                while(aux!=NULL){
                    cout<<aux->num<<" - ";
                    aux=aux->next;
                }
            }
            cout<<endl<<endl;
        }

        void deleteStart(){
            if(start==NULL){
                cout<<endl<<"Empty pile... It's not posible to delete";
            }else{
                if(start->next==NULL){
                    cout<<endl<<"There's only one node left..."<<endl;
                    cout<<"Deleting last node..."<<endl;
                    delete(start);
                    start=end=NULL;
                }else{
                    Node *aux;
                    aux=start;
                    start=aux->next;
                    delete(aux);
                    cout<<endl<<"Deleting at the beginning...";
                }
            }
        }
}; //fin de la clase List

//MAIN
int main(){
    List myList;
    int opt, num;

    //NAME & DATA
    cout<<endl<<"\033[1;35mCESAR ANDRES ZULETA MALANCO  ID:300077\033[0m"<<endl;

    List::Node *aux, *bsq; //como Nodo esta dentro de la clase lista, el tipo de dato se manda llamar con el operador de alcance (::)
    
    do{
        cout<<endl<<"**************************************************";
        cout<<endl<<"Stack implementation with \nSIMPLE LINKED LISTS\n";
        cout<<endl<<"(push) Insert start......................1";
        cout<<endl<<"(pop)  Delete start......................2";
        cout<<endl<<"       Exit..............................3";
        cout<<endl<<"\nSelect one option: ";
        cin>>opt;
        cout<<endl<<"**************************************************";
        switch(opt){
            case 1:{
                cout<<endl<<"Give me the number to insert: ";
                cin>>num;
                myList.insertStart(num);
                myList.print();
                break;
            }
            case 2:{
                myList.deleteStart();
                myList.print();
                break;
            }
            case 3:{
                cout<<endl<<"Leaving the program...";
                break;
            }
            default:{
                cout<<endl<<"Invalid option, try again..."<<endl;
                break;
            }
        }
    }while(opt!=3);

    cout<<endl;

    return 0;
}