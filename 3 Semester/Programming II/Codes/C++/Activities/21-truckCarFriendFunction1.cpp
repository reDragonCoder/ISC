// Author: reDragonCoder
//Two classes have a friend function in common

//LIBRARIES
#include <iostream>
#include <conio.h>

//NAMESPACE
using namespace std;

//CLASSES
class Truck; //an advance reference

class Car{
    private:
        int passengers;
        int speed;
    public:
        Car(int p, int s){passengers=p; speed=s;}
        friend int sp_greater(Car c, Truck t);
};

class Truck{
    private:
        int weight;
        int speed;
    public:
        Truck(int w, int s){weight=w; speed=s;}
        friend int sp_greater(Car c, Truck t);
};

//FUNCTION
int sp_greater(Car c, Truck t){
    return c.speed-t.speed;
}

//MAIN
int main(){
    //variables
    int t;
    Car c1(6, 55), c2(2, 130);
    Truck t1(10000, 55), t2(20000, 72);

    cout<<"Comparing c1 and t1:\n";
    t=sp_greater(c1, t1);
    if(t<0)
        cout<<"The truck is faster.\n";
    else
        if(t==0)
            cout<<"The speed of the car and the truck is the same..\n";
        else
            cout<<"The car is faster.\n";
    cout<<"\nComparing c2 and t2:\n";
    t=sp_greater(c2, t2);
    if(t<0)
        cout<<"The truck is faster.\n";
    else
        if(t==0)
            cout<<"The speed of the car and the truck is the same..\n";
        else
            cout<<"The car is faster.\n";
    char ch=getch();
    return 0;

    return 0;
}