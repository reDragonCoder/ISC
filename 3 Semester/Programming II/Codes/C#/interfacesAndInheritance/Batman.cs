class Batman:Hero, ICombat{
    //properties
    public string BatcaveLocation{get; set;}

    // constructor
    public Batman(string name, int powerLevel, string batcaveLocation):base(name, powerLevel){
        BatcaveLocation=batcaveLocation;
    }

    // abstract method override
    public override void UsePower(){
        Console.WriteLine($"{Name} uses gadgets and intelligence to defear enemies!");
    }

    //interfaces method
    public void Fight(){
        Console.WriteLine($"{Name} is using martial arts to fight!");
    }

    // concrete class method
    public void GatherIntel(){
        Console.WriteLine($"{Name} is gathering intelligence form the batcomputer");
    }

    // virtual method override
    public override void DisplayHeroInfo()
    {
        base.DisplayHeroInfo();
        Console.WriteLine($"Batcave Location: {BatcaveLocation}");
    }
}