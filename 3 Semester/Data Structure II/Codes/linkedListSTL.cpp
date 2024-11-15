// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <forward_list>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    forward_list<int> list;
    int tempVal=0;

    do{
        cout<<"Enter your node value: ";
        cin>>tempVal;
        if(tempVal!=0){
            list.emplace_front(tempVal);
        }
    }while(tempVal!=0);

    list.sort();

    cout<<endl;
    forward_list<int>::iterator it;
    for(it=list.begin(); it!=list.end(); it++)
        cout<<*it<<" -> ";
    cout<<endl;

    return 0;
}