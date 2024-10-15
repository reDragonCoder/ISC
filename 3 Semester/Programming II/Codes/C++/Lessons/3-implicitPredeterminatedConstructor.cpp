// Author: GSP

//LIBRARIES
#include <iostream>
 

/*The implicit default constructor of a class is the one that the language
included in your program because you did NOT implement any constructor in the class (i.e.
your class has no constructors), the implicit default constructor 
It is an empty constructor that you will not see in your code,
 the language incorporates it automatically during execution 
of the program, this benefit of the implicit default constructor will
is REMOVED the moment you implement a constructor with parameters, so if
you want an empty constructor in the class, YOU have to implement it!!!
*/

//NAMESPACE
using namespace std;

//CLASSES
class Circunference{
	private:
		//attributes or characteristics of the class are private
		float ratio;	
		
	public:	
		//methods or behavior of the class goes public
		float calculateArea();
		float getRatio(); //retrieves the value of the ratio attribute
		void setRatio(float); //sets a value to the ratio attribute
	 
};

//FUNCTIONS
//implement the functions
float Circunference::calculateArea(){
	//local variable
	float area=3.1416*this->ratio*this->ratio;
	return area;	
}

float Circunference::getRatio(){
	//It only takes one line of code
	return this->ratio;
}

void Circunference::setRatio(float ratio){
	//It only takes one line of code
	this->ratio=ratio;
}


int main(int argc, char** argv) {
	Circunference obj; //utiliza un constructor vacio  pero la clase no lo tiene
	
    cout<<endl<<"This program works WITHOUT EXPLICIT CONSTRUCTORS (that is, that YOU implement)"<<endl;
	cout<<endl<<"We put 3.4 to the obj ratio with the set method";
	cout<<endl<<"It would not be possible to apply set methods if the instance ";
	cout<<endl<<"would not have been created"<<endl;
	
	 
		
	obj.setRatio(3.4);
	cout<<endl<<"Area= "<<obj.calculateArea();
	cout<<endl<<"Ratio= "<<obj.getRatio();
	cout<<endl<<"********************************";
	
	 cout<<endl<<"The implicit default constructor of a class is the one that the language "<<
		"include \n in your program because you did NOT implement any constructor in the class (i.e. " <<
		"your class has no constructors), \n the implicit default constructor " <<
		"it is an empty constructor that you will not see in your code \n"<<
		"the language incorporates it automatically during execution" <<
		"of the program, this benefit of the implicit default \n constructor gives you "<<
		"is REMOVED the moment you implement a constructor with parameters,\n then if "<<
		"you want an empty constructor in the class, YOU have to implement it!!!";
			
	return 0;
}



