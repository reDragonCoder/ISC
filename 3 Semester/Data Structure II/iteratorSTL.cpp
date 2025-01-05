// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    vector<string> languages={"Python", "C++", "Java"};

    //create an iterator to a string vector
    vector<string>::iterator itr;

    //iterator over all elements
    for(itr=languages.begin(); itr!=languages.end(); itr++){
        cout<<*itr<<", ";
    }

    return 0;
}

