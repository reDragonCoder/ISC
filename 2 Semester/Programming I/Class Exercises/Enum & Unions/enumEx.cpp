// Author: reDragonCoder
//Enum types

//LIBRARIES
#include <stdio.h>
#include <iostream>

//NAMESPACE
using namespace std;

//ENUM DECLARATION
enum Month{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

//PROTOTYPES
bool validDate(int, Month, int);
bool isLeap(int);

//MAIN
int main(){
    //VARIABLES
    int dd, yy;
    Month mm;

    cout<<"Enter date: "<<endl;
    cout<<"Day: ";
    cin>>dd;
    cout<<"Month: ";
    scanf("%d", (int*)&mm); 
    cout<<"Year: ";
    cin>>yy;

    if(validDate(dd, mm, yy)){
        cout<<"The date is valid!"<<endl;
    }else{
        cout<<"Non-valid date"<<endl;
    }

    return 0;
}

//IMPLEMENTATIONS
bool validDate(int dd, Month mm, int yy){
    if(mm<JAN || mm>DEC)
        return false;
    
    switch(mm){
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG: 
        case OCT:
        case DEC: 
            if(dd<1 || dd>31)
                return false;
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            if(dd<1 || dd>30)
                return false;
            break;
        case FEB:
            if(isLeap(yy)){
                if(dd<1 || dd>29)
                    return false;
            }else{
                if(dd<1 || dd>28)
                    return false;
            }
            break;
    }
    return true;
}

bool isLeap(int yy){
    if((yy%4==0 && yy%100!=0)||(yy%400==0))
        return true;
    else   
        return false;
}