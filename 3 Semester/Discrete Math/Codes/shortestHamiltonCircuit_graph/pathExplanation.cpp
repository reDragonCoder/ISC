//CALCULATE THE MIN COST HAMILTON CIRCUIT OF A 11 NODE GRAPH
//PATH EXPLANATION

// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANT
#define V 5
#define MAX_CIRCUITS 48 //(11-1)!=10!=3,628,800 ~ 4,000,000

//GLOBAL VARIABLES
int path[V];
int allCircuits[MAX_CIRCUITS][V]; 
int circuitCount=0;

//FUNCTIONS
//display the Hamiltonian circuit
void displayCircuit(int circuit[V]) {
   cout<<"Circuit Found: ";
   for(int i=0; i<V; i++)
      cout<<circuit[i]<<" ";
   cout<<circuit[0]<< endl; 
}

//check if adding vertex v to the path is valid
bool isValid(int u, int k, int a[V][V]) {
   if(a[path[k-1]][u]==0)
      return false;
   for(int i=0; i<k; i++){
	  cout<<"I: "<<i<<" K: "<<k<<endl;
      if (path[i]== u){
		 cout<<"FALSE"<<endl<<path[i]<<endl;
		 cout<<u<<endl;
         return false;
	  }
	  cout<<"TRUE"<<endl<<path[i]<<endl;
	  cout<<u<<endl;
   }
   
   return true;
}

//find Hamiltonian circuits
void circuitFound(int k, int a[V][V]) {
   if(k==V){
      if(a[path[k-1]][path[0]]==1){
         if(circuitCount<MAX_CIRCUITS){
			cout<<"PATH:";
            for(int i=0; i<V; i++){
               allCircuits[circuitCount][i]=path[i]; 
			   cout<<" "<<path[i];
            }
            circuitCount++;
			cout<<endl<<"DING: "<<circuitCount<<endl;

         }
      }
      return;
   }

   for(int u=1; u<V; u++){
	  cout<<endl<<"PATH: ";
	  for (int i = 0; i < V; i++){
		cout<<" "<<path[i];
	  }
	  cout<<endl;
      if(isValid(u, k, a)){
        path[k]=u;
		cout<<endl<<"IS VALID: "<<path[k]<<endl;
        circuitFound((k+1), a);
        path[k]=-1; 
      }else{
		cout<<endl<<"NOT VALID"<<endl;
	  }
   }
}

//find and display all Hamiltonian circuits
void hamiltonianCircuit(int a[V][V]){
   fill(path, path + V, -1);
   path[0]=0; 
   circuitFound(1, a);

   if(circuitCount==0){
      cout<<"Solution does not exist"<<endl;
   }else{
      for(int i=0; i< circuitCount; i++){
        displayCircuit(allCircuits[i]);
      }
   }
}

//MAIN
int main(){
    srand(time(0));
	int a[V][V]={{0}}, i=0 ,j=0,pass=0, paths[V]={0}, temp_value=0;
	while(pass==0){
		for(i=0; i<V; i++){
			for(j=0; j<V; j++){
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
		for(i=0; i<V; i++){
			paths[i]=0;
		}
		pass=1;
		for(i=0; i<V; i++){
			for(j=0; j<V; j++){
				paths[i]+=a[i][j];
			}
		}
		for(i=0; i<V; i++){
			if(2*paths[i]<V)
				pass=0;
		}
	}
	for(i=0; i<V; i++){
		for(j=i; j<V; j++){
			/*temp_value=(rand()%100);
			temp_value++;*/
			temp_value=1;

			if(i==j){
				a[i][j]=0;
			}
			else{
				a[i][j]*=temp_value;
				a[j][i]*=temp_value;
			}
		}
	}
	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			if(j<V-1){
				cout<<setw(5)<<a[i][j];
			}
			else{
				cout<<setw(5)<<a[i][j]<<endl;
			}
		}
	}
    hamiltonianCircuit(a);
    return 0;
}