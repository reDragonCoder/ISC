// Author: reDragonCoder
//calloc 

//LIBRARIES
#include <iostream>
#include <stdlib.h> //for memory

//NAMESPACE
using namespace std;

//MAIN
int main(){
    //VARIABLES
    int *vec=NULL, size;
    char *name;

    //get the size of the array
    cout<<"Array size: ";
    cin>>size;
    //before using the variables is important to allocate memory
    vec=(int*)calloc(size,sizeof(int));
    name=(char*)calloc(15,sizeof(char));
    cout<<"Name: ";
    cin>>name;
    for(int i=0; i<size; i++){
        cout<<"Value "<<i<<": ";
        cin>>*(vec+i); //pointers notation (vec[i])
    }
    for(int i=size-1; i>=0; i--){
        cout<<vec[i]<<"\t";
    }
    
    return 0;
}