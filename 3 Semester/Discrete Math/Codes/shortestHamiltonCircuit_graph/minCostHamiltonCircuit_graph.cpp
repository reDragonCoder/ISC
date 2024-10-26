//CALCULATE THE MIN COST HAMILTON CIRCUIT OF A 11 NODE GRAPH

// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

//NAMESPACE
using namespace std;

//GLOBAL CONSTANT
#define V 11
#define MAX_CIRCUITS 4000000 //(11-1)!=10!=3,628,800 ~ 4,000,000

//GLOBAL VARIABLES
int path[V];
int allCircuits[MAX_CIRCUITS][V];
int circuitCount=0;
int sumsCircuit[MAX_CIRCUITS];

//FUNCTIONS
void display(int circuit[V]){
	for(int i=0; i<V; i++){
		cout<<circuit[i]<<" ";
	}
	cout<<circuit[0]<< endl; 
}

//verify the least costly circuit
void barateishon(){
	int temp=0, k=0, j=0;
	int index[circuitCount];
	temp=sumsCircuit[0];
	for(int i=1; i<circuitCount; i++){
		if(temp>sumsCircuit[i]){
			temp=sumsCircuit[i];
		}
	}
	for(int i=1; i<circuitCount; i++){
		if(sumsCircuit[i]==temp){
			index[k]=i;
			k++;
		}
	}
	cout<<endl<<"The path(s) with the least cost were:"<<endl;
	for(int i=0; i<k; i++){
		j=index[i];
		display(allCircuits[j]);
		cout<<temp<<endl;
		cout<<endl;
	}
}

//display the Hamiltonian circuit
void circuitSum(int circuit[V], int a[V][V], int n) {
	int sum=0, temp=0;
   	/*cout<<"Circuit Found: ";
	for(int i=0; i<V; i++){
		cout<<circuit[i]<<" ";
	}
	cout<<circuit[0]<< endl;*/ 

   for(int i=1; i<V+1; i++){
		temp=a[circuit[i-1]][circuit[i]];
		sum+=temp;
   }
   sumsCircuit[n]=sum;
}

//check if adding vertex v to the path is valid
bool isValid(int u, int k, int temp[V][V]) {
   if(temp[path[k-1]][u]==0)
      return false;
   for(int i=0; i<k; i++)
      if (path[i]==u)
         return false;
   return true;
}

//find Hamiltonian circuits
void circuitFound(int k, int temp[V][V]) {
   if(k==V){
      if(temp[path[k-1]][path[0]]==1){
         if(circuitCount<MAX_CIRCUITS){
            for(int i=0; i<V; i++){
               allCircuits[circuitCount][i]=path[i]; 
            }
            circuitCount++;
         }
      }
      return;
   }

   for(int v=1; v<V; v++){
      if(isValid(v, k, temp)){
        path[k]=v;
        circuitFound((k+1), temp);
        path[k]=-1; 
      }
   }
}

//find and display all Hamiltonian circuits
void hamiltonianCircuit(int a[V][V], int temp[V][V]){
	int n=0;
   fill(path, path+V, -1);
   path[0]=0; 
   circuitFound(1, temp);

   if(circuitCount==0){
      cout<<"Solution does not exist"<<endl;
   }else{
      for(int i=0; i<circuitCount; i++){
		n=i;
        circuitSum(allCircuits[i], a, i);
      }
	barateishon();
   }
}

//MAIN
int main(){
    srand(time(0));
	int a[V][V]={{0}}, i=0 ,j=0,pass=0, paths[V]={0}, temp_value=0;
	int temp[V][V]={{0}};
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

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			if(a[i][j]!=0){
				temp[i][j]=1;
			}
		}
	}

	cout<<endl;
	
    hamiltonianCircuit(a, temp);
    return 0;
}