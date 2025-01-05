// Author: reDragonCoder
//Write a function that receives an integer as a parameter. The function must verify that the value has at most 5 digits.
// If the condition is met, it must return the sum of the digits.

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
void addition(int);

//MAIN
int main(){
    //VARIABLES
    int number=0;

    cout<<"Enter your number: ";
    cin>>number;

    if(number>=0 && number<=99999){
        addition(number);
    }else{
        cout<<"Your number is not valid!";
    }

    return 0;
}

//IMPLEMENTATIONS
void addition(int number){
    int aux=0;
    for(int i=0; i<5; i++){
        aux+=number%10;
        number/=10;
    }
    cout<<aux;
}