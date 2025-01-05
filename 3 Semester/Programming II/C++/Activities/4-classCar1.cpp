// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR CAR FUNCTIONALITY

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Car{
    //attributes or member variable of the class
    private: //private level acces for attributes
        string brand, model;
        float price;
    public: //public access level for constructors, destructors and methods

    //empty constructor
    Car(){
        cout<<endl<<"<<I'm the class constructor>>";
        this->brand="Nissan";
        this->model="Tsuru";
        this->price=100000;
    }

    //destructor
    ~Car(){
        cout<<endl<<"I'm the class destructor"<<endl;
    }

    //methods or member functions
    void stop(){
        cout<<endl<<"Stopping";
    }

    void move(){
        cout<<endl<<"Moving";
    }

    void turnOn(){
        cout<<endl<<"Turning on";
    }

    void turnOff(){
        cout<<endl<<"Turning off";
    }

    void turnAround(){
        cout<<endl<<"Turning around";
    }
    
    void honking(){ //method 1 (class exercise)
        cout<<endl<<"Honking pi-pi";
    }

    void turnOnRadio(){ //method 2 (class exercise)
        cout<<endl<<"Turning on the radio";
    }

    void turnOffRadio(){ //method 3 (class exercise)
        cout<<endl<<"Turning off the radio";
    }

    void changingSong(){ //method 4 (class exercise)
        cout<<endl<<"Changing song";
    }

    void turnOnLights(){ //method 5 (class exercise)
        cout<<endl<<"Turning on the lights";
    }

    void turnOffLights(){ //method 6 (class exercise)
        cout<<endl<<"Turning off the lights";
    }

    void backingUp(){ //method 7 (class exercise)
        cout<<endl<<"Backing-up car";
    }

    void flying(){ //method 8 (class exercise)
        cout<<endl<<"Flying activated";
    }

    void landing(){ //method 9 (class exercise)
        cout<<endl<<"Landing activated";
    }


    void print(){
        cout<<endl<<"\nPrinting data: ";
        cout<<endl<<this->brand;
        cout<<endl<<this->model;
        cout<<endl<<this->price;
    }

}; //end of the class

/* The important difference between constructors and methods is that constructors
   create and initialize objects that do not yet exist, while methods perform 
   operations on objects that already exists */

//MAIN
int main(){
    //creating a static object
    cout<<endl<<"Static object car1";
    Car car1;
    car1.turnOn();
    car1.move();
    car1.stop();
    car1.print();

    //creating another static object
    cout<<endl<<"\nStatic object car2";
    Car car2;
    car2.turnAround();
    car2.turnOff();
    car2.print();

    //creating a dynamic object
    cout<<endl<<"\nDynamic object car3";
    Car *car3;
    car3=new Car;
    car3->turnOn();
    car3->move();
    car3->turnAround();
    car3->print();
    delete car3;

    //static objects (class exercise)
    cout<<endl<<"\nStatic object coolCar1"; //static object no.1
    Car coolCar1;
    coolCar1.turnOn();
    coolCar1.turnOnLights();
    coolCar1.honking();
    coolCar1.turnOffLights();
    coolCar1.turnOff();

    cout<<endl<<"\nStatic object coolCar2"; //static object no.2
    Car coolCar2;
    coolCar2.turnOn();
    coolCar2.turnOnRadio();
    coolCar2.move();
    coolCar2.honking();
    coolCar2.flying();
    coolCar2.move();
    coolCar2.changingSong();
    coolCar2.landing();
    coolCar2.turnOff();

    //dynamic objects (class exercise)
    cout<<endl<<"\nDynamic object coolDcar1"; //dynamic object no.1
    Car *coolDcar1;
    coolDcar1=new Car;
    coolDcar1->turnOn();
    coolDcar1->move();
    coolDcar1->stop();
    coolDcar1->turnOnLights();
    coolDcar1->turnOffRadio();
    coolDcar1->backingUp();
    delete coolDcar1;

    cout<<endl<<"\nDynamic object coolDcar2"; //dynamic object no.2
    Car *coolDcar2;
    coolDcar2=new Car;
    coolDcar2->turnOff();
    coolDcar2->turnOffLights();
    coolDcar2->turnOnRadio();
    coolDcar2->changingSong();
    delete coolDcar2;

    return 0;
}//end main


//NOTES:
//In-line functions are not highly recommended or so organized
//"this->" marks an attribute
//If my identifier is from a class, it will be called object
//The constructors call themselves
//When objects are static, the instance is automatically given, when they are dynamic they're not.
//The destructor comes into action when the object's scope ends
