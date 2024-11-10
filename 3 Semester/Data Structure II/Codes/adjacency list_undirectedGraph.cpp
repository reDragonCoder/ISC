// Author: reDragonCoder

/*
    This program receives a bidirectional (undirected) graph and prints the 
    adjacency list for each vertex
 */

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <queue>

//NAMESPACE
using namespace std;

//MAIN
int main(){
    int t=0, v=0, e=0, org, dest;
    vector<list<int>>adj;

    do{
        cout<<"Enter the number of testcases: ";
        cin>>t;
        if(t<=0 || t>200){
            cout<<"Enter a valid number of testcases between 1 and 200"<<endl;
        }
    }while(t<=0 || t>200);
    
    for(int k=0; k<t; k++){
        do{
            cout<<"Enter the number of nodes: ";
            cin>>v;
            if(v<=0 || v>100){
                cout<<"Enter a valid number of nodes between 1 and 100"<<endl;
            }
        }while(v<=0 || v>100);
        do{
            cout<<"Enter the number of edges: ";
            cin>>e; 
            if(e<=0 || e>v*(v-1)){
                cout<<"Enter a valid number of edges between 1 and v*(v-1)"<<endl;
            }
        }while(e<=0 || e>v*(v-1));
    
        adj=vector<list<int>>(v);

        while(e--){
            cout<<"Enter the origin and destination node: ";
            cin>>org>>dest;
            adj[org].push_back(dest);
            adj[dest].push_back(org);
        }
    }

    cout<<endl;

    for(int i=0; i<v; i++){
        cout<<i<<" -> ";
        for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
            cout<<*it<<" -> ";
        }
        cout<<endl;
    }
    return 0;
}