// Author: reDragonCoder

using System;

// We define the interface
interface IStorageDevice{
    void SaveData(string data);
}

// Implementation of the interface in a class without 'virtual'
class BasicStorage:IStorageDevice{
    public void SaveData(string data){
        Console.WriteLine("Saving data to basic storage: "+data);
    }
}

// Derived class that cannot override 'SaveData' because it is not 'virtual'
class PremiumStorage:BasicStorage{
    // Can't override 'SaveData' in this class
}

// Main program
class Program{
    static void Main(){
        //IStorageDevice dev=new IStorageDevice(); //NO!!!
        IStorageDevice device=new BasicStorage();
        device.SaveData("File1.txt");
    }
}
