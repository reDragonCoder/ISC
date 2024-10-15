// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR CAR FUNCTIONALITY PT.2

//LIBRARIES
#include <iostream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Car{
    //attributes or member variables of the class
    private: //private level access for the attributes
        string brand, model;
        float price;
    public: //public level access for the constructors & methods

    //empty constructor
    Car();
    //constructor with parameters
    Car(string brand, string model, float price); 
    //destructor
    ~Car();

    //methods or member functions (prototypes)
    void stop();
    void moveForward();
    void turnOn();
    void turnOff();
    void turnAround();
    void print();
}; //end of class

//constructors & methods (functions) implementation of the class
    Car::Car(){
        cout<<endl<<"I'm the EMPTY constructor of the class";
        this->brand="Nissan";
        this->model="Tsuru";
        this->price=10000;
    }

    Car::Car(string brand, string model, float price){
        cout<<endl<<"I'm the constructor WITH PARAMETERS of the class";
        this->brand=brand;
        this->model=model;
        this->price=price;
    }
    
    //destructor
    Car::~Car(){
        cout<<endl<<"I'm the class destructor"<<endl;
    }

    //methods or member functions
    void Car::stop(){
        cout<<endl<<this->brand<<" stopping";
    }

    void Car::moveForward(){
        cout<<endl<<this->brand<<" moving forward";
    }

    void Car::turnOn(){
        cout<<endl<<this->brand<<" turning on";
    }

    void Car::turnOff(){
        cout<<endl<<"Turning off "<<this->brand;
    }

    void Car::turnAround(){
        cout<<endl<<this->brand<<" turning around";
    }

    void Car::print(){
        cout<<endl<<"\nPrinting data";
        cout<<endl<<"Brand: "<<this->brand;
        cout<<endl<<"Model: "<<this->model;
        cout<<endl<<"Price: "<<this->price;
    }

/*
The important difference between constructors & methods is that the constructors 
build & initialize objects that doesn't exist yet, while methods work on already 
existing objects.
*/

//MAIN
int main(){
    //creating static object
    {
        /*This keys are for you to appreciate how
          the destructor goes into action at the end
          of the objects scope*/
    cout<<endl<<"Static object car1";
    Car car1;
    car1.turnOn();
    car1.moveForward();
    car1.stop();
    car1.print();
    }

    cout<<endl<<"************************************";

    //testing the constructor with parameters
    Car car2("Ford", "Explorer", 250000);
    car2.turnOn();
    car2.print();

    cout<<endl<<"************************************";

    //testing the constructor with parameters
    Car car3("Toyota", "Sienna", 450000);
    car3.turnOn();
    car3.print();

    cout<<endl<<"************************************";

    //testing the constructor with parameters
    string brand2, model2;
    float price2;

    cout<<endl;
    cout<<endl<<"Give me a brand: ";
    getline(cin, brand2);
    cout<<endl<<"Give me a model: ";
    getline(cin, model2);
    cout<<endl<<"Give me the price: ";
    cin>>price2;

    Car car4(brand2, model2, price2);
    car4.turnAround();
    car4.print();

    cout<<endl<<"************************************";

    //testing the constructor with parameters with a dynamic object
    cout<<endl;
    fflush(stdin); //in case the brand question is saleishon
    cout<<endl<<"Give me a brand: ";
    getline(cin, brand2);
    cout<<endl<<"Give me a model: ";
    getline(cin, model2);
    cout<<endl<<"Give me the price: ";
    cin>>price2;

    Car *car5;
    car5=new Car(brand2, model2, price2);
    car5->stop();
    car5->print();
    delete car5;

    cout<<endl<<"************************************";

    //static object (class exercise)
    Car car6("Lamborghini", "Veneno", 87000);
    car6.print();
    car6.turnOn();
    car6.turnAround();
    car6.stop();
    car6.turnOff();

    cout<<endl<<"************************************";

    //dynamic object (class exercise)
    Car *car7;
    car7=new Car("Bugatti", "Veyron", 56000);
    car7->turnOn();
    car7->moveForward();
    car7->turnAround();
    car7->turnOff();
    car7->print();
    delete car7;

    return 0;
} //end of main

//NOTES:
//Overflow of the constructor when there are more than one constructor in the class (never with a destructor)