public class JetSki:AquaticVehicle{
    //constructor
    public JetSki(string brand, string color, string navigationType):base(brand, color, navigationType){}

    //overriden method
    public override void Drive(){
        Console.WriteLine("Driving a JetSki...");
    }

    public override void Sail(){
        Console.WriteLine("The JetSki is sailing.");
    }

    //concrete method
    public void DoJumpTrick(){
        Console.WriteLine("The JetSki is doing a jump trick.");
    }
}