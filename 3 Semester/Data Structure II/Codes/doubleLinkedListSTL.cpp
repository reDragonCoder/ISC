// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <list>
#include <string>

//NAMESPACE
using namespace std;

//FUNCTION
bool compare(const string &a, const string &b){
    return a.length()<b.length();
}

//MAIN
int main(){
    list<string> myList{"zocalo", "agua", "abarrote"};
    myList.sort();
    for(auto it=myList.begin(); it!=myList.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    myList.sort(compare);
    for(auto it=myList.begin(); it!=myList.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}