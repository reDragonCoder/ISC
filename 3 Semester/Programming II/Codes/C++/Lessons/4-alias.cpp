// Author: GSP
/*Using the alias operator for the step 
parameters by reference :) */

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//FUNCTION PROTOTYPES
void function(int &);
void functionWithoutAlias(int *p);

//MAIN
int main(){
	cout<<endl<<"\nUpdating a main variable from"
	          <<"\nother function, using the operators"
	          <<"\naddress (&) and indirection (*)\n";
	int x=3;
	cout<<endl<<"x="<<x;
	functionWithoutAlias(&x);
	cout<<endl<<"x="<<x;
	cout<<endl<<"\n*******************************";
	
	cout<<endl<<"\nUpdating a main variable from"
	          <<"\nother function, using the alias operator(&)\n";	           
	int a=7;
	cout<<endl<<"a="<<a;
	function(a); //Here it is not put &
	cout<<endl<<"a="<<a;
	cout<<endl<<"\n*******************************";
    return 0;	 	
}

//FUNCTION IMPLEMENTATIONS
void functionWithoutAlias(int *p){
	*p=*p+2;
}

void function(int &x){ //Here we do not put int *x, because we are using the alias.
	x=x+2; //the variable is used normally we do not need to dereference with *
}

