// Author: GSP

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASS
class Automovil{
    //attributes or member variable of the class
    private: //private access level for attributes
        string brand, model;
        float price;

    public: //public access level for constructors and methods
        //empty constructor
        Automovil();
        //constructor with parameters
        Automovil(string brand, string model, float price);
        //destructor
        ~Automovil();
        
        //methods or member functions
        string getbrand(){
            return this->brand;
        }
        
        string getmodel(){
            return this->model;    	
        }
        
        float getprice(){
            return this->price;    	
        }
        
        void curb();
        void advance();
        void turnOn();
        void turnOff();
        void turnAround();
        void print();

}; 

//CONSTRUCTORS, DESTRUCTORS & METHODS IMPLEMENTATIONS
Automovil::Automovil(){
    cout<<endl<<"EMPTY Constructor "; 
    this->model="Tsuru";
    this->price=100000;
}

Automovil::Automovil(string brand, string model, float price){
    cout<<endl<<"constructor WITH PARAMETERS";
    this->brand=brand;
    this->model=model;
    this->price=price;
}

//destructor
Automovil::~Automovil(){
    cout<<endl<<"Destructor de la clase"<<endl;
}

void Automovil::curb(){
    cout<<endl<<this->brand<<" curbing";
}

void Automovil::advance(){
    cout<<endl<<this->brand<<" advancing";
}

void Automovil::turnOn(){
    cout<<endl<<this->brand<<" turning On";
}

void Automovil::turnOff(){
    cout<<endl<<"turning Off "<<this->brand;
}

void Automovil::turnAround(){
    cout<<endl<<this->brand<<" turning around";
}

void Automovil::print(){
    cout<<endl<<"\nPrinting data...";
    cout<<endl<<"Brand: "<<this->brand;
    cout<<endl<<"Model: "<<this->model;
    cout<<endl<<"Price: "<<this->price;
}

//FUNCTION
void prueba(Automovil &obj){
	cout<<endl<<"I am in test function receiving an object as parameter";
	cout<<endl<<obj.getbrand();
	cout<<endl<<obj.getmodel();
	cout<<endl<<obj.getprice();		
}

//MAIN
int main(){

    cout<<endl<<"**************";
    
    //testing the constructor with parameters
    Automovil auto1("Ford","Explorer",250000);
    auto1.turnOn();
    auto1.print();
    cout<<endl<<"\n**************\n";
    prueba(auto1);
    
    cout<<endl<<endl<<endl;
    return 0;
}



