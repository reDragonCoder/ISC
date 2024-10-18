// Author: reDragonCoder
//Write a program that converts a temperature in degrees Celsius to Fahrenheit (or vice versa).

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
void far_to_celsius();
float celsius_to_far(float);

//MAIN
int main(){
    //VARIABLES
    int opt=0;
    float celsius=0, farenheit=0;

    cout<<"MENU"<<endl;
    cout<<"Farenheit to Celsius...1"<<endl;
    cout<<"Celsius to Farenheit...2"<<endl;
    cout<<"Exit...................3"<<endl;
    cout<<"Please select one option: ";
    cin>>opt;

    do{
        switch(opt){
            case 1:
                far_to_celsius();
                break;
            case 2:
                cout<<"Enter the celsius temperature: ";
                cin>>celsius;
                farenheit=celsius_to_far(celsius);
                cout<<"The temperature in Farenheit is: "<<farenheit<<endl;
                break;
        }
        cout<<"Select another option: ";
        cin>>opt;
    }while(opt!=3);

    return 0;
}

//IMPLEMENTATION
void far_to_celsius(){
    float farenheit=0, result=0;
    cout<<"Enter the farenheit temperature: ";
    cin>>farenheit;
    result=(farenheit-32)*5/9;
    cout<<"The temperature in Celsius is: "<<result<<endl;
}

float celsius_to_far(float celsius){
    float result=0;
    result=(celsius*9/5)+32;
    return result;
}