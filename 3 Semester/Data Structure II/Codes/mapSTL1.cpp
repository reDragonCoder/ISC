// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <map>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    map<string, char> map1;
    map<string, char>::iterator cursor;

    map1["dishes"]='a';
    map1["tables"]='b';

    cout<<"Original container"<<endl;
    cout<<"key\telement"<<endl;
    for(cursor=map1.begin(); cursor!=map1.end(); cursor++){
        cout<<cursor->first;
        cout<<'\t'<<cursor->second << '\n'
             <<endl;
    }
    map1.insert({"tablecloths", 'c'});

    cout<<"Updated container"<<endl;
    cout<<"key\telement"<<endl;
    for(auto i:map1){
        cout<<i.first;
        cout<<'\t'<<i.second<<'\n'
             <<endl;
    }
}


