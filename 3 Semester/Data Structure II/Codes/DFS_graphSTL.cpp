// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>

//NAMESPACE
using namespace std;

//FUNCTIONS
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void recursiveDFS(int u, vector<int> adj[], vector<bool> &visited){
    visited[u]=true;
    cout<<u<<" ";
    for(int i=0; i<adj[u].size(); i++)
        if(visited[adj[u][i]]==false)
            recursiveDFS(adj[u][i], adj, visited);
}

void unvisitedDFS(vector<int> adj[], int n){
    vector<bool> visited(n, false);
    for(int u=0; u<n; u++)
        if(visited[u]==false)
            recursiveDFS(u, adj, visited);
}

//MAIN
int main(){
    int t=0, n=0, e=0, u=0, v=0;

    do{
        cout<<"Enter the number of testcases: ";
        cin>>t;
        if(t<1 || t>100){
            cout<<"Enter a valid number of testcases between 1 and 100"<<endl<<endl;
        }
    }while(t<1 || t>100);
    while(t--){
        do{
            cout<<"Enter the number of nodes & edges: ";
            cin>>n>>e;
            if(n<1 || n>100){
                cout<<"Enter a valid number of nodes between 1 and 100"<<endl<<endl;
            }
        }while(n<1 || n>100);
        vector<int> adj[n];
        for(int i=0; i<e; i++){
            cout<<"Enter the "<<i+1<<" pair: ";
            cin>>u>>v;
            addEdge(adj, u, v);
        }
        
        cout<<endl;
        unvisitedDFS(adj, n);
        cout<<endl<<endl;
    }
    return 0;
}