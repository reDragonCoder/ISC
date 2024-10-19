//STRING LIBRARY EXAMPLE

//LIBRARIES
#include <iostream>
#include <string> //This library is dedicated to the use of string data type

//NAMESPACE
using namespace std;

//MAIN
int main(){
	//VARIABLES
	string name1, copy;

	string name2="Cesar Malanco";  
	cout<<endl<<"Give me a name: ";
	getline(cin,name1); //with this sintaxis you enter all the data you captured before including blank spaces
	//cin>>name1; //captures only the text before the first blank space you type

	cout<<endl<<"Name 1: "<<name1;
	
	//The string data type allows you to do comparisons using ==
	cout<<endl;
	if(name1==name2)
		cout<<endl<<name1<<" is equal to "<<name2;
	else
		cout<<endl<<name1<<" is not equal to "<<name2;
	
	//The string data type allows you direct assignation
	cout<<endl;
	copy=name1;
	cout<<endl<<"Copy: "<<copy;
	
	//The string data type allows you to concatenate directly
	cout<<endl;
	name1="Welcome " + name1;
	cout<<endl<<"Name 1: "<<name1<<endl;
	
	//Way to traverse a string
	//printing a string letter by letter
	cout<<endl<< "Printing a string letter by letter: ";
	for(int i=0; i<name2.size(); i++){
		cout<<name2[i]<<" - ";
	}
	
	return 0;
}
