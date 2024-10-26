//Intermediary abstract class that extends NetworkDevice class and andds new properties
//NOTE: the class is abstarct because it does not overwrite the abstract method Connect in its base class
abstract class WirelessDevice:NetworkDevice{
    //attributes
    protected string wirelessProtocol;

    //constructor
    public WirelessDevice(string ipAddress, string deviceName, string wirelessProtocol):base(ipAddress, deviceName){
        this.wirelessProtocol=wirelessProtocol;
    }

    //method override
    public override void DisplayDeviceInfo(){
        base.DisplayDeviceInfo();
        Console.WriteLine($"Wireless Protocol: {wirelessProtocol}");
    }

    //another method
    public void ChangeWirelessProtocol(string newProtocol){
        Console.WriteLine($"{deviceName} is switching from {wirelessProtocol} to {newProtocol}");
        this.wirelessProtocol=newProtocol;
    }
}