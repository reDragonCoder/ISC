// Author: reDragonCoder

using System;

// We define the interface with a property and a method
interface IVehicle{
    int Speed{get; set;}  // Property instead of an attribute
    void Drive();
}

// Class that implements the interface and defines a private attribute
class Car:IVehicle{
    private int speed; // Private attribute to store the value of Speed

    public int Speed{
        get{return speed;}
        set{speed=value;}
    }

    public void Drive(){
        Console.WriteLine("Driving at "+Speed+" km/h speed.");
    }
}

class Program{
    static void Main(){
        Car car=new Car();
        car.Speed=100;  // Using property to assign a value
        car.Drive();      // Sample: "Driving at 100 km/h speed"
    }
}
