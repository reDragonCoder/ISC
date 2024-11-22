// Author: reDragonCoder

//LIBRARIES
#include <iostream> 
#include <stack> 

//NAMESPACE
using namespace std; 
  
//FUNCTION
void showstack(stack <int> s){ 
    while(!s.empty()){ 
        cout<<'\t'<<s.top(); 
        s.pop(); 
    } 
    cout<<endl; 
} 

//MAIN
int main(){ 
    stack<int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 

    cout<<"Stack elements: "; 
    showstack(s);   

    cout<<"\ns.size(): "<<s.size(); 
    cout<<"\ns.top(): " <<s.top();
    cout<<"\ns.pop(): "<<endl; 
    s.pop(); 
    showstack(s); 
    
    return 0; 
} 
