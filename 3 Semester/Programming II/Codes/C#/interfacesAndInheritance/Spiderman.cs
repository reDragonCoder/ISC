class Spiderman:Hero, ICombat{
    //properties
    public string WebMaterial{get; set;}

    // constructor
    public Spiderman(string name, int powerLevel, string webMaterial):base(name, powerLevel){
        WebMaterial=webMaterial;
    }

    // abstract method override
    public override void UsePower(){
        Console.WriteLine($"{Name} uses spider powers and webs to fight crime!");
    }

    //interfaces method
    public void Fight(){
        Console.WriteLine($"{Name} is swinging from webs and fighting villains!");
    }

    // concrete class method
    public void ProtectNewYork(){
        Console.WriteLine($"{Name} is protecting the streets of New York");
    }

    // virtual method override
    public override void DisplayHeroInfo()
    {
        base.DisplayHeroInfo();
        Console.WriteLine($"Web Material: {WebMaterial}");
    }
}