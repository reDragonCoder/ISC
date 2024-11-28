// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <set>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    set<char> a;

    a.insert('G');
    a.insert('F');
    a.insert('G');

    for(auto& str:a){
        cout<<str<<' ';
    }
    cout<<endl;

    return 0;
}
