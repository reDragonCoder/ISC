// Author: reDragonCoder

using System;

interface IAquaticVehicle{
    void Start();
    void Stop();
}

class AquaticVehicle:IAquaticVehicle{
    //properties
    public string Name{get; set;}
    public double Speed{get; set;}

    //constructor
    public AquaticVehicle(string name, double speed){
        Name=name;
        Speed=speed;
    }

    //interface implementations
    public void Start(){
        Console.WriteLine("Starting movement...");
    }

    public void Stop(){
        Console.WriteLine("Stopping movement...");
    }
}

class Boat:AquaticVehicle{
    //constructor
    public Boat(string name, double speed):base(name, speed){}

    //concrete method
    public void Anchor(){
        Console.WriteLine("Anchoring the boat...");
    }
}

class Submarine:AquaticVehicle{
    //constructor
    public Submarine(string name, double speed):base(name, speed){}

    //concrete method
    public void Dive(int depth){
        Console.WriteLine($"Diving to {depth} meters...");
    }
}

class Program{
    static void Main(){
        AquaticVehicle boat=new Boat("Black Pearl", 200); //polymorphism
        AquaticVehicle submarine=new Submarine("Nautilus", 177); //polymorphism

        Console.WriteLine($"Vehicle: {boat.Name}");
        Console.WriteLine($"Speed: {boat.Speed} km/h");
        boat.Start();
        if(boat is Boat b){ //downcasting
            b.Anchor();
        }
        boat.Stop();

        Console.WriteLine();
        Console.WriteLine("***********************************");
        Console.WriteLine();

        Console.WriteLine($"Vehicle: {submarine.Name}");
        Console.WriteLine($"Speed: {submarine.Speed} km/h");
        submarine.Start();
        if(submarine is Submarine s){ //downcasting
            s.Dive(300);
        }
        submarine.Stop();
    }
}