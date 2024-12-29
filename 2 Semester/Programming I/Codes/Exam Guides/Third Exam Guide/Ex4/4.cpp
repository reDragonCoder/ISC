// Author: reDargonCoder

//Create a program that takes all multiples of 4 up to a given N, and stores them in a file 
//of characters.

//LIBRARIES
#include <iostream>

using namespace std;

//PROTOTYPES
void fillFile(FILE*);

//MAIN
int main(){
	FILE* multiplesOf4=NULL;
	fillFile(multiplesOf4);
	cout<<"Creating file...\n";
	cout<<"Check your files";
	return 0;
}

//IMPLEMENTATIONS
void fillFile(FILE* multiplesOf4){
	multiplesOf4=fopen("multiplesOf4.txt", "w");
	
	if(multiplesOf4==NULL){
		cout<<"ERROR";
		exit(1);
	}
	
	int n;
	cout<<"Enter the number up to which you want to get the multiples: ";
	cin>>n;
	
	for(int i=0; i<n; i++){
		if(i%4==0){
			fprintf(multiplesOf4, "%d ", i);
		}else{
			continue;
		}
	}
	
	fclose(multiplesOf4);
}
