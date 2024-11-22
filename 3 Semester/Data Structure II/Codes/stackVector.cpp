// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <stack>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    vector<stack<string>> stacks(4); // 4 stacks

    int n;
    string str;

    //Fill the stacks
    for(int i=0; i<stacks.size(); i++){  
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>str;
            stacks[i].push(str);
        }
    }

    //Print the stacks
    for(int i=0; i<stacks.size(); i++){  
        cout<<"Stack " <<(i + 1)<<" with "<<stacks[i].size()<<" elements"<<endl; 
        while (!stacks[i].empty()){
            string s=stacks[i].top();
            cout<<s<<endl;
            stacks[i].pop();
        }
        cout<<endl;
    }

    return 0;
}

