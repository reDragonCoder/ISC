//Abstract class that defines the concept of connected device
abstract class NetworkDevice{
    //attributes
    protected string ipAddress;
    protected string deviceName;

    //constructor
    public NetworkDevice(string ipAddress, string deviceName){
        this.ipAddress=ipAddress;
        this.deviceName=deviceName;
    }

    //abstract method
    public abstract void Connect();

    //virtual method
    public virtual void DisplayDeviceInfo(){
        Console.WriteLine($"Device Name: {deviceName}, IP Address: {ipAddress}");
    }
}