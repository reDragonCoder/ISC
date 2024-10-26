//Concrete class that extends WirelessDevice class
class SmartPhone:WirelessDevice{
    //attributes
    private string osVersion;

    //constructor
    public SmartPhone(string ipAddress, string deviceName, string wirelessProtocol, string osVersion):base(ipAddress, deviceName, wirelessProtocol){
        this.osVersion=osVersion;
    }

    //method override
    public override void DisplayDeviceInfo(){
        base.DisplayDeviceInfo();
        Console.WriteLine($"Operating System Version: {osVersion}");
    }

    //abstract method override
    public override void Connect(){
        Console.WriteLine($"{deviceName} is connecting via {wirelessProtocol} at {ipAddress}");
    }

    //other methods
    public void ChangeDeviceName(string newName){
        Console.WriteLine($"Changing device name from {deviceName} to {newName}");
        this.deviceName=newName;
    }
}