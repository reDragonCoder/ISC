public abstract class LandVehicle:Vehicle{
    //attributes
    public int Wheels{get; set;}

    //constructor
    public LandVehicle(string brand, string color, int wheels):base(brand, color){
        Wheels=wheels;
    }

    //method for simulating the wheel change
    public virtual void ChangeWheels(){
        Console.WriteLine($"Changing the {Brand} land vehicle wheels");
    }
}