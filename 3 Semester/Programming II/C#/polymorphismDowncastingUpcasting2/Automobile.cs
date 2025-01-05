public class Automobile:LandVehicle{
    //constructor
    public Automobile(string brand, string color, int wheels):base(brand, color, wheels){}

    //overriden methods
    public override void Drive(){
        Console.WriteLine("The automobile is being driven...");
    }

    public override void CheckFuelLevel(){
        Console.WriteLine("The automobile fuel level is at 75%.");
    }

    //concrete method
    public void openTrunk(){
        Console.WriteLine("Opening automobile trunk.");
    }
}