//Third class
public class Dog:Mammal{
    private string race;
    private double weight;

    //Constructor of the most derived class that also calls its predecessors
    public Dog(string name, int age, bool hasHair, string bloodType, string race, double weight):base(name, age, hasHair, bloodType){
        this.race=race;
        this.weight=weight;
        Console.WriteLine($"Dog constructor: race = {race}, weight = {weight} kg");
    }

    //Methods to display attributes
    public override void ShowData(){
        base.ShowData(); //Calling the method of the derived class
        Console.WriteLine($"Dog: race = {race}, weight = {weight} kg");
    }
}
