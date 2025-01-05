// Author: reDragonCoder
// A program that determines if there is at least one vertex within the graph 
// that is not connected using an adjacency list

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <queue>

//NAMESPACE
using namespace std;

//FUNCTIONS
void createGraph(vector<list<int>> &adj, int edges){
    int org, dest;
    while(edges--){
        //directed graph
        /*cout<<"Enter the origin & destination node: ";
        cin>>org>>dest;
        adj[org].push_back(dest);*/

        //non-directed graph
        cout<<"Enter the origin & destination node: ";
        cin>>org>>dest;
        adj[org].push_back(dest);
        adj[dest].push_back(org);
    }
    return;
}

bool connected(vector<list<int>> &adj){
    bool connected=true;
    for(int i=0; i<adj.size(); i++){
        if(adj[i].empty()){
            cout<<endl;
            cout<<"The node "<<i<<" doesn't have any connection"<<endl;
            connected=false;
        }
    }
    return connected;
}

//MAIN
int main(){
    int nodes, edges;
    bool isConnected;

    cout<<"Enter the number of nodes in your graph: ";
    cin>>nodes;
    cout<<"Enter the number of edges in your graph: ";
    cin>>edges;
    cout<<endl;

    vector<list<int>>adjList;
    adjList=vector<list<int>>(nodes);
    createGraph(adjList, edges);
    isConnected=connected(adjList);
    if(isConnected==true){
        cout<<endl;
        cout<<"All nodes in the graph are connected";
    }else{
        cout<<endl;
        cout<<"There is at least one node that is not connected in the graph as shown above";
    }

    return 0;
}