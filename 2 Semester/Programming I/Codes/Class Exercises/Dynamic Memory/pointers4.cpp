// Author: reDragonCoder
//Recorrido de arreglos con notación de punteros pt. 3

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define TAM 6

//MAIN 
int main(){
    //VARIABLES
    int vecA[]={2,4,6,8,10,12}, *ptr=vecA; //enlazar puntero con vector dentro de la declaracion

    while(*ptr<=12){
        cout<<*ptr++<<"\t"; //position 0, then ++, position 1, then ++ ...
    }
    
    return 0;
}