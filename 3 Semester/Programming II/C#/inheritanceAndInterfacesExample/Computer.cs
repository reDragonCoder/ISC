class Computer:Device, ITestable, IStorable{
    public string OS{get; set;}

    public Computer(string name, string os):base(name){
        OS=os;
    }

    public override void TurnOn(){
        Console.WriteLine($"{DeviceName} with {OS} is booting up.");
    }

    public void Test(){
        Console.WriteLine($"Running tests on {DeviceName}.");
    }

    public string TestName{
        get{return "Basic Test";}
    }

    public void Store(){
        Console.WriteLine($"{DeviceName} is storing data.");
    }

    public void Retrieve(){
        Console.WriteLine($"{DeviceName} is retrieving data.");
    }

    public void UpgradeOS(){
        Console.WriteLine($"{DeviceName} is upgrading to a new OS.");
    }
}