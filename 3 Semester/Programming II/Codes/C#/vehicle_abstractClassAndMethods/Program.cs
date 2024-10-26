// Author: reDragonCoder

using System;

abstract class Vehicle{
    //Abstract method that every vehicle has to implement
    public abstract string FuelType();

    //Concrete method that describes the vehicle boot
    public void TurnOn(){
        Console.WriteLine("The vehicle is turned on.");
    }
}

class ElectricCar:Vehicle{
    //Abstract method implementation
    public override string FuelType(){
        return "Electricity";
    }
}

class MotorBike:Vehicle{
    //Abstract method implementation
    public override string FuelType(){
        return "Gas";
    }
}

class Truck:Vehicle{
    //Abstract method implementation
    public override string FuelType(){
        return "Diesel";
    }
}

class Program{
    static void Main(string[] args){
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("reDragonCoder");
        Console.ResetColor();
        Console.WriteLine();
        
        //Instances
        ElectricCar electricCar=new ElectricCar();
        MotorBike motorBike=new MotorBike();
        Truck truck=new Truck();

        //Every vehicle informs about its fuel type
        //With every object it calls the fuelType method
        Console.WriteLine($"The car uses: {electricCar.FuelType()}");
        Console.WriteLine($"The motorbike uses: {motorBike.FuelType()}");
        Console.WriteLine($"The truck uses: {truck.FuelType()}");
        Console.WriteLine();

        //All vehicles can boot
        //With each object it calls the inherit method TurnOn
        electricCar.TurnOn();
        motorBike.TurnOn();
        truck.TurnOn();
    }
}
