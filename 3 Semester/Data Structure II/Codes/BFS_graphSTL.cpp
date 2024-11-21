// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <queue>

//NAMESPACE
using namespace std;

//CONSTANTS
vector<bool> vec;
vector<vector<int>> graph;

//FUNCTIONS
void addEdge(int u, int v){
    graph[v].push_back(v);
    //for undirected graph
    // + g[v].push_back(u);
}

void BFS(int u){
    queue<int> q;
    
    q.push(u);
    vec[u]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";

        for(auto i=graph[front].begin();i!=graph[front].end(); i++){
            if(!vec[*i]){
                q.push(*i);
                vec[*i]=true;
            }
        }
    }
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
        vec.assign(n, false);
        graph.assign(n, vector<int>());
        for(int i=0; i<e; i++){
            cout<<"Enter the "<<i+1<<" pair: ";
            cin>>u>>v;
            addEdge(u, v);
        }
        cout<<endl;
        for(int i=0; i<n; i++){
            if(!vec[i])
                BFS(i);
        }
        cout<<endl<<endl;
    }
    return 0;
}