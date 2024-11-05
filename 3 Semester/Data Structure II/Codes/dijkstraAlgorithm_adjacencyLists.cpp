// Author: reDragonCoder
//DIJKSTRA ALGORITHM WITH ADJACENCY LISTS

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

//NAMESPACE
using namespace std;
 
//FUNCTIONS
vector<int> shortpath(vector <pair<int, int> > adj[], int s, int t, vector<int> & precedes, int vertices){
    //vector initialization
    vector<int> distance( vertices, INT_MAX );
    vector<bool> visited( vertices, false );
    distance[s]=0;
    int n=vertices-1;
    for(int i=0; i<n; i++){
        int min=INT_MAX, index=0;
        for(int i=0; i<vertices;i++)
            if(distance[i]<=min && visited[i]==false){
                min=distance[i];
                index=i;
            }
        int u=index;
        visited[u]=true;
        for(vector <pair <int, int> > :: iterator it=adj[u].begin(); it!=adj[u].end(); it++){
            if(visited[it->first]==false && distance [u]!=INT_MAX && distance[it->first]>distance[u]+it->second)
                distance[it->first]=distance[u]+it->second;
        }
    }
    return distance;
} 

// To add an edge
void addEdges(vector <pair<int, int> > *adj,int edges){
    int u=0, v=0, wgt=0;
    while (edges--){
        cout<<"Start Node: ";
        cin>>u;
        cout<<"End Node: ";
        cin>>v;
        cout<<"Weight: ";
        cin>>wgt;
        adj[u].push_back(make_pair(v, wgt));
        //adj[v].push_back(make_pair(u, wgt));
    }
}
 
// Print adjacency list representation of graph
void printGraph(vector <pair<int, int> > adj[], int vertices){
    int v, w;
    for(int u=0; u<vertices; u++){
        cout<<"Node "<<u<<" makes an edge with \n";
        for(auto it=adj[u].begin(); it!=adj[u].end(); it++){
            v=it->first;
            w=it->second;
            cout<<"\tNode "<<v<<" with edge weight "<<w<<"\n";
        }
        cout<<"\n";
    }
}

//MAIN 
// Driver code
int main(){
    int vertices=0, edges=0, s=0, t=0;
    cout<<"How many vertices does the graph have?: ";
    cin>>vertices;
    cout<<"How many edges does the graph have?: ";
    cin>>edges;
    vector<pair<int, int> > *adjList=new vector <pair<int, int> > [vertices];
    addEdges(adjList,edges);
    printGraph(adjList, vertices);
    
    cout<<"Please introduce the start and target vertices respectively: ";
    cin>>s>>t;
    vector<int> precedes(vertices,-1);
    vector<int> distance=shortpath(adjList, s, t, precedes, vertices);
    for(int i=0; i<distance.size(); i++)
        cout<<distance[i]<<" ";
    return 0;
}