// Author: reDragonCoder
//Union example

//LIBRARIES
#include <iostream>
#include <string.h>

//NAMESPACE
using namespace std;

//UNION DECLARATION
union Formula1{
    char namePilot[30];
    int prizes;
    float times;
    char nation[30];
};

//MAIN
int main(){
    //VARIABLES
    Formula1 redbull;
    strcpy(redbull.nation, "Mexico");
    redbull.prizes=5;
    redbull.times=0.29;

    cout<<"Pilot name: "<<redbull.namePilot<<endl;
    cout<<"Amount of prizes: "<<redbull.prizes<<endl;
    cout<<"Times: "<<redbull.times<<endl;
    cout<<"Nationality: "<<redbull.nation<<endl;

    return 0;
}
