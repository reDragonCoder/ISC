// Author: reDragonCoder
//Write a program that calculates the area and perimeter of a rectangle. The sides of the rectangle must be entered by the user.

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//PROTOTYPES
float area(float, float);
void perimeter(float, float);

//MAIN
int main(){
    //VARIABLES
    float base=0, height=0, showArea=0;

    cout<<"Enter the base of the rectangle: ";
    cin>>base;
    cout<<"Enter the height of the rectangle: ";
    cin>>height;
    if(base==height){
        cout<<"That's not a rectangle";
    }else{
        showArea=area(base, height);
        cout<<"The rectangle area is: "<<showArea<<" cm2"<<endl;
        perimeter(base, height);
    }
    
    return 0;
}

//IMPLEMENTATIONS
float area(float base, float height){
    float result=0;
    result=base*height;
    return result;
}

void perimeter(float base, float height){
    float result=0;
    result=2*(base+height);
    cout<<"The rectangle perimeter is: "<<result<<" cm";
}
