// Author: reDragonCoder

using System;

class Program{
    static void Main(){
        // object creation
        Device myComputer=new Computer("Desktop", "Windows 10");
        Device myLaptop=new Laptop("My Laptop", "Linux", 80);
        Device myGamingLaptop=new GamingLaptop("Gaming Beast", "Windows 10", 95, "RTX 3080");

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Polymorphism with inheritance hierarchy\n");
        Console.ResetColor();
        List<Device> devices=new List<Device> {myComputer, myLaptop, myGamingLaptop};
        foreach(var device in devices){
            device.TurnOn();
            device.TurnOff();
        }
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Polymorphism with interfaces\n");
        Console.ResetColor();
        if(myComputer is ITestable testableDevice){
            testableDevice.Test();
        }
        if(myLaptop is IStorable storableDevice){
            storableDevice.Store();
        }
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Downcasting using interfaces\n");
        Console.ResetColor();
        if(myLaptop is IStorable storableInterface){
            storableInterface.Store();
        }
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Downcasting with inheritance hierarchy\n");
        Console.ResetColor();
        if(myLaptop is Laptop){
            Laptop mySpecificLaptop=(Laptop)myLaptop;
            mySpecificLaptop.ChargeBattery();
        }
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Upcasting with inheritance hierarchy\n");
        Console.ResetColor();
        Computer myUpcastedLaptop=(Computer)myLaptop;
        myUpcastedLaptop.Test();
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Upcasting with interfaces\n");
        Console.ResetColor();
        ITestable upcastedTestableDevice=(ITestable)myGamingLaptop;
        upcastedTestableDevice.Test();
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Identify hidden object type by polymorphism with classes\n");
        Console.ResetColor();
        Console.WriteLine($"Object type in 'myComputer': {myComputer.GetType()}");
        Console.WriteLine($"Object type in 'myGamingLaptop': {myGamingLaptop.GetType()}");
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Identify hidden object type by polymorphism with interfaces\n");
        Console.ResetColor();
        IdentifyInterfaceType(myComputer);
        IdentifyInterfaceType(myLaptop);
        IdentifyInterfaceType(myGamingLaptop);
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Polymorphic interface type array\n");
        Console.ResetColor();
        ITestable[] testDevices=new ITestable[] {(ITestable)myComputer, (ITestable)myLaptop, (ITestable)myGamingLaptop};
        PrintTestableDevices(testDevices);
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Polymorphic array of class type\n");
        Console.ResetColor();
        Device[] deviceArray=new Device[] {myComputer, myLaptop, myGamingLaptop};
        PrintDevices(deviceArray);
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("\n---------------------------------------------------------------------\n");
        Console.ResetColor();

        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("Own methods\n");
        Console.ResetColor();
        ((GamingLaptop)myGamingLaptop).PlayGame();
        ((Laptop)myLaptop).UpgradeOS();
    }

    // method to print using foreach
    static void PrintDevices(Device[] devices){
        foreach(var device in devices){
            device.TurnOn();
        }
    }

    static void PrintTestableDevices(ITestable[] devices){
        for(int i=0; i<devices.Length; i++){
            devices[i].Test();
        }
    }

    static void IdentifyInterfaceType(Device device){
        Console.WriteLine($"Identifying interfaces for device of type {device.GetType()}...");

        if(device is ITestable){
            Console.WriteLine($"The device {device.GetType()} implements the ITestable interface.");
            if(device is ITestable testable){
                testable.Test();
            }
        }else{
            Console.WriteLine($"The device {device.GetType()} does NOT implement ITestable.");
        }

        if(device is IStorable){
            Console.WriteLine($"The device {device.GetType()} implements the IStorable interface.");
            if(device is IStorable storable){
                storable.Store();
            }
        }else{
            Console.WriteLine($"The device {device.GetType()} does NOT implement IStorable.");
        }
    }
}