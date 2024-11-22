// Author: reDragonCoder

//LIBRARIES
#include <iostream> 
#include <queue>

//NAMESPACE
using namespace std; 
  
//FUNCTION
void print(queue <int> gq){ 
    queue <int> g=gq; 
    while(!g.empty()){ 
        cout<<'\t'<<g.front(); 
        g.pop(); 
    } 
    cout<<'\n'; 
} 

//MAIN 
int main(){ 
    queue <int> q;

    q.push(10); 
    q.push(20); 
    q.push(30); 

    cout<<"In queue: "; 
    print(q); 

    cout<<"\nq.size(): "<<q.size(); 
    cout<<"\nq.front(): "<<q.front(); 
    cout<<"\nq.back(): "<<q.back(); 
    cout<<"\nq.pop(): "; 
    q.pop(); 
    print(q); 
    
    return 0; 
} 
