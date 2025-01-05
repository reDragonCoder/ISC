// Author: reDragonCoder
//realloc
//Create more spaces in an array and this has to be dynamic (not static)

//LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10

//NAMESPACE
using namespace std;

//PROTOTYPES
void fill(int*, int);
void show(int*, int);


//MAIN
int main(){
	srand(time(NULL));
	//VARIABLES
	int *vec=NULL, index=SIZE, element=SIZE;
	bool answer=false;
	vec=(int*)malloc(SIZE* sizeof(int)); 
	//vec=new int [SIZE]; 
	
	//Save values//Management of sections//Check memory usage
	if(vec == NULL){
		cout<<"Could not create memory";
		exit (1);
	}
	
	cout<<"Do you want more elements? yes=1 || no=0"<<endl;
	cin>>answer;
	if(answer){
		cout<<"Total elements: "<<endl;
		cin>>index;
		vec=(int*)realloc(vec, index*sizeof(int));
		element=SIZE+index;//The variable num is created to add the size of the vector, with this the length function is no longer necessary
	}
	fill(vec, element);//Call this function below because if I wanted more elements they would not be filled
	show(vec, element);
} 

//IMPLEMENTATIONS
void fill(int *vec, int element){
	for(int i=0; i<element; i++){
		*(vec+i)=rand()%10;
	}
}

void show(int *vec, int element){
	for(int i=0; i<element; i++){
		cout<< *(vec+i) <<"\t";
	}	
}
