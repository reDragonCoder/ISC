// Author: reDragonCoder

using System;

class Program{
    static void Main(string[] args){
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("reDragonCoder\n");
        Console.ResetColor();

        SmartPhone phone=new SmartPhone("192.168.1.2", "MyPhone", "Wi-Fi 6", "Android 12");
        Router router=new Router("192.168.1.1", "HomeRouter", 4);

        //Connecting devices
        phone.Connect();
        router.Connect();

        //Showing device info1
        Console.WriteLine("\nDevice Info:");
        phone.DisplayDeviceInfo();
        router.DisplayDeviceInfo();

        //Modify the protected attributes from derivate classes
        Console.WriteLine("\nModifying Attributes:");
        phone.ChangeDeviceName("SuperPhone");
        phone.ChangeWirelessProtocol("Wi-Fi 7");

        //Show again the info after the changes
        Console.WriteLine("\nUpdate Device Info:");
        phone.DisplayDeviceInfo();

        //Testing
        SmartPhone phone1=new SmartPhone("172.16.254.4", "Cesar's iPhone", "Wi-Fi 8", "iOS 17");
        Router router1=new Router("175.16.238.3", "IZZI-Router", 5);

        Console.WriteLine();
        phone1.Connect();
        router1.Connect();

        Console.WriteLine("\nDevice Info:");
        phone1.DisplayDeviceInfo();
        router1.DisplayDeviceInfo();
    }
}