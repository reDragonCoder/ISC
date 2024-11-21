// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

//NAMESPACE
using namespace std;

//FUNCTIONS
void graphConstruction(int v, int e){
    vector<list<int>> adj(v);

    for(int i=0; i<e; i++){
        int u, w;
        cout<<"Enter the nodes connected by the edge: ";
        cin>>u>>w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    for(int i=0; i<v; i++){
        cout<<i<<" -> ";

        list<int> temp=adj[i];
        vector<int> sortedAdj(temp.begin(), temp.end());
        sort(sortedAdj.begin(), sortedAdj.end());

        for(int j=0; j<sortedAdj.size(); j++){
            cout<<sortedAdj[j];
            if(j!=sortedAdj.size()-1){
                cout<<" -> ";
            }
        }
        cout<<endl;
    }
}

//MAIN
int main(){
    int t=0, v=0, e=0;

    do{
        cout<<"Enter the number of testcases: ";
        cin>>t;
        if(t<1 || t>200){
            cout<<"Enter a valid number of testcases between 1 and 100"<<endl<<endl;
        }
    }while(t<1 || t>200);
    while(t--){
        do{
            cout<<"Enter the number of nodes & edges: ";
            cin>>v>>e;
            if(v<1 || v>103){
                cout<<"Enter a valid number of nodes between 1 and 100"<<endl<<endl;
            }
            if(e<1 || e>v*(v-1)){
                cout<<"Enter a valid number of edges between 1 and v*(v-1)"<<endl<<endl;
            }
        }while(v<1 || v>103 || e<1 || e>v*(v-1));

        cout<<endl<<endl;
        graphConstruction(v, e);
        cout<<endl;
    }
    return 0;
}