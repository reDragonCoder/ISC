//STAGGERED MATRIX EXAMPLE

//LIBRARIES
#include <iostream> //for using C++
#include <iomanip> //for using setw
#include <ctime> 
#include <cstdlib>

//NOTE: old libraries use .h, and for deleting .h you need to erase it and adding a "c" at the start of the library name
//NOTE: Ex. printf("%4d", k); if for justifying that value (space) & setw does the same but for cout (cout<<setw(4)<<prod[i][j];)

//PROTOTYPES
int **createStaggeredMatrix(int n, int *columns);
void fill(int **prod, int *columns, int n);
void print(int **prod, int *columns, int n);

//NAMESPACE
using namespace std;

//STAGGERED MATRIX
/*A staggered matrix is
the one in which every
row has a different 
number of columns*/

//MAIN
int main(){
	//RANDOM SEED
	srand(time(0)); //random numbers seed (it only generates once in the main to cover all the program)

	//VARIABLES
	int **prod, *columns, n;
	
	cout<<endl<<"How many rows does the staggered matrix has?: ";
	cin>>n;	

	//creating the boxes for the auxiliar dynamic vector
	//here we are going to save the total columns of each row
	
	columns=new int[n];
	prod=createStaggeredMatrix(n, columns);	
    
	fill(prod, columns, n);	
	print(prod, columns, n);
	
	return 0;
}


//IMPLEMENTATIONS
int **createStaggeredMatrix(int n, int *columns){
	//create columns for the dynamic matrix
	int **mat, total;
	mat=new int*[n]; //row creation
	for(int i=0; i<n; i++){
		cout<<"Give me the total columns of the row #"<<i<<" : ";
		cin>>total;		
		//create columns for the i-row of the staggered matrix
		mat[i]=new int[total];
		columns[i]=total;
	}
	return mat;
}

void fill(int **prod, int *columns, int n){
	//fill staggered matrix with random data
	cout<<endl<<"\nFilling staggered matrix with RANDOM numbers..."<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<columns[i]; j++){
			prod[i][j]=8+rand()%(16-8+1); /*lower limit / format / upper limit-lower limit+1 (1 is required)*/
		}
	}
}

void print(int **prod, int *columns, int n){
	cout<<endl<<"Printing staggered matrix..."<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<columns[i]; j++){
			cout<<setw(4)<<prod[i][j];
		}
		cout<<endl;
	}
}

 