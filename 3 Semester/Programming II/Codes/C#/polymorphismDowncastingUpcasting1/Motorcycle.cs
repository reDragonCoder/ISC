public class Motorcycle:LandVehicle{
    //constructor
    public Motorcycle(string brand, string color, int wheels):base(brand, color, wheels){}

    //overriden methods
    public override void Drive(){
        Console.WriteLine("The motorcycle is being driven...");
    }

    public override void CheckFuelLevel(){
        Console.WriteLine("The motorcycle fuel level is at 30%");
    }

    //concrete methods
    public void DoWheelieTrick(){
        Console.WriteLine("The motorcycle is doing a wheelie trick.");
    }
}