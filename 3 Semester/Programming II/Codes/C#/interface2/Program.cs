// Author: reDragonCoder

using System;

interface IStorageDevice{
    void SaveData(string data);
}

class BasicStorage:IStorageDevice{
    public virtual void SaveData(string data){
        Console.WriteLine("Saving data to basic storage: "+data);
    }
}

// 'PremiumStorage' can now overwrite 'SaveData'
class PremiumStorage:BasicStorage{
    public override void SaveData(string data){
        Console.WriteLine("Saving data to premium storage with encryption: "+data);
    }
}

// Main program
class Program{
    static void Main(){
        IStorageDevice device=new PremiumStorage();
        device.SaveData("File2.txt"); // Shows: "Saving data to premium storage with encryption: File2.txt"
    }
}
