// Author: reDragonCoder
//Recorrido de arreglos con notación de punteros pt. 2

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define TAM 6

//MAIN 
int main(){
    //VARIABLES
    int vecA[]={2,4,6,8,10,12}, *ptr=NULL;
    int vecB[]={1,3,5,7,9,11};

    //show the A content with ptr
    ptr=&vecA[0]; //enlazamos el ptr con vecA fuera de la declaracion
    cout<<"Content: *(ptr+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<*(ptr+i)<<"\t"; 
    }
    cout<<endl<<endl;
    //show memory directions with ptr
    cout<<"Memory dir: (ptr+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<(ptr+i)<<"\t"; 
    }
    cout<<endl<<endl;

    
    //show the B content with ptr
    ptr=&vecB[0]; //enlazamos el ptr con vecB fuera de la declaracion
    cout<<"Content: *(ptr+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<*(ptr+i)<<"\t"; 
    }
    cout<<endl<<endl;
    //show memory directions with ptr
    cout<<"Memory dir: (ptr+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<(ptr+i)<<"\t"; 
    }
    cout<<endl<<endl;


    return 0;
}