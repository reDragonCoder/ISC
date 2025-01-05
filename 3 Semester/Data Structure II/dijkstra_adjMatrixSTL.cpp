// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <limits.h>

//NAMESPACE
using namespace std;

//FUNCTION
vector<int> dijkstra(const vector<vector<int>> &weights, int s, int v){
    vector<int> distance(v, INT_MAX);
    vector<bool> visited(v, false);
    int actual, dc, minDistance, newDistance, k;

    distance[s]=0;
    visited[s]=true;
    actual=s;

    while(true){
        minDistance=INT_MAX;
        dc=distance[actual];

        for(int i=0; i<v; i++){
            if(!visited[i] && weights[actual][i]!=INT_MAX){
                newDistance=dc+weights[actual][i];
                if(newDistance<distance[i]){
                    distance[i]=newDistance;
                }
                if(distance[i]<minDistance){
                    minDistance=distance[i];
                    k=i;
                }
            }
        }

        bool found=false;
        for(int i=0; i<v; i++){
            if(!visited[i] && distance[i]!=INT_MAX){
                actual=k;
                visited[actual]=true;
                found=true;
                break;
            }
        }

        if(!found) break;
    }

    return distance;
}

//MAIN
int main(){
    int t=0, v=0, source=0;
    vector<vector<int>> adjMatrix;
    vector<int> originNodes;

    do{
        cout<<"Enter the number of testcases: ";
        cin>>t;
        if(t<1 || t>20){
            cout<<"Enter a valid number of testcases between 1 and 100"<<endl<<endl;
        }
    }while(t<1 || t>20);
    while(t--){
        do{
            cout<<"Enter the number of nodes: ";
            cin>>v;
            if(v<1 || v>20){
                cout<<"Enter a valid number of nodes between 1 and 100"<<endl<<endl;
            }
        }while(v<1 || v>20);

        adjMatrix=vector<vector<int>>(v, vector<int> (v, 0));

        cout<<"Enter the adjacency matrix: ";
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cin>>adjMatrix[i][j];
                if(adjMatrix[i][j]==0)
                    adjMatrix[i][j]=INT_MAX;
            }
        }

        cout<<"Enter the source node: ";
        cin>>source;

        vector<int> distances=dijkstra(adjMatrix, source, v);

        for(int i=0; i<v; i++){
            cout<<distances[i]<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}