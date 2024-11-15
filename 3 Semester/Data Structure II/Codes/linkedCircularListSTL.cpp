// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <forward_list>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    forward_list<int> circularList;
    int t=0, n=0, tempVal=0, deletedNode=0;

    cout<<"Enter the number of testcases: ";
    cin>>t;
    for(int i=0; i<t; i++){
        cout<<endl<<"Enter the number of values: ";
        cin>>n;
        cout<<"--- Enter the values ---"<<endl;
        for(int j=0; j<n; j++){
            cin>>tempVal;
            circularList.emplace_front(tempVal);
        }
        
        cout<<"Circular list before deletion (reversed): ";
        for(int &c:circularList)
            cout<<c<<" ";
        cout<<endl;

        cout<<endl<<"Enter the value you want to delete: ";
        cin>>deletedNode;
        circularList.remove(deletedNode);
        cout<<"Circular list after deletion (reversed): ";
        for(int &c:circularList)
            cout<<c<<" ";
        cout<<endl;
    }

    return 0;
}