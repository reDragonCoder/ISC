// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <set>

//NAMESPACE
using namespace std;

//FUNCTIONS
set<string> operator&(set<string> set1, set<string> set2){
    set<string> temp;
    for(auto i:set1){
        auto here=set2.find(i);
        if(here!=set2.end()){
            temp.insert(i);
        }
    }
    return temp;
}

set<string> operator|(set<string> set1, set<string> set2){
    for(auto i:set2){
        set1.insert(i);
    }
    return set1;
}

//MAIN
int main(){
    set<string> set1={"Minecraft", "COD", "Cesar", "Targaryen"};
    set<string> set2={"Cesar", "Stardew", "Star", "Targaryen"};
    set<string> temp;

    cout<<"Original set 1: "<<endl;
    for(auto i:set1){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"Original set 2: "<<endl;
    for(auto i:set2){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"Intersection set: "<<endl;
    temp=set1&set2;
    for(auto i:temp){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    cout<<"United set: "<<endl;
    temp=set1|set2;
    for(auto i:temp){
        cout<<i<<" ";
    }
    cout<<endl<<endl;

    return 0;
}