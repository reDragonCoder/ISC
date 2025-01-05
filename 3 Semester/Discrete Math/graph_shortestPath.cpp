// Author: reDragonCoder
//SHORTEST PATH TO ALL NODES OF A GRAPH

//LIBRARIES
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANT
#define V 5
#define INFINITY 9999

//FUNCTION PROTOTYPE
void shortestPath(int a[V][V], int start);

//MAIN
int main(){
    srand(time(0));
	int a[V][V]={{0}}, i=0, j=0, pass=0, paths[V]={0}, temp_value=0, node=0;
	while(pass==0){
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				temp_value=rand()%2;
				if(i==j){
					a[i][j]=0;
				}
				else{
					a[i][j]=temp_value;
					a[j][i]=temp_value;
				}
			}
		}
		for(i=0;i<V;i++){
			paths[i]=0;
		}
		pass=1;
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				paths[i]+=a[i][j];
			}
		}
		for(i=0;i<V;i++){
			if(2*paths[i]<V)
				pass=0;
		}
	}
	for(i=0;i<V;i++){
		for(j=i;j<V;j++){
			temp_value=(rand()%100);
			temp_value++;
			if(i==j){
				a[i][j]=0;
			}
			else{
				a[i][j]*=temp_value;
				a[j][i]*=temp_value;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(j<V-1){
				cout<<setw(5)<<a[i][j];
			}
			else{
				cout<<setw(5)<<a[i][j]<<endl;
			}
		}
	}

    shortestPath(a, node);

    return 0;
}

//FUNCTION IMPLEMENTATION
void shortestPath(int a[V][V], int start){
    int weight[V][V], distance[V], pred[V];
    int visited[V], counter=0, minDistance=0, nextNode=0, j=0;

    //discarding impossible paths 
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(a[i][j]==0)
                weight[i][j]=INFINITY;
            else
                weight[i][j]=a[i][j];
        }
    }

    //using first node in the path
    for(int i=0; i<V; i++){
        distance[i]=weight[start][i];
        pred[i]=start;
        visited[i]=0;
    }
    distance[start]=0;
    visited[start]=1;
    counter=1;

    //dijkstra's algorithm
    while(counter<V-1){
        minDistance=INFINITY;
        for(int i=0; i<V; i++){
            if(distance[i]<minDistance && !visited[i]){
                minDistance=distance[i];
                nextNode=i;
            }
        }
        visited[nextNode]=1;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(minDistance+weight[nextNode][i]<distance[i]){
                    distance[i]=minDistance+weight[nextNode][i];
                    pred[i]=nextNode;
                }
            }
        }
        counter++;
    }

    //printing the distance & the path
    for(int i=0; i<V; i++){
        if(i!=start){
            cout<<"\nDistance of node "<<i<<": "<<distance[i];
            cout<<"\nPath: "<<i;
            j=i;
            do{
                j=pred[j];
                cout<<" <-- "<<j;
            }while(j!=start);
        }
    }
}