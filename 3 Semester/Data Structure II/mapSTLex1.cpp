// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <map>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    string tempWord;
    map<string, int> map1;
    map<string, int>::iterator cursor;

    cout<<"Write words and press * when you're done"<<endl;
    do { 
        cin>>tempWord;
        if(tempWord!="*") {
            auto it=map1.find(tempWord);
            if(it!=map1.end()) {
                it->second++;
            }else{
                map1[tempWord]=1;
            }
        }
        
    }while(tempWord!="*");

    cout<<endl;
    cout<<"KEY\tELEMENT"<<endl;
    for(auto i:map1){
        cout<<i.first;
        cout<<'\t'<<i.second<<'\n'
             <<endl;
    }

    return 0;
}