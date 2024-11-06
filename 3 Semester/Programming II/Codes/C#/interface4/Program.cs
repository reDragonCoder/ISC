// Author: reDragonCoder

using System;

// We define the IPrintable interface
interface IPrintable{
    void Print(string document);
}

// We define the IScannable interface
interface IScannable{
    void Scan(string document);
}

// Base class for devices
class Device{
    public string Model {get; set;}

    public Device(string model){
        Model=model;
    }

    public void DisplayModel(){
        Console.WriteLine("Device model: "+Model);
    }
}

// MultifunctionDevice class that inherits from Device and 
// implements the IPrintable and IScannable interfaces
class MultifunctionDevice : Device, IPrintable, IScannable{
    public MultifunctionDevice(string model):base(model){}

    // IPrintable method implementation
    public void Print(string document){
        Console.WriteLine("Printing document: "+document);
    }

    // Implementation of the IScannable method
    public void Scan(string document){
        Console.WriteLine("Scanning document: "+document);
    }
}

// Main program
class Program{
    static void Main(){
        MultifunctionDevice device=new MultifunctionDevice("X1000 Multifunction");
        device.DisplayModel();
        device.Print("Annual Report.pdf");
        device.Scan("Legal_Contract.pdf");
    }
}

