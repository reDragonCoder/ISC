public class SailBoat:AquaticVehicle{
    //constructor
    public SailBoat(string brand, string color, string navigationType):base(brand, color, navigationType){}

    //overriden methods
    public override void Drive(){
        Console.WriteLine("Driving a sailboat...");
    }

    public override void Sail(){
        Console.WriteLine("The sailboat is sailingwith it's sails at max speed");
    }

    //concrete method
    public void RaiseAnchor(){
        Console.WriteLine("The sailboat is raising its anchor.");
    }
}