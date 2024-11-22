// Author: reDragonCoder
//double end queue

//LIBRARIES
#include <iostream>
#include <deque>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    deque<string> array;

    array.push_back("pablito");
    array.push_back("juanito");
    array.push_back("chenchito");

    for(int i=0; i<array.size(); i++)
        cout<<array[i]<<endl;

    string x=array.back();
    array.pop_back();
    cout<<"Deleting in the back: "<<x<<endl;

    x=array.front();
    array.pop_front();
    cout<<"Deleting in the front: "<<x<<endl;
    
    array.push_front("panchito");
    array.push_back("jorgito");

    for(int i=0; i<array.size(); i++)
        cout<<array[i]<<endl;
    cout<<"Front: "<<array.front()<<endl;
    cout<<"Back: "<<array.back();
}