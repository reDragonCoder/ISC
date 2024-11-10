// Author: reDragonCoder

/*
    This program prints the breadth-first search (BFS) 
    path for a directed graph
*/

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <queue>

//NAMESPACE
using namespace std;

//FUNCTIONS
void BFS(int s, vector<list<int>> &graph, vector<bool>visited){
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int node=q.front();
        cout<<node+1<<" ";
        q.pop();

        for(int neigh:graph[node]){
            if(!visited[neigh]){
                visited[neigh]=true;
                q.push(neigh);
            }
        }
    }
}

//MAIN
int main(){
    int t=0, nodes=0, e=0;
    do{
        cout<<"Enter the number of testcases: ";
        cin>>t;
        if(t<=0 || t>100){
            cout<<"Enter a valid number of testcases between 1 and 100"<<endl;
        }
    }while(t<=0 || t>100);
    
    for(int k=0; k<t; k++){
        do{
            cout<<"Enter the number of edges: ";
            cin>>e; 
            if(e<=0 || e>100){
                cout<<"Enter a valid number of edges between 1 and v*(v-1)"<<endl;
            }
        }while(e<=0 || e>100);

        do{
            cout<<"Enter the number of nodes: ";
            cin>>nodes; 
            if(nodes<=0 || nodes>100){
                cout<<"Enter a valid number of nodes between 1 and 100"<<endl;
            }
        }while(nodes<=0 || nodes>100);
        
        vector<list<int>> graph(nodes);
        vector<bool> visited(nodes,false);

        for(int i=0; i<e; i++){
            int u, v;
            cout<<"Enter the "<<i+1<<" pair of nodes (u, v): ";
            cin>>u>>v;
            graph[u-1].push_back(v-1);
        }

        cout<<endl;
        BFS(0, graph, visited);
    }
    return 0;
}
