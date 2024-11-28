// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <set>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    set<string> setS;
    string temp;

    cout<<"Write words and press * when you're done"<<endl;
    do{
        cin>>temp;
        if(temp!="*"){
            setS.insert(temp);
        }
    }while(temp!="*");

    cout<<endl<<"Words in the set: "<<endl;
    for(auto var:setS)
        cout<<var<<endl;

    return 0;
}