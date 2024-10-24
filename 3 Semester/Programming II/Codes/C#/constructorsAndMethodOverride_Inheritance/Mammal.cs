//Second class
public class Mammal:Animal{
    private bool hasHair;
    private string bloodType;

    //Constructor of the derived class that calls the base constructor
    public Mammal(string name, int age, bool hasHair, string bloodType):base(name, age){
        this.hasHair=hasHair;
        this.bloodType=bloodType;
        Console.WriteLine($"Mammal constructor: Has hair = {hasHair}, Blood type = {bloodType}");
    }

    //Methods to display attributes
    public override void ShowData(){
        base.ShowData(); //Calling the base class method
        Console.WriteLine($"Mammal: Has hair = {hasHair}, Blood type = {bloodType}");
    }
}