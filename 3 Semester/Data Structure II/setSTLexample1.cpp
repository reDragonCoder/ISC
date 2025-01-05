// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <set> 

//NAMESPACE
using namespace std;

//MAIN
int main(){
    set<string> set1({"1", "2", "5", "23", "6", "290"});
  
    cout<<"Added elements: "<<endl;
    for(auto val: set1)
        cout<<val<< endl;
    auto y=set1.find("2");
    auto x=set1.erase(*y);
    cout<<"We find "<<*y<<" & we eliminate the position "<<x<<endl;
    set1.insert("100");
    set1.insert("50");
    cout<<"We insert"<<endl;
    for(auto val:set1)
        cout <<val<<endl;

    set<string, greater <string>> set2({"1", "2", "5", "23", "6", "290"});
  
    cout<<endl<<"Added elements"<<endl;
    for(auto val:set2)
        cout<<val<<endl;

    return 0;
}

