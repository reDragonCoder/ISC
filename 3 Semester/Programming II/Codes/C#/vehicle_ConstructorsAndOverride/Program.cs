// Author: reDragonCoder

using System;

public class Vehicle{
    private string brand;
    private int year;

    //Base class constructor
    public Vehicle(string brand, int year){
        this.brand=brand;
        this.year=year;
        Console.WriteLine($"Vehicle constructor: Brand = {brand}, Year = {year}");
    }

    //Virtual method that can be overriden
    public virtual void ShowInfo(){
        Console.WriteLine($"Vehicle: Brand = {brand}, Year = {year}");
    }
}

public class Car:Vehicle{
    private int doorNum;
    private string fuelType;

    //Derivate class constructor that calls the base constructor
    public Car(string brand, int year, int doorNum, string fuelType):base(brand, year){
        this.doorNum=doorNum;
        this.fuelType=fuelType;
        Console.WriteLine($"Car constructor: Door number = {doorNum}, Fuel type = {fuelType}");
    }

    //ShowInfo override
    public override void ShowInfo(){
        base.ShowInfo();
        Console.WriteLine($"Car: Door number = {doorNum}, Fuel type = {fuelType}");
    }
}

public class Sport:Car{
    private double maxSpeed;
    private bool turbo;

    //More derivate class that also calls its predecesors
    public Sport(string brand, int year, int doorNum, string fuelType, double maxSpeed, bool turbo):base(brand, year, doorNum, fuelType){
        this.maxSpeed=maxSpeed;
        this.turbo=turbo;
        Console.WriteLine($"Sport constructor: Maximum speed = {maxSpeed}, Turbo = {turbo}");
    }

    //ShowInfo override
    public override void ShowInfo(){
        base.ShowInfo();
        Console.WriteLine($"Sport: Maximum speed = {maxSpeed}, Turbo = {turbo}");

    }
}

class Program{
    static void Main(){
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("reDragonCoder");
        Console.ResetColor();
        Console.WriteLine();

        //creating a Sport class object
        Sport mySport=new Sport("BMW", 2024, 2, "Gas", 300.0, true);

        //Showing the info using the overriden method
        mySport.ShowInfo();
        Console.WriteLine();

        //Complete by creating another object of the type of the Sports class and displaying information
        Sport anotherSport=new Sport("Lamborghini", 2024, 2, "Gas", 350.0, true);
        anotherSport.ShowInfo();
        Console.WriteLine();

        //Complete by creating another object of the Car class type and display information
        Car myCar=new Car("Bugatti", 2015, 2, "Gas");
        myCar.ShowInfo();
        Console.WriteLine();

        //Complete by creating another object of the Vehicle class type
        Vehicle myVehicle=new Vehicle("Mustang", 2005);
        myVehicle.ShowInfo();
        Console.WriteLine();
    }
}