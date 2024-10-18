// Author: reDragonCoder
//Write a function that performs a search for a value in an array. If the value is found, true is returned, otherwise false. 
//The array is called calif and is of real type, both values are received as parameters.

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANTS
#define MAX 5

//PROTOTYPES
bool isHere(float[], float);

//MAIN
int main(){
    float calif[MAX], number=0;
    bool flag=false;

    for(int i=0; i<MAX; i++){
        cout<<"Enter the ["<<i+1<<"] grade: ";
        cin>>calif[i];
    }
    cout<<endl;
    cout<<"Enter the number you're searching for: ";
    cin>>number;

    flag=isHere(calif, number);
    if(flag==true){
        cout<<endl;
        cout<<"The number ["<<number<<"] is here";
    }else{
        cout<<endl;
        cout<<"The number ["<<number<<"] is not here!";
    }

    return 0;
}

//IMPLEMENTATIONS
bool isHere(float calif[], float number){
    bool flag=false;
    for(int i=0; i<MAX; i++){
        if(calif[i]==number){
            flag=true;
        }else{
            flag=false;
        }
    }
    return flag;
}