// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <map>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    string tempWord;
    int counter=0;
    map<string, int> map1;           
    map<int, list<string>> map2;     

    cout<<"Write words and press '*' when you're done"<<endl;

    while(true){
        cin>>tempWord;
        if(tempWord=="*") break;   
        counter++;

        auto it=map1.find(tempWord);
        if(it!=map1.end()){
            int oldFrequency=it->second;
            it->second++;  
            map2[oldFrequency].remove(tempWord);
            map2[it->second].push_back(tempWord);
        }else{
            map1[tempWord]=1;
            map2[1].push_back(tempWord);
        }
    }

    for(auto cursor1=map2.begin(); cursor1!=map2.end(); cursor1++){
        cout<<"Frequency "<<cursor1->first<<": "<<endl;
        for(const string &name:cursor1->second){
            cout<<name<<"  "<<endl;
        }
        cout<<endl;
    }

    return 0;
}
