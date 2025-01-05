// Author: Aaron Guillen Villalobos

//LIBRARIES
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <iomanip>

//NAMESPACE
using namespace std;

//GLOABL CONSTANT
#define V 5

//MAIN
int main(){
	srand(time(0));
	int a[V][V]={{0}}, i=0, j=0, pass=0, paths[V]={0}, temp_value=0;
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
 return 0;
}