//Concrete class that extends NetworkDevice (a wired device)
class Router:NetworkDevice{
    //attributes
    private int portCount;

    //constructor
    public Router(string ipAddress, string deviceName, int portCount):base(ipAddress, deviceName){
        this.portCount=portCount;
    }

    //methods overrides
    public override void DisplayDeviceInfo(){
        base.DisplayDeviceInfo();
        Console.WriteLine($"Port Count: {portCount}");
    }

    public override void Connect(){
        Console.WriteLine($"{deviceName} is connecting via Ethernet at {ipAddress}");
    }
}