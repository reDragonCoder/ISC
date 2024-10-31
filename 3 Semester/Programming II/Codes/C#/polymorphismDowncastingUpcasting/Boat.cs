public class Boat:AquaticVehicle{
    //constructor
    public Boat(string brand, string color, string navigationType):base(brand, color, navigationType){}

    //overriden methods
    public override void Drive(){
        Console.WriteLine("Driving a boat...");
    }

    public override void Sail(){
        Console.WriteLine("The boat is sailing in the water.");
    }

    //concrete method
    public void Beeping(){
        Console.WriteLine("The boat is beeping.");
    }
}