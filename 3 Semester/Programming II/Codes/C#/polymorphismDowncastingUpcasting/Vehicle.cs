public abstract class Vehicle{
    //attributes
    public string Brand{get; set;} 
    public string Color{get; set;} 

    //constructor
    public Vehicle(string brand, string color){
        Brand=brand;
        Color=color;
    }

    //abstract method
    public abstract void Drive();

    //virtual method that can be overriden in the subclasses
    public virtual void CheckFuelLevel(){
        Console.WriteLine("Checking vehicle fuel level...");
    }

    // concrete method to show info
    public void showInfo(){
        Console.WriteLine($"Brand: {Brand}, Color: {Color}");
    }
}