// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

//NAMESPACE
using namespace std;

//FUNCTION
void print(queue<int> gq){
    queue<int> g=gq;
    while(!g.empty()){
        cout<<g.front()<<" ";
        g.pop();
    }
    cout<<endl;
}

//MAIN
int main(){
    long long int n, temp;
    queue<int> wait;
    stack<int> icecream;

    cin>>n;  
    vector<int> result(n, 0);

    cout<<"Flavor desires: " << endl;
    for(int i=0; i<n; i++){
        cin>>temp;
        wait.push(temp); 
    }

    cout<<"Icecream flavor order: " << endl;
    for(int i=0; i<n; i++){
        cin>>temp;
        icecream.push(temp); 
    }

    int personIndex=0;  
    while(!icecream.empty()){
        if(icecream.top()==wait.front()){
            icecream.pop(); 
            wait.pop(); 
            result[personIndex]++;  
        }else{
            int temp=wait.front();
            wait.pop();
            wait.push(temp);
        }

        personIndex++;
        if(personIndex==n){
            personIndex=0;  
        }
    }

    cout<<"Results: "<<endl;
    result[n-1]=result[n-1]-1;
    for(int i=0; i<n; i++){
        cout<<result[i]<< endl;
    }

    return 0;
}