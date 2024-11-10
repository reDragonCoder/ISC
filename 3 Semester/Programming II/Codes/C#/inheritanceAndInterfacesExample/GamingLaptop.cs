class GamingLaptop:Laptop{
    public string GPU{get; set;}

    public GamingLaptop(string name, string os, int batteryLife, string gpu):base(name, os, batteryLife){
        GPU=gpu;
    }

    public override void TurnOn(){
        Console.WriteLine($"{DeviceName} (Gaming Laptop) with {OS}, {GPU} GPU is booting up.");
    }

    public void PlayGame(){
        Console.WriteLine($"Playing a game on {DeviceName} with {GPU}");
    }
}