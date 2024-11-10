class Ironman:Hero, ICombat, IFlight{
    //properties
    public string SuitType{get; set;}

    // constructor
    public Ironman(string name, int powerLevel, string suitType):base(name, powerLevel){
        SuitType=suitType;
    }

    // abstract method override
    public override void UsePower(){
        Console.WriteLine($"{Name} uses the Iron Man suit to fight!");
    }

    //interfaces methods
    public void Fight(){
        Console.WriteLine($"{Name} is using his suit's weapons to fight!");
    }

    public void Fly(){
        Console.WriteLine($"{Name} is flying with his suit!");
    }

    // concrete class method
    public void SaveTheWorld(){
        Console.WriteLine($"{Name} is saving the world with hos genius!");
    }

    // virtual method override
    public override void DisplayHeroInfo()
    {
        base.DisplayHeroInfo();
        Console.WriteLine($"Suit Type: {SuitType}");
    }
}