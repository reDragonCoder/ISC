abstract class Device{
    public string DeviceName{get; set;}

    public Device(string name){
        DeviceName=name;
    }

    public abstract void TurnOn();

    public virtual void TurnOff(){
        Console.WriteLine($"{DeviceName} is turned off.");
    }
}