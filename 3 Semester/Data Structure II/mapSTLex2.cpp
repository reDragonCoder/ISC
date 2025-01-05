// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iterator>
#include <map>
#include <list>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    int num;
    string tempWord;
    map<string, int> map1;
    map<string, int>::iterator cursor;

    cout<<"Write words and press * when you're done"<<endl;
    do{ 
        cin>>tempWord;
        if(tempWord!="*") {
            auto it=map1.find(tempWord);
            if(it!=map1.end()) {
                it->second++;
                num=it->second;
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

    list<string> list1, list2, list3;
    map<int, list<string>> mapNo1;
    map<int, list<string>> mapNo2;
    map<int, list<string>> mapNo3;

    for(auto i:map1){
        switch(i.second){
            case 1:
                list1.push_back(i.first);
                break;
            case 2:
                list2.push_back(i.first);
                break;
            case 3:
                list3.push_back(i.first);
                break;
        }
    }

    mapNo1.insert({1, list1});
    mapNo2.insert({2, list2});
    mapNo3.insert({3, list3});

    cout<<"Words that repeat themselves 1 time: ";
    for(auto word:mapNo1[1])
        cout<<word<<" ";
    cout<<endl<<endl;
    
    cout<<"Words that repeat themselves 2 times: ";
    for(auto word:mapNo2[2])
        cout<<word<<" ";
    cout<<endl<<endl;
    
    cout<<"Words that repeat themselves 3 times: ";
    for(auto word:mapNo3[3])
        cout<<word<<" ";
    cout<<endl<<endl;

    return 0;
}