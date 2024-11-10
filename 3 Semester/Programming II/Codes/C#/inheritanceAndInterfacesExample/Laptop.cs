class Laptop:Computer{
    public int BatteryLife{get; set;}

    public Laptop(string name, string os, int batteryLife):base(name, os){
        BatteryLife=batteryLife;
    }

    public override void TurnOn(){
        Console.WriteLine($"{DeviceName} (Laptop) with {OS} is starting with {BatteryLife}% battery");
    }

    public void ChargeBattery(){
        Console.WriteLine($"{DeviceName} is charging.");
    }
}