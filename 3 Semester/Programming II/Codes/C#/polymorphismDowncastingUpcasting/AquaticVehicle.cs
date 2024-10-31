public abstract class AquaticVehicle:Vehicle{
    //attrubutes
    public string NavigationType{get; set;} //by motor, by sail or by oars

    //constructor
    public AquaticVehicle(string brand, string color, string navigationType):base(brand, color){
        NavigationType=navigationType;
    }

    //virtual method
    public virtual void Sail(){
        Console.WriteLine("Sailing on the aquatic vehicle...");
    }
}