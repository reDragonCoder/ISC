// Author: reDragonCoder

//NOTE: Multimaps allow keys to be repeated, although the access operator [ ] is not available

//LIBRARIES
#include <iostream>
#include <iterator>
#include <map>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    multimap<string, char> map1;
    multimap<string, char>::iterator cursor;

    map1.insert({"dishes", 'a'});
    map1.insert({"tables", 'b'});
    cout<<"Original containers"<<endl;
    cout<<"key\telement"<<endl;
    for(cursor=map1.begin(); cursor!=map1.end(); cursor++){
        cout<<cursor->first;
        cout<<'\t'<<cursor->second<<'\n'
             <<endl;
    }
    map1.insert({"dishes", 'd'});
    map1.insert({"tableclothes", 'c'});
    cout<<"Uptaded container"<<endl;
    cout<<"key\telement"<<endl;
    for(auto i:map1){
        cout<<i.first;
        cout<<'\t'<<i.second<<'\n'
             <<endl;
    }
}
