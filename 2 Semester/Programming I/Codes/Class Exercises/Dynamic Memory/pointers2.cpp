// Author: reDragonCoder
//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define TAM 6

//MAIN 
int main(){
    //VARIABLES
    int vecA[]={2,4,6,8,10,12};

    cout<<"Content: *(vecA+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<*(vecA+i)<<"\t"; //the array name by itself is the memory direction (same as ptr)
    }
    cout<<endl<<endl;

    //show memory directions with ptr
    cout<<"Memory dir: (vecA+i) \n";
    for(int i=0; i<TAM; i++){
        cout<<(vecA+i)<<"\t"; 
    }
    cout<<endl<<endl;


    return 0;
}