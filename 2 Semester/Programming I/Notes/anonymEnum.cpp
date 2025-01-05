// Author: reDragonCoder
//Anonym enumeration (there's only anonym enumerations)

//LIBRARIES
#include <iostream>

//GLOBAL CONSTANT
#define TOT 4

//NAMESPACE
using namespace std;

//MAIN
int main(){
    //ENUM DECLARATION
    //it's most common to see int enumerations than other with another data type
    //the enumerations takes consecutives values (ascending order - ordinal numbers)
    enum{REG, IRREG, VOLDIS, DEFDIS}; 
    char vec[][30]={"Regular", "Irregular", "Voluntary discharge", "Definitive discharge"};

    return 0;
}