abstract class Hero{
    //properties
    public string Name{get; set;}
    public int PowerLevel{get; set;}

    //constructor
    public Hero(string name, int powerLevel){
        Name=name;
        PowerLevel=powerLevel;
    }

    //abstract method
    public abstract void UsePower();

    //virtual method
    public virtual void DisplayHeroInfo(){
        Console.WriteLine($"Hero Name: {Name}, Power Level: {PowerLevel}");
    }
}