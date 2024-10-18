// Author: reDragonCoder
//Write a program that takes two integer numbers as input and make the sum, sustraction, multiplication and division with them

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
int substraction(int, int);
void multiplication(int, int);
int sum();
void division();

//MAIN
int main(){
    //VARIABLES
    int num1=0, num2=0, showSum=0, showSubstraction=0;

    cout<<"Hello User, please enter your first number: ";
    cin>>num1;
    cout<<"Please enter your second number: ";
    cin>>num2;

    //the function recives two numbers captured in the main that are sended as parameters and the result is saved in the variable to show it
    showSubstraction=substraction(num1, num2);
    cout<<"Friend, the result of your substraction is: "<<showSubstraction<<endl;

    //the function recives two numbers captured in the main that are sended as parameters but the result is shown directly from the function
    multiplication(num1, num2);

    //the function returns a value, saves it in a variable and that variable is used to display the result directly in the main
    showSum=sum();
    cout<<"Friend, the result of your sum is: "<<showSum<<endl;

    //the function does all the tasks inside it
    division();

    return 0;
}

//IMPLEMENTATIONS
int substraction(int num1, int num2){
    int result=0;
    result=num1-num2;
    return result;
}

void multiplication(int num1, int num2){
    int result=0;
    result=num1*num2;
    cout<<"Friend, I'm your multiplication function, your result is: "<<result<<endl;
}

int sum(){
    int num1=0, num2=0, result=0;
    cout<<"Hi, I'm your sum function, please enter two numbers: "<<endl;
    cin>>num1;
    cin>>num2;
    result=num1+num2;
    return result;
}

void division(){
    int num1=0, num2=0, result=0;
    cout<<"Hello again friend, I'm your division function, please enter your first number: ";
    cin>>num1;
    cout<<"Please enter your second number: ";
    cin>>num2;
    result=num1/num2;
    cout<<"Your result is: "<<result<<endl;
}