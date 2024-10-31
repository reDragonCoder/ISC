public class Truck:Automobile{
    //attribute
    public int LoadCapacity {get; set;}

    //constructor
    public Truck(string brand, string color, int wheels, int loadCapacity):base(brand, color, wheels){
        LoadCapacity=loadCapacity;
    }

    //overriden methods
    public override void Drive(){
        Console.WriteLine("The truck is being driven with load...");
    }

    public override void CheckFuelLevel(){
        Console.WriteLine("The truckfuel level is at 50%.");
    }

    //concrete constructor
    public void Load(){
        Console.WriteLine("Loading the truck.");
    }
}